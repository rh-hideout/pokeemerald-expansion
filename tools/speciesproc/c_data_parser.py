import re

def append_lists(values):
    element = values[0]
    lis =  values[1]
    if "key" in lis:
        lis = [{lis["key"]: lis["value"]}]
    if "key" in element:
        lis[element["key"]] = element["value"]
        return lis
    else:
        lis.append(element)
        return lis

def singleton(values):
    return values[0]

def add_field(values):
    if (values[2] == None or values[2] == []):
        if values[0] == None:
            return {}
        return {values[0]: values[1]}
    else:
        values[2][values[0]] = values[1]
        return values[2]

def add_element(values):
    if (len(values) < 2 or values[1] == None):
        if values[0] == None:
            return []
        return [values[0]]
    else:
        values[1].append(values[0])
        return values[1]

def ternary_check(values):
    if values[0]:
        return values[1]
    else:
        return values[2]

def equality_check(values):
    if values[1] == "==" and values[0] == values[2]:
        return 1
    elif values[1] == "!=" and values[0] != values[2]:
        return 1
    else:
        return 0

def order_check(values):
    if values[1] == ">=" and values[0] >= values[2]:
        return 1
    elif values[1] == "<=" and values[0] <= values[2]:
        return 1
    elif values[1] == "<" and values[0] < values[2]:
        return 1
    elif values[1] == ">" and values[0] > values[2]:
        return 1
    else:
        return 0

def word_or_digit(values):
    s = values[0]
    if s[0] == "-":
        if s[1:].isdigit():
            return int(s)
    elif s.isdigit():
        return int(s)
    return s

def bit_shift(values):
    if values[1] == ">>":
        return (values[0] >> values[2])
    else:
        return (values[0] << values[2])

def add_values(values):
    if values[1] == "+":
        return (values[0] + values[2])
    else:
        return (values[0] - values[2])

