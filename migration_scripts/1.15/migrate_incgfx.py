# To migrate all files:
# git ls-files | grep 'src/.*\.[ch]$' | xargs grep -l INCBIN | xargs python3 migration_scripts/1.15/migrate_incgfx.py

import os.path
import re
import sys

# Set to 'True' and the files will be printed to stdout rather than
# updated in place.
DRY_RUN = False

def expand_variables(definition, variables):
    return re.sub(r'\$[({](\w+)[)}]', lambda m: variables.get(m.group(1), m.group(0)), definition)

def exclude_automatic_variables(arguments):
    return re.sub(r'(^| )\$[^\w-]+', '', arguments);

# Very incomplete parsing of 'Makefile' syntax.
def parse_graphics_rules():
    paths = ["Makefile"]

    targets = {}
    variables = {}

    while paths:
        path = paths.pop()

        target = None
        target_ext = None
        source = None

        with open(path, "r") as f:
            for line in f:
                # Makefile include
                if m := re.match(r'^include\s+(.+?)\s*$', line):
                    # FIXME: Submakefiles should be processed immediately?
                    paths.append(m.group(1))
                # Variable definition (= or := or ?=)
                elif m := re.match(r'^(\w+)\s*(=|:=|\?=)\s*(.*?)\s*$', line):
                    name = m.group(1)
                    definition = expand_variables(m.group(3), variables)
                    variables[name] = definition
                # Multi-line rule.
                elif m := re.match(r'^([^:\s]+)\s*:\s*[^:\s]+\s*\\$', line):
                    # FIXME: Some of these rules could potentially be
                    # converted if we extend 'INCGFX'? e.g. if it could
                    # take multiple files to concatenate.
                    target = expand_variables(m.group(1), variables)
                    targets[target] = None
                # Generic pattern rule (%.tgt : %.src ; $(GFX) $< $@ ...)
                elif m := re.match(r'^(%[^:\s]+)\s*:\s*(%[^:\s]*)\s*;\s*\$\(GFX\)\s*(.*)$', line):
                    target = expand_variables(m.group(1), variables)
                    source = expand_variables(m.group(2), variables)
                    arguments = expand_variables(m.group(3), variables)
                    arguments = exclude_automatic_variables(arguments)
                    targets.setdefault(target, []).append((source, arguments))
                    target = source = None
                # Generic pattern rule (%.tgt : %.src ; $(SMOL) $< $@ ...)
                elif m := re.match(r'^(%[^:\s]+)\s*:\s*(%[^:\s]*)\s*;\s*\$\(SMOL\)\s*(.*)$', line):
                    target = expand_variables(m.group(1), variables)
                    source = expand_variables(m.group(2), variables)
                    targets.setdefault(target, []).append((source, []))
                    target = source = None
                # Specific pattern rule (foo.tgt : %.tgt : %.src)
                elif m := re.match(r'^([^:\s]+)\s*:\s*%([^:\s]+)\s*:\s*%(\S+)\s*$', line):
                    target = expand_variables(m.group(1), variables)
                    target_ext = m.group(2)
                    source_ext = m.group(3)
                    source = target.replace(target_ext, source_ext)
                # Specific rule (foo.tgt : bar.src)
                elif m := re.match(r'^([^:\s]+)\s*:\s*([^:\s]+)\s*$', line):
                    target = expand_variables(m.group(1), variables)
                    target_ext = '.' + '.'.join(target.split('.')[1:])
                    source = expand_variables(m.group(2), variables)
                # Recipe ($(GFX) ...)
                elif m := re.match(r'^\t\$\(GFX\)\s+(.*)$', line):
                    if target:
                        arguments = expand_variables(m.group(1), variables)
                        arguments = exclude_automatic_variables(arguments)
                        targets[target] = (target_ext, source, arguments)
                        target = source = None

    return targets

# *Very* incomplete implementation of pattern rules.
def lookup_rule(target, targets):
    # Specific rule.
    if target in targets:
        return targets[target]

    target, _, target_ext_extra = target.rpartition('.')
    generic_target = f'%.{target_ext_extra}'

    # No generic rule.
    # FIXME: There could be a generic rule that consumes multiple extensions.
    if generic_target not in targets:
        return None

    # Check for matching generic rule.
    for (source_pattern, arguments) in targets[generic_target]:
        source = source_pattern.replace('%', target)
        # Trivial generic rule...
        if not arguments:
            # ... that enables another rule.
            if rule := lookup_rule(source, targets):
                (target_ext, source, arguments) = rule
                return (target_ext + '.' + target_ext_extra, source, arguments)
            # ... the enabled rule is manually-specified.
            elif source in targets and targets[source] is None:
                return ('.' + target_ext_extra, source, "")

        # Satisfiable generic rule.
        # NOTE: This comes after the previous 'if' because otherwise
        # migrating a dirty repository would find asset artifacts and
        # do a muddled migration.
        if os.path.exists(source):
            return ('.' + target_ext_extra, source, arguments)

    # No matching generic rule.
    return None

def try_convert_incbin(size, c_source, pos, targets):
    try:
        while c_source[pos].isspace():
            pos += 1

        if c_source[pos] != '(':
            return None
        pos += 1

        while c_source[pos].isspace():
            pos += 1

        if c_source[pos] != '"':
            return None
        pos += 1

        target_start = pos
        while c_source[pos] != '"':
            pos += 1
        target_end = pos
        pos += 1

        while c_source[pos].isspace():
            pos += 1

        if c_source[pos] != ')':
            return None
        pos += 1

    except IndexError:
        return None

    target = c_source[target_start:target_end]
    if rule := lookup_rule(target, targets):
        (target_ext, source, arguments) = rule
        if arguments:
            return f'INCGFX_{size}("{source}", "{target_ext}", "{arguments}")' + c_source[pos:]
        else:
            return f'INCGFX_{size}("{source}", "{target_ext}")' + c_source[pos:]
    else:
        return None

def convert_incbins(path, targets):
    with open(path, "r") as f:
        c_source = f.read()

    # WARNING: This will catch 'INCBIN's in strings, comments, etc.
    pattern = re.compile(r'INCBIN_(U8|U16|U32|COMP)')
    pos = 0
    while True:
        m = pattern.search(c_source, pos=pos)
        if not m:
            break
        pos = m.start()
        rest = try_convert_incbin(m.group(1), c_source[pos:], m.end() - pos, targets)
        if rest:
            c_source = c_source[:pos] + rest
        else:
            pos = m.end()

    if DRY_RUN:
        sys.stdout.write(c_source)
    else:
        with open(path, "w") as f:
            f.write(c_source)

if __name__ == '__main__':
    targets = parse_graphics_rules()

    for path in sys.argv[1:]:
        convert_incbins(path, targets)
