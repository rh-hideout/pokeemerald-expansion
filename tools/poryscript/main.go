package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"os"
	"strings"

	"github.com/huderlem/poryscript/emitter"
	"github.com/huderlem/poryscript/lexer"
	"github.com/huderlem/poryscript/parser"
)

const version = "3.5.2"

type mapOption map[string]string

func (opt mapOption) String() string {
	return ""
}

func (opt mapOption) Set(value string) error {
	result := strings.SplitN(value, "=", 2)
	if len(result) != 2 {
		return fmt.Errorf("expected key-value option to be separate by '=', but got '%s' instead", value)
	}
	opt[result[0]] = result[1]
	return nil
}

type options struct {
	inputFilepath         string
	outputFilepath        string
	commandConfigFilepath string
	fontConfigFilepath    string
	defaultFontID         string
	maxLineLength         int
	optimize              bool
	enableLineMarkers     bool
	compileSwitches       map[string]string
}

func parseOptions() options {
	helpPtr := flag.Bool("h", false, "show poryscript help information")
	versionPtr := flag.Bool("v", false, "show version of poryscript")
	inputPtr := flag.String("i", "", "input poryscript file (leave empty to read from standard input)")
	outputPtr := flag.String("o", "", "output script file (leave empty to write to standard output)")
	commandConfigPtr := flag.String("cc", "command_config.json", "command config JSON file")
	fontsPtr := flag.String("fc", "font_config.json", "font config JSON file")
	fontIDPtr := flag.String("f", "", "set default font id (leave empty to use default defined in font config file)")
	lengthPtr := flag.Int("l", 0, "set default line length in pixels for formatted text (uses font config file for default)")
	optimizePtr := flag.Bool("optimize", true, "optimize compiled script size (To disable, use '-optimize=false')")
	enableLineMarkersPtr := flag.Bool("lm", true, "include line markers in output (enables more helpful error messages when compiling the ROM). (To disable, use '-lm=false')")
	compileSwitches := make(mapOption)
	flag.Var(compileSwitches, "s", "set a compile-time switch. Multiple -s options can be set. Example: -s VERSION=RUBY -s LANGUAGE=GERMAN")
	flag.Parse()

	if *helpPtr {
		flag.Usage()
		os.Exit(0)
	}

	if *versionPtr {
		fmt.Printf("%s\n", version)
		os.Exit(0)
	}

	return options{
		inputFilepath:         *inputPtr,
		outputFilepath:        *outputPtr,
		commandConfigFilepath: *commandConfigPtr,
		fontConfigFilepath:    *fontsPtr,
		defaultFontID:         *fontIDPtr,
		maxLineLength:         *lengthPtr,
		optimize:              *optimizePtr,
		enableLineMarkers:     *enableLineMarkersPtr,
		compileSwitches:       compileSwitches,
	}
}

func getInput(filepath string) (string, error) {
	var bytes []byte
	var err error
	if filepath == "" {
		bytes, err = ioutil.ReadAll(os.Stdin)
	} else {
		bytes, err = ioutil.ReadFile(filepath)
	}

	return string(bytes), err
}

func writeOutput(output string, filepath string) error {
	if filepath == "" {
		fmt.Print(output)
	} else {
		f, err := os.Create(filepath)
		if err != nil {
			return err
		}

		_, err = io.WriteString(f, output)
		if err != nil {
			return err
		}
	}
	return nil
}

func readCommandConfig(filepath string) parser.CommandConfig {
	var config parser.CommandConfig
	if len(filepath) == 0 {
		return config
	}
	bytes, err := ioutil.ReadFile(filepath)
	if err != nil {
		log.Fatalf("PORYSCRIPT ERROR: Failed to read command config file: %s\n", err.Error())
	}

	if err := json.Unmarshal(bytes, &config); err != nil {
		log.Fatalf("PORYSCRIPT ERROR: Failed to load command config file: %s\n", err.Error())
	}

	return config
}

func main() {
	log.SetFlags(0)
	options := parseOptions()
	input, err := getInput(options.inputFilepath)
	if err != nil {
		log.Fatalf("PORYSCRIPT ERROR: %s\n", err.Error())
	}

	commandConfig := readCommandConfig(options.commandConfigFilepath)
	parser := parser.New(lexer.New(input), commandConfig, options.fontConfigFilepath, options.defaultFontID, options.maxLineLength, options.compileSwitches)
	program, err := parser.ParseProgram()
	if err != nil {
		log.Fatalf("PORYSCRIPT ERROR: %s\n", err.Error())
	}

	emitter := emitter.New(program, options.optimize, options.enableLineMarkers, options.inputFilepath)
	result, err := emitter.Emit()
	if err != nil {
		log.Fatalf("PORYSCRIPT ERROR: %s\n", err.Error())
	}
	err = writeOutput(result, options.outputFilepath)
	if err != nil {
		log.Fatalf("PORYSCRIPT ERROR: %s\n", err.Error())
	}
}