def multiply(values):
    if values[1] == "*":
        return (values[0] * values[2])
    elif values[1] == "/":
        return (values[0] // values[2])
    else:
        return (values[0] % values[2])

def read_float(values):
    return float(values[0])

def join_strings(values):
    if values[1] == None:
        return values[0]
    return values[0] + values[1]

def andor_check(values):
    if (values[1] == "||" and (values[0] or values[2])):
        return True
    if values[1] == "&&" and values[0] and values[2]:
        return True
    return False

def bitwise_op(values):
    if values[1] == "^":
        return values[0] ^ values[2]
    if values[1] == "|":
        return values[0] | values[2]
    if values[1] == "&":
        return values[0] & values[2]

def logical_not(values):
    if values[0]:
        return False
    return True

def logical_not(values):
    if values[0]:
        return False
    return True

def bitwise_not(values):
    return ~values[0]

grammar = {
    "value": [
        {"func": bitwise_not, "num_steps": 2, "steps": [("match", r"\s*\~"), ("type", "value"), ("end",0)]},
        {"func": logical_not, "num_steps": 2, "steps": [("match", r"\s*\!"), ("type", "value"), ("end",0)]},
        {"func": singleton, "num_steps": 3, "steps": [("match", r"\s*\("), ("type", "ternary"), ("match", r"\s*\)"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "atom"), ("end",0)]},
    ],

    "ternary": [
        {"func": ternary_check, "num_steps": 5, "steps": [("type", "object"), ("match", r"\s*\?"), ("type", "ternary"), ("match", r"\s*\:"), ("type", "ternary"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "object"), ("end",0)]}
    ],
    "prio1": [
        {"func": andor_check, "num_steps": 3, "steps": [("type", "prio2"), ("match", r"\s*(\|\|)"), ("type", "prio1"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio2"), ("end",0)]},
    ],
    "prio2": [
        {"func": andor_check, "num_steps": 3, "steps": [("type", "prio3"), ("match", r"\s*(&&)"), ("type", "prio2"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio3"), ("end",0)]},
    ],
    "prio3": [
        {"func": bitwise_op, "num_steps": 3, "steps": [("type", "prio4"), ("match", r"\s*(\|[^\|])"), ("type", "prio3"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio4"), ("end",0)]},
    ],
    "prio4": [
        {"func": bitwise_op, "num_steps": 3, "steps": [("type", "prio5"), ("match", r"\s*(\^)"), ("type", "prio4"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio5"), ("end",0)]},
    ],
    "prio5": [
        {"func": bitwise_op, "num_steps": 3, "steps": [("type", "prio6"), ("match", r"\s*(&[^\&])"), ("type", "prio5"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio6"), ("end",0)]},
    ],
    "prio6": [
        {"func": equality_check, "num_steps": 3, "steps": [("type", "prio7"), ("match", r"\s*([!=]=)"), ("type", "prio6"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio7"), ("end",0)]},
    ],
    "prio7": [
        {"func": order_check, "num_steps": 3, "steps": [("type", "prio8"), ("match", r"\s*([><]=?)"), ("type", "prio7"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio8"), ("end",0)]},
    ],
    "prio8": [
        {"func": bit_shift, "num_steps": 3, "steps": [("type", "prio9"), ("match", r"\s*(<<|>>)"), ("type", "prio8"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio9"), ("end",0)]},
    ],
    "prio9": [
        {"func": add_values, "num_steps": 3, "steps": [("type", "prio10"), ("match", r"\s*([+\-])"), ("type", "prio9"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio10"), ("end",0)]},
    ],
    "prio10": [
        {"func": multiply, "num_steps": 3, "steps": [("type", "value"), ("match", r"\s*([*/%])"), ("type", "prio6"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "value"), ("end",0)]},
    ],
    "atom": [
        {"func": read_float, "num_steps": 1, "steps": [("match", r"\s*f\(([\d\.]+)\)"), ("end",0)]},
        {"func": word_or_digit, "num_steps": 1, "steps": [("match", r"\s*([\-\w]+)"), ("end",0)]},
        {"func": join_strings, "num_steps": 2, "steps": [("match", r"\s*\"([^\"]+)\""), ("type", "next_string"), ("end",0)]},
        {"num_steps": 0}
    ],
    "object": [
        {"func": singleton, "num_steps": 3, "steps": [("match", r"\s*{"), ("type", "list"), ("match", r"\s*}"), ("end",0)]},
        {"func": singleton, "num_steps": 3, "steps": [("match", r"\s*\["), ("type", "list"), ("match", r"\s*\]"), ("end",0)]},
        {"func": singleton, "num_steps": 1, "steps": [("type", "prio1"), ("end",0)]},
    ],
    "list" : [
        {"func": add_field, "num_steps": 5, "steps": [("match", r"\s*\."), ("type", "ternary"), ("match", r"\s*="), ("type", "ternary"), ("type", "next"), ("end",0)]},
        {"func": add_field, "num_steps": 5, "steps": [("match", r"\s*\["), ("type", "ternary"), ("match", r"\]\s*="), ("type", "ternary"), ("type", "next"), ("end",0)]},
        {"func": add_element, "num_steps": 2, "steps": [("type", "ternary"), ("type", "next"), ("end",0)]}
    ],
    "next" : [
        {"func": singleton, "num_steps": 2, "steps": [("match", r"\s*,"), ("type", "list"), ("end",0)]},
        {"num_steps": 0}
    ],
    "next_string" : [
        {"func": join_strings, "num_steps": 2, "steps": [("match", r"\s*\"([^\"]+)\""), ("type", "next_string"), ("end",0)]},
        {"num_steps": 0}
    ]
}



def generic_parse(type, string):
    step = 0
    mode = 0
    values = []

    while True:
        if mode >= len(grammar[type]):
            print("no valid mode")
            exit(1)
        x = grammar[type][mode]
        if  grammar[type][mode]["num_steps"] == 0:
            return (None, string)
        if step > grammar[type][mode]["num_steps"]:
            print("parsing error")
            exit(1)
        x = x["steps"][step]
        if x[0] == "type":
            parsed_struct = generic_parse(x[1], string)
            values.append(parsed_struct[0])
            string = parsed_struct[1]
        elif x[0] == "match":
            match = re.match(x[1], string)
            if not match:
                #print(grammar[type][mode], step)
                mode += 1
                continue
            #print(len(match.groups()))
            if len(match.groups()) > 0:
                values.append(match.group(1))
            string = string[match.end():]
        elif x[0] == "end":
            break
        step += 1

    #print(grammar[type][mode], step)
    #print("values", values)
    result = grammar[type][mode]["func"](values)
    #print(result)
    #print(string)
    return (result, string)

def file_parse(string):
    file_data = {}
    while (string != ""):
        match = re.search(r"(\w+)(\[\w*\])?\s*=", string)
        if not match:
            break
        var = match.group(1)
        string = string[match.end():]
        result = generic_parse("ternary", string)
        data = result[0]
        string = result[1]
        print(var)
        #print(data)
        if data == None:
            break
        file_data[var] = data
    return file_data

