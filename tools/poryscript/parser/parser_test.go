package parser

import (
	"errors"
	"fmt"
	"regexp"
	"testing"

	"github.com/huderlem/poryscript/token"

	"github.com/huderlem/poryscript/ast"
	"github.com/huderlem/poryscript/lexer"
)

type commandArgs struct {
	name string
	args []string
}

func TestScriptStatements(t *testing.T) {
	input := `
script MyScript {
	lock
	bufferitemname("Bar", 0, VAR_BUG_CONTEST_PRIZE, ascii"Foo", format(braille"Baz"))
	# this is a comment
	# another comment
	message() waitstate
	somecommand(foo,
		4+   6,,(CONST_FOO) +  1)
}

script MyScript2 {}
script MyScript3 {
		}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "../font_config.json", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}
	if len(program.TopLevelStatements) != 3 {
		t.Fatalf("program.TopLevelStatements does not contain 3 statements. got=%d", len(program.TopLevelStatements))
	}

	tests := []struct {
		expectedName     string
		expectedCommands []commandArgs
	}{
		{"MyScript", []commandArgs{
			{"lock", []string{}},
			{"bufferitemname", []string{"MyScript_Text_0", "0", "VAR_BUG_CONTEST_PRIZE", "MyScript_Text_1", "MyScript_Text_2"}},
			{"message", []string{}},
			{"waitstate", []string{}},
			{"somecommand", []string{"foo", "4 + 6", "", "( CONST_FOO ) + 1"}},
		}},
		{"MyScript2", []commandArgs{}},
		{"MyScript3", []commandArgs{}},
	}

	for i, tt := range tests {
		stmt := program.TopLevelStatements[i]
		if !testScriptStatement(t, stmt, tt.expectedName, tt.expectedCommands) {
			return
		}
	}
}

func testScriptStatement(t *testing.T, s ast.Statement, expectedName string, expectedCommandArgs []commandArgs) bool {
	if s.TokenLiteral() != "script" {
		t.Errorf("s.TokenLiteral not 'script'. got=%q", s.TokenLiteral())
		return false
	}

	scriptStmt, ok := s.(*ast.ScriptStatement)
	if !ok {
		t.Errorf("s not %T. got=%T", &ast.ScriptStatement{}, s)
		return false
	}

	if scriptStmt.Name.Value != expectedName {
		t.Errorf("scriptStmt.Name.Value not '%s'. got=%s", expectedName, scriptStmt.Name.Value)
		return false
	}

	if scriptStmt.Name.TokenLiteral() != expectedName {
		t.Errorf("scriptStmt.Name not '%s'. got=%s", expectedName, scriptStmt.Name.TokenLiteral())
		return false
	}

	if scriptStmt.Body == nil {
		t.Errorf("scriptStmt.Body was nil")
		return false
	}

	if len(scriptStmt.Body.Statements) != len(expectedCommandArgs) {
		t.Errorf("scriptStmt.Body statements size not %d. got=%d", len(expectedCommandArgs), len(scriptStmt.Body.Statements))
		return false
	}

	for i, stmt := range scriptStmt.Body.Statements {
		expectedCommand := expectedCommandArgs[i]
		if stmt.TokenLiteral() != expectedCommand.name {
			t.Errorf("scriptStmt.Body statement %d not '%s'. got=%s", i, expectedCommand, stmt.TokenLiteral())
			return false
		}

		commandStmt, ok := stmt.(*ast.CommandStatement)
		if !ok {
			t.Errorf("s not %T. got=%T", &ast.CommandStatement{}, s)
			return false
		}

		if len(commandStmt.Args) != len(expectedCommand.args) {
			t.Errorf("commandStmt.Args size not %d. got=%d", len(expectedCommand.args), len(commandStmt.Args))
			return false
		}

		for j, arg := range commandStmt.Args {
			if arg != expectedCommand.args[j] {
				t.Errorf("Command statement %d of body statement %d not '%s'. got='%s'", j, i, expectedCommand.args[j], arg)
				return false
			}
		}
	}

	return true
}

func TestPoryswitchStatements(t *testing.T) {
	input := `
script MyScript {
	lock
	poryswitch(GAME_VERSION) {
		RUBY: foo
		SAPPHIRE {
			bar
			poryswitch(LANG) {
				DE {
					de_command
					de_command2
				}
				EN: en_command
				_: fallback
			}
			baz
		}
	}
	release
}

text MyText {
	poryswitch(LANG) {
		DE: ascii"Das ist MAY's Haus."
		_: format("formatted")
		EN {
			"Two\n"
			"Lines"
		}
	}
}

movement MyMovement {
	walk_up
	poryswitch(GAME_VERSION) {
		_: walk_default
		RUBY: walk_ruby * 2
		SAPPHIRE {
			face_up
			poryswitch(LANG) {
				DE: face_de
				_ { face_default * 2  }
			}
			face_down
		}
	}
	walk_down
}

mart MyMart {
	ITEM_FOO
	poryswitch(GAME_VERSION) {
		_: ITEM_FALLBACK
		RUBY: ITEM_RUBY
		SAPPHIRE {
			ITEM_SAPPHIRE
			poryswitch(LANG) {
				DE: ITEM_DE
				_ { ITEM_FALLBACK_LANG }
			}
			ITEM_SAP_END
		}
	}
	ITEM_FINAL
}
`
	scriptTests := []struct {
		switches map[string]string
		commands []string
	}{
		{map[string]string{"GAME_VERSION": "RUBY", "LANG": "FR"}, []string{"lock", "foo", "release"}},
		{map[string]string{"GAME_VERSION": "SAPPHIRE", "LANG": "DE"}, []string{"lock", "bar", "de_command", "de_command2", "baz", "release"}},
		{map[string]string{"GAME_VERSION": "SAPPHIRE", "LANG": "BLAH"}, []string{"lock", "bar", "fallback", "baz", "release"}},
	}

	for _, tt := range scriptTests {
		l := lexer.New(input)
		p := New(l, CommandConfig{}, "../font_config.json", "", 0, tt.switches)
		program, err := p.ParseProgram()
		if err != nil {
			t.Fatalf(err.Error())
		}
		stmt := program.TopLevelStatements[0].(*ast.ScriptStatement)
		if len(stmt.Body.Statements) != len(tt.commands) {
			t.Fatalf("Incorrect number of statements. Expected %d, got %d", len(tt.commands), len(stmt.Body.Statements))
		}
		for i, expectedCommand := range tt.commands {
			command := stmt.Body.Statements[i].TokenLiteral()
			if expectedCommand != command {
				t.Fatalf("Incorrect statement %d. Expected %s, got %s", i, expectedCommand, command)
			}
		}
	}

	textTests := []struct {
		switches map[string]string
		text     string
	}{
		{map[string]string{"GAME_VERSION": "RUBY", "LANG": "DE"}, "Das ist MAY's Haus.\\0"},
		{map[string]string{"GAME_VERSION": "SAPPHIRE", "LANG": "EN"}, "Two\\n\nLines$"},
		{map[string]string{"GAME_VERSION": "SAPPHIRE", "LANG": "BLAH"}, "formatted$"},
	}

	for i, tt := range textTests {
		l := lexer.New(input)
		p := New(l, CommandConfig{}, "../font_config.json", "", 0, tt.switches)
		program, err := p.ParseProgram()
		if err != nil {
			t.Fatalf(err.Error())
		}
		stmt := program.TopLevelStatements[1].(*ast.TextStatement)
		text := stmt.Value
		if tt.text != text {
			t.Fatalf("Incorrect text %d. Expected %s, got %s", i, tt.text, text)
		}
	}

	movementTests := []struct {
		switches map[string]string
		commands []string
	}{
		{map[string]string{"GAME_VERSION": "RUBY", "LANG": "DE"}, []string{"walk_up", "walk_ruby", "walk_ruby", "walk_down"}},
		{map[string]string{"GAME_VERSION": "SAPPHIRE", "LANG": "DE"}, []string{"walk_up", "face_up", "face_de", "face_down", "walk_down"}},
		{map[string]string{"GAME_VERSION": "SAPPHIRE", "LANG": "EN"}, []string{"walk_up", "face_up", "face_default", "face_default", "face_down", "walk_down"}},
	}

	for _, tt := range movementTests {
		l := lexer.New(input)
		p := New(l, CommandConfig{}, "../font_config.json", "", 0, tt.switches)
		program, err := p.ParseProgram()
		if err != nil {
			t.Fatalf(err.Error())
		}
		stmt := program.TopLevelStatements[2].(*ast.MovementStatement)
		if len(stmt.MovementCommands) != len(tt.commands) {
			t.Fatalf("Incorrect number of movement commands. Expected %d, got %d", len(tt.commands), len(stmt.MovementCommands))
		}
		for i, expectedCommand := range tt.commands {
			command := stmt.MovementCommands[i]
			if expectedCommand != command.Literal {
				t.Fatalf("Incorrect movement command %d. Expected %s, got %s", i, expectedCommand, command.Literal)
			}
		}
	}

	martTests := []struct {
		switches map[string]string
		items    []string
	}{
		{map[string]string{"GAME_VERSION": "RUBY", "LANG": "DE"}, []string{"ITEM_FOO", "ITEM_RUBY", "ITEM_FINAL"}},
		{map[string]string{"GAME_VERSION": "SAPPHIRE", "LANG": "DE"}, []string{"ITEM_FOO", "ITEM_SAPPHIRE", "ITEM_DE", "ITEM_SAP_END", "ITEM_FINAL"}},
		{map[string]string{"GAME_VERSION": "SAPPHIRE", "LANG": "EN"}, []string{"ITEM_FOO", "ITEM_SAPPHIRE", "ITEM_FALLBACK_LANG", "ITEM_SAP_END", "ITEM_FINAL"}},
	}

	for _, tt := range martTests {
		l := lexer.New(input)
		p := New(l, CommandConfig{}, "../font_config.json", "", 0, tt.switches)
		program, err := p.ParseProgram()
		if err != nil {
			t.Fatalf(err.Error())
		}
		stmt := program.TopLevelStatements[3].(*ast.MartStatement)
		if len(stmt.Items) != len(tt.items) {
			t.Fatalf("Incorrect number of mart items. Expected %d, got %d", len(tt.items), len(stmt.Items))
		}
		for i, expectedItem := range tt.items {
			item := stmt.Items[i]
			if expectedItem != item {
				t.Fatalf("Incorrect mart item %d. Expected %s, got %s", i, expectedItem, item)
			}
		}
	}
}

func TestRawStatements(t *testing.T) {
	input := `
raw ` + "`" + `
	step_up
	step_end
` + "`" + `

raw ` + "`" + `
	step_down
` + "`"
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}
	if len(program.TopLevelStatements) != 2 {
		t.Fatalf("program.TopLevelStatements does not contain 2 statements. got=%d", len(program.TopLevelStatements))
	}

	tests := []struct {
		expectedValue string
	}{
		{`
	step_up
	step_end`},
		{`
	step_down`},
	}

	for i, tt := range tests {
		stmt := program.TopLevelStatements[i]
		if !testRawStatement(t, stmt, tt.expectedValue) {
			return
		}
	}
}

func testRawStatement(t *testing.T, s ast.Statement, expectedValue string) bool {
	if s.TokenLiteral() != "raw" {
		t.Errorf("s.TokenLiteral not 'raw'. got=%q", s.TokenLiteral())
		return false
	}

	rawStmt, ok := s.(*ast.RawStatement)
	if !ok {
		t.Errorf("s not %T. got=%T", &ast.RawStatement{}, s)
		return false
	}

	if rawStmt.Value != expectedValue {
		t.Errorf("rawStmt.Value not '%s'. got=%s", expectedValue, rawStmt.Value)
		return false
	}

	return true
}

func TestIfStatements(t *testing.T) {
	input := `
script Test {
	if (var(VAR_1) == 1) {
		if (var(VAR_7) != value(0x4000)) {
			message()
		}
		message()
	} elif (var(VAR_2) != 2) {
		blah()
	} elif (var(VAR_3) < 3) {
		blah()
	} elif (var(VAR_4) <= 4) {
		blah()
	} elif (var(VAR_5) > 5) {
		blah()
	} elif (var(VAR_6) >= 6) {
		blah()
	} elif (flag(FLAG_1) == TRUE) {
		blah()
	} elif (flag(FLAG_2 +  BASE) == false) {
		blah()
	} elif (flag(FLAG_3)) {
		blah()
	} elif (!flag(FLAG_4)) {
		blah()
	} elif (var(VAR_1)) {
		blah()	
	} elif (!var(VAR_2)) {
		blah()
	} elif (defeated(TRAINER_GARY)) {
		blah()
	} elif (!defeated(TRAINER_BLUE)) {
		blah()
	} elif (defeated(TRAINER_GERALD) == TRUE) {
		blah()
	} elif (defeated(TRAINER_AXLE) == false) {
		blah()
	} else {
		message()
		lock
		faceplayer
		facepalm
		blah(1, 3, 4)
	}
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	scriptStmt := program.TopLevelStatements[0].(*ast.ScriptStatement)
	ifStmt := scriptStmt.Body.Statements[0].(*ast.IfStatement)
	testConditionExpression(t, ifStmt.Consequence.Expression.(*ast.OperatorExpression), token.VAR, "VAR_1", token.EQ, "1", ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[0].Expression.(*ast.OperatorExpression), token.VAR, "VAR_2", token.NEQ, "2", ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[1].Expression.(*ast.OperatorExpression), token.VAR, "VAR_3", token.LT, "3", ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[2].Expression.(*ast.OperatorExpression), token.VAR, "VAR_4", token.LTE, "4", ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[3].Expression.(*ast.OperatorExpression), token.VAR, "VAR_5", token.GT, "5", ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[4].Expression.(*ast.OperatorExpression), token.VAR, "VAR_6", token.GTE, "6", ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[5].Expression.(*ast.OperatorExpression), token.FLAG, "FLAG_1", token.EQ, token.TRUE, ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[6].Expression.(*ast.OperatorExpression), token.FLAG, "FLAG_2 + BASE", token.EQ, token.FALSE, ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[7].Expression.(*ast.OperatorExpression), token.FLAG, "FLAG_3", token.EQ, token.TRUE, ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[8].Expression.(*ast.OperatorExpression), token.FLAG, "FLAG_4", token.EQ, token.FALSE, ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[9].Expression.(*ast.OperatorExpression), token.VAR, "VAR_1", token.NEQ, "0", ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[10].Expression.(*ast.OperatorExpression), token.VAR, "VAR_2", token.EQ, "0", ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[11].Expression.(*ast.OperatorExpression), token.DEFEATED, "TRAINER_GARY", token.EQ, token.TRUE, ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[12].Expression.(*ast.OperatorExpression), token.DEFEATED, "TRAINER_BLUE", token.EQ, token.FALSE, ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[13].Expression.(*ast.OperatorExpression), token.DEFEATED, "TRAINER_GERALD", token.EQ, token.TRUE, ast.NormalComparison)
	testConditionExpression(t, ifStmt.ElifConsequences[14].Expression.(*ast.OperatorExpression), token.DEFEATED, "TRAINER_AXLE", token.EQ, token.FALSE, ast.NormalComparison)
	nested := ifStmt.Consequence.Body.Statements[0].(*ast.IfStatement)
	testConditionExpression(t, nested.Consequence.Expression.(*ast.OperatorExpression), token.VAR, "VAR_7", token.NEQ, "0x4000", ast.StrictValueComparison)

	if len(ifStmt.ElseConsequence.Statements) != 5 {
		t.Errorf("len(ifStmt.ElseConsequences) should be '%d'. got=%d", 5, len(ifStmt.ElseConsequence.Statements))
	}
}

func testConditionExpression(t *testing.T, expression *ast.OperatorExpression, expectedType token.Type, expectedOperand string, expectedOperator token.Type, expectedComparisonValue string, expectedComparisonType ast.ComparisonValueType) {
	if expression.Type != expectedType {
		t.Errorf("expression.Type not '%s'. got=%s", expectedType, expression.Type)
	}
	if expression.Operand.Literal != expectedOperand {
		t.Errorf("expression.Operand not '%s'. got=%s", expectedOperand, expression.Operand.Literal)
	}
	if expression.Operator != expectedOperator {
		t.Errorf("expression.Operator not '%s'. got=%s", expectedOperator, expression.Operator)
	}
	if expression.ComparisonValue != expectedComparisonValue {
		t.Errorf("expression.ComparisonValue not '%s'. got=%s", expectedComparisonValue, expression.ComparisonValue)
	}
	if expression.ComparisonValueType != expectedComparisonType {
		t.Errorf("expression.ComparisonValueType not '%d'. got=%d", expectedComparisonType, expression.ComparisonValueType)
	}
}

func TestWhileStatements(t *testing.T) {
	input := `
script Test {
	while (var(VAR_1) < 1) {
		if (var(VAR_7) != 1) {
			continue
		}
		message()
	}
	while (flag(FLAG_1)) {
		message()
		break
	}
	do {
		message()
		break
	} while (var(VAR_1) > value(0x4001 + (4)))
	while {
		message()
	}
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	scriptStmt := program.TopLevelStatements[0].(*ast.ScriptStatement)
	whileStmt := scriptStmt.Body.Statements[0].(*ast.WhileStatement)
	testConditionExpression(t, whileStmt.Consequence.Expression.(*ast.OperatorExpression), token.VAR, "VAR_1", token.LT, "1", ast.NormalComparison)
	ifStmt := whileStmt.Consequence.Body.Statements[0].(*ast.IfStatement)
	continueStmt := ifStmt.Consequence.Body.Statements[0].(*ast.ContinueStatement)
	if continueStmt.LoopStatment != whileStmt {
		t.Fatalf("continueStmt != whileStmt")
	}

	whileStmt = scriptStmt.Body.Statements[1].(*ast.WhileStatement)
	testConditionExpression(t, whileStmt.Consequence.Expression.(*ast.OperatorExpression), token.FLAG, "FLAG_1", token.EQ, "TRUE", ast.NormalComparison)
	breakStmt := whileStmt.Consequence.Body.Statements[1].(*ast.BreakStatement)
	if breakStmt.ScopeStatment != whileStmt {
		t.Fatalf("breakStmt != whileStmt")
	}

	doWhileStmt := scriptStmt.Body.Statements[2].(*ast.DoWhileStatement)
	testConditionExpression(t, doWhileStmt.Consequence.Expression.(*ast.OperatorExpression), token.VAR, "VAR_1", token.GT, "( 0x4001 + ( 4 ) )", ast.StrictValueComparison)
	breakStmt = doWhileStmt.Consequence.Body.Statements[1].(*ast.BreakStatement)
	if breakStmt.ScopeStatment != doWhileStmt {
		t.Fatalf("breakStmt != doWhileStmt")
	}

	infiniteWhileStmt := scriptStmt.Body.Statements[3].(*ast.WhileStatement)
	if infiniteWhileStmt.Consequence.Expression != nil {
		t.Errorf("Expected infinite while statement to have no condition expression")
	}
}

func TestCompoundBooleanExpressions(t *testing.T) {
	input := `
script Test {
	if (var(VAR_1) < value(1) || flag(FLAG_2) == true && var(VAR_3) > value(4)) {
		message()
	}
	if (var(VAR_1) < 1 && flag(FLAG_2) == true || giveitem(ITEM, 1) > 4) {
		message()
	}
	if ((var(VAR_1) == 10 || ((var(VAR_1) == 12))) && !(flag(FLAG_1))) {
		message()
	}
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{
		AutoVarCommands: map[string]AutoVarCommand{
			"giveitem": {VarName: "VAR_RESULT"},
		},
	}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	scriptStmt := program.TopLevelStatements[0].(*ast.ScriptStatement)
	ifStmt := scriptStmt.Body.Statements[0].(*ast.IfStatement)
	ex := ifStmt.Consequence.Expression.(*ast.BinaryExpression)
	if ex.Operator != token.OR {
		t.Fatalf("ex.Operator != token.OR. Got '%s' instead.", ex.Operator)
	}
	op := ex.Left.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.VAR, "1", "VAR_1", token.LT)
	op = (ex.Right.(*ast.BinaryExpression)).Left.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.FLAG, "TRUE", "FLAG_2", token.EQ)
	op = (ex.Right.(*ast.BinaryExpression)).Right.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.VAR, "4", "VAR_3", token.GT)

	ifStmt = scriptStmt.Body.Statements[1].(*ast.IfStatement)
	ex = ifStmt.Consequence.Expression.(*ast.BinaryExpression)
	if ex.Operator != token.OR {
		t.Fatalf("ex.Operator != token.OR Got '%s' instead.", ex.Operator)
	}
	op = (ex.Left.(*ast.BinaryExpression)).Left.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.VAR, "1", "VAR_1", token.LT)
	op = (ex.Left.(*ast.BinaryExpression)).Right.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.FLAG, "TRUE", "FLAG_2", token.EQ)
	op = ex.Right.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.VAR, "4", "VAR_RESULT", token.GT)

	ifStmt = scriptStmt.Body.Statements[2].(*ast.IfStatement)
	ex = ifStmt.Consequence.Expression.(*ast.BinaryExpression)
	if ex.Operator != token.AND {
		t.Fatalf("ex.Operator != token.AND Got '%s' instead.", ex.Operator)
	}
	op = (ex.Left.(*ast.BinaryExpression)).Left.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.VAR, "10", "VAR_1", token.EQ)
	op = (ex.Left.(*ast.BinaryExpression)).Right.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.VAR, "12", "VAR_1", token.EQ)
	op = ex.Right.(*ast.OperatorExpression)
	testOperatorExpression(t, op, token.FLAG, "TRUE", "FLAG_1", token.NEQ)
}

func testOperatorExpression(t *testing.T, ex *ast.OperatorExpression, expectType token.Type, comparisonValue string, operand string, operator token.Type) {
	if ex.Type != expectType {
		t.Fatalf("ex.Type != %s. Got '%s' instead.", expectType, ex.Type)
	}
	if ex.ComparisonValue != comparisonValue {
		t.Fatalf("ex.ComparisonValue != %s. Got '%s' instead.", comparisonValue, ex.ComparisonValue)
	}
	if ex.Operand.Literal != operand {
		t.Fatalf("ex.Operand != %s. Got '%s' instead.", operand, ex.Operand.Literal)
	}
	if ex.Operator != operator {
		t.Fatalf("ex.Operator != %s. Got '%s' instead.", operator, ex.Operator)
	}
}

func TestSwitchStatements(t *testing.T) {
	input := `
script Test {
	switch (var(VAR_1)) {
		case 0: message1()
		case 1:
		case 2: case 3:
			message2()
			switch (var(VAR_2)) {
				case 67: message67()
			}
			blah
		default:
			message3()
	}
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	scriptStmt := program.TopLevelStatements[0].(*ast.ScriptStatement)
	switchStmt, ok := scriptStmt.Body.Statements[0].(*ast.SwitchStatement)
	if !ok {
		t.Fatalf("not a switch statement\n")
	}
	if switchStmt.Operand.Literal != "VAR_1" {
		t.Fatalf("switchStmt.Operand != VAR_1. Got '%s' instead.", switchStmt.Operand.Literal)
	}
	if len(switchStmt.Cases) != 5 {
		t.Fatalf("len(switchStmt.Cases) != 5. Got '%d' instead.", len(switchStmt.Cases))
	}
	if switchStmt.DefaultCase == nil {
		t.Fatalf("switchStmt.DefaultCase == nil")
	}
	testSwitchCase(t, switchStmt.Cases[0], "0", 1)
	testSwitchCase(t, switchStmt.Cases[1], "1", 0)
	testSwitchCase(t, switchStmt.Cases[2], "2", 0)
	testSwitchCase(t, switchStmt.Cases[3], "3", 3)
	testSwitchCase(t, switchStmt.DefaultCase, "", 1)
	testSwitchCase(t, (switchStmt.Cases[3].Body.Statements[1].(*ast.SwitchStatement)).Cases[0], "67", 1)
}

func testSwitchCase(t *testing.T, sc *ast.SwitchCase, expectValue string, expectBodyLength int) {
	if sc.Value.Literal != expectValue {
		t.Fatalf("sc.Value != %s. Got '%s' instead.", expectValue, sc.Value.Literal)
	}
	if len(sc.Body.Statements) != expectBodyLength {
		t.Fatalf("len(sc.Body.Statements) != %d. Got '%d' instead.", expectBodyLength, len(sc.Body.Statements))
	}
}

func TestDuplicateTexts(t *testing.T) {
	input := `
script Script1 {
	msgbox("Hello$")
	msgbox(braille"Goodbye$")
	msgbox(ascii"StringType$")
	msgbox("Hello\n"
		   "Multiline$")
}

script Script2 {
	msgbox("Test$")
	msgbox(braille"Goodbye$")
	msgbox("Hello$")
	msgbox("StringType$")
	msgbox("Hello\n"
		"Multiline$", MSGBOX_DEFAULT)
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	if len(program.Texts) != 6 {
		t.Fatalf("len(program.Texts) != 6. Got '%d' instead.", len(program.Texts))
	}
}

func TestTextStatements(t *testing.T) {
	input := `
script MyScript1 {
	msgbox(ascii"Test$")
	msgbox("Hello$")
}

text MyText1 {
	"Hello$"
}

text MyText2 {
	"Foo"
	"Bar$"
}

script MyScript1 {
	foo()
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	if len(program.Texts) != 4 {
		t.Fatalf("len(program.Texts) != 4. Got '%d' instead.", len(program.Texts))
	}
}

func TestDuplicateMovements(t *testing.T) {
	input := `
script Script1 {
	applymovement(moves(walk_left * 2 walk_up face_down))
	applymovement(moves(face_left walk_down walk_down))
	applymovement(moves(walk_left * 2 walk_up face_down))
}

movement Movement1 {
	face_left walk_down walk_down face_right
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	numMovementStatements := 0
	for _, v := range program.TopLevelStatements {
		if _, ok := v.(*ast.MovementStatement); ok {
			numMovementStatements++
		}
	}

	if numMovementStatements != 3 {
		t.Fatalf("numMovementStatements != 3. Got '%d' instead.", numMovementStatements)
	}
}

func TestFormatOperator(t *testing.T) {
	input := `
script MyScript1 {
	msgbox(format("Test»{BLAH} and a bunch of extra stuff to overflow the line$"))
}

text MyText {
	format("FooBar and a bunch of extra stuff to overflow the line$", "TEST")
}

text MyText1 {
	format("FooBar and a bunch of extra stuff to overflow the line$", "TEST", 100)
}

text MyText2 {
	format("FooBar and a bunch of extra stuff to overflow the line$", 100, "TEST")
}

text MyText3 {
	format("aaaa aaa aa aaa aa aaa aa aaa aa aaa aa aaa", "1_latin_rse")
}

text MyText4 {
	format("aaaa aaa aa aaa aa aaa aa aaa aa aaa aa aaa", "1_latin_frlg")
}

text MyText5 {
	format("aaaa aaa aa a", numLines=3, maxLineLength=1, cursorOverlapWidth=100, fontId="1_latin_rse")
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "../font_config.json", "1_latin_frlg", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	if len(program.Texts) != 7 {
		t.Fatalf("len(program.Texts) != 7. Got '%d' instead.", len(program.Texts))
	}
	defaultTest := "Test»{BLAH} and a bunch of extra stuff to\\n\noverflow the line$"
	if program.Texts[0].Value != defaultTest {
		t.Fatalf("Incorrect format() evaluation. Got '%s' instead of '%s'", program.Texts[0].Value, defaultTest)
	}
	testBlank := "FooBar\\n\nand\\l\na\\l\nbunch\\l\nof\\l\nextra\\l\nstuff\\l\nto\\l\noverflow\\l\nthe\\l\nline$"
	if program.Texts[1].Value != testBlank {
		t.Fatalf("Incorrect format() evaluation. Got '%s' instead of '%s'", program.Texts[1].Value, testBlank)
	}
	test100 := "FooBar and\\n\na bunch of\\l\nextra\\l\nstuff to\\l\noverflow\\l\nthe line$"
	if program.Texts[2].Value != test100 {
		t.Fatalf("Incorrect format() evaluation. Got '%s' instead of '%s'", program.Texts[2].Value, test100)
	}
	if program.Texts[3].Value != test100 {
		t.Fatalf("Incorrect format() evaluation. Got '%s' instead of '%s'", program.Texts[3].Value, test100)
	}
	otherFont := "aaaa aaa aa aaa aa aaa aa aaa aa aaa aa\\n\naaa$"
	if program.Texts[4].Value != otherFont {
		t.Fatalf("Incorrect format() evaluation. Got '%s' instead of '%s'", program.Texts[4].Value, otherFont)
	}
	defaultFont := "aaaa aaa aa aaa aa aaa aa aaa aa\\n\naaa aa aaa$"
	if program.Texts[5].Value != defaultFont {
		t.Fatalf("Incorrect format() evaluation. Got '%s' instead of '%s'", program.Texts[5].Value, defaultFont)
	}
	namedParams := "aaaa\\n\naaa\\n\naa\\l\na$"
	if program.Texts[6].Value != namedParams {
		t.Fatalf("Incorrect format() evaluation. Got '%s' instead of '%s'", program.Texts[6].Value, namedParams)
	}

}

func TestMovementStatements(t *testing.T) {
	input := `
movement MyMovement {
	walk_up
	walk_down walk_left
	step_end
}

movement MyMovement2 {
}

movement MyMovement3 {
	run_up * 3
	face_down
	delay_16*2
}

script MyScript {
	applymovement(moves(
		walk_up * 4
		face_left, face_down
	))
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	if len(program.TopLevelStatements) != 5 {
		t.Fatalf("len(program.TopLevelStatements) != 5. Got '%d' instead.", len(program.TopLevelStatements))
	}
	testMovement(t, program.TopLevelStatements[0], "MyMovement", []string{"walk_up", "walk_down", "walk_left", "step_end"})
	testMovement(t, program.TopLevelStatements[1], "MyMovement2", []string{})
	testMovement(t, program.TopLevelStatements[2], "MyMovement3", []string{"run_up", "run_up", "run_up", "face_down", "delay_16", "delay_16"})
	testMovement(t, program.TopLevelStatements[4], "MyScript_Movement_0", []string{"walk_up", "walk_up", "walk_up", "walk_up", "face_left", "face_down"})
}

func testMovement(t *testing.T, stmt ast.Statement, expectedName string, expectedCommands []string) {
	movementStmt := stmt.(*ast.MovementStatement)
	if movementStmt.Name.Value != expectedName {
		t.Errorf("Incorrect movement name. Got '%s' instead of '%s'", movementStmt.Name.Value, expectedName)
	}
	if len(movementStmt.MovementCommands) != len(expectedCommands) {
		t.Fatalf("Incorrect number of movement commands. Got %d commands instead of %d", len(movementStmt.MovementCommands), len(expectedCommands))
	}
	for i, cmd := range expectedCommands {
		if movementStmt.MovementCommands[i].Literal != cmd {
			t.Errorf("Incorrect movement command at index %d. Got '%s' instead of '%s'", i, movementStmt.MovementCommands[i].Literal, cmd)
		}
	}
}

func TestMartStatements(t *testing.T) {
	input := `
mart NormalMart {
	ITEM_LAVA_COOKIE
	ITEM_MOOMOO_MILK
	ITEM_RARE_CANDY
	ITEM_LEMONADE
	ITEM_BERRY_JUICE
}

mart EmptyMart {
}

mart EarlyTerminatedMart {
	ITEM_LAVA_COOKIE
	ITEM_MOOMOO_MILK
	ITEM_NONE
	ITEM_RARE_CANDY
	ITEM_LEMONADE
	ITEM_BERRY_JUICE
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	if len(program.TopLevelStatements) != 3 {
		t.Fatalf("len(program.TopLevelStatements) != 3. Got '%d' instead.", len(program.TopLevelStatements))
	}
	testMart(t, program.TopLevelStatements[0], "NormalMart", []string{"ITEM_LAVA_COOKIE", "ITEM_MOOMOO_MILK", "ITEM_RARE_CANDY", "ITEM_LEMONADE", "ITEM_BERRY_JUICE"})
	testMart(t, program.TopLevelStatements[1], "EmptyMart", []string{})
	// ITEM_NONE only terminates the array early upon emission, not when parsing.
	testMart(t, program.TopLevelStatements[2], "EarlyTerminatedMart", []string{"ITEM_LAVA_COOKIE", "ITEM_MOOMOO_MILK", "ITEM_NONE", "ITEM_RARE_CANDY", "ITEM_LEMONADE", "ITEM_BERRY_JUICE"})
}

func testMart(t *testing.T, stmt ast.Statement, expectedName string, expectedItems []string) {
	martStmt := stmt.(*ast.MartStatement)
	if martStmt.Name.Value != expectedName {
		t.Errorf("Incorrect mart name. Got '%s' instead of '%s'", martStmt.Name.Value, expectedName)
	}
	if len(martStmt.Items) != len(expectedItems) {
		t.Fatalf("Incorrect number of mart items. Got %d commands instead of %d", len(martStmt.Items), len(expectedItems))
	}
	for i, cmd := range expectedItems {
		if martStmt.Items[i] != cmd {
			t.Errorf("Incorrect movement command at index %d. Got '%s' instead of '%s'", i, martStmt.Items[i], cmd)
		}
	}
}

func TestMapScriptStatements(t *testing.T) {
	input := `
mapscripts MyMap_MapScripts {
	MAP_SCRIPT_ON_TRANSITION: MyMap_OnTransition
	MAP_SCRIPT_ON_RESUME: MyMap_OnResume
	MAP_SCRIPT_ON_TRANSITION {
		lock
		release
	}
	MAP_SCRIPT_ON_FRAME_TABLE [
		VAR_LITTLEROOT_INTRO_STATE, 1: MyMap_OnFrame_FirstThing
		VAR_LITTLEROOT_INTRO_STATE    + 2, 1+ BASE_THING: MyMap_OnFrame_2
		VAR_OTHER, 3 {
			lock
			foo(1, 2)
			release
		}
	]
	MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE [
		VAR_TEMP_1, 0 { foo }
		VAR_TEMP_1, 1 { some more commands }
	]
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	if len(program.TopLevelStatements) != 1 {
		t.Fatalf("len(program.TopLevelStatements) != 1. Got '%d' instead.", len(program.TopLevelStatements))
	}
	stmt := program.TopLevelStatements[0].(*ast.MapScriptsStatement)
	if stmt.Name.Value != "MyMap_MapScripts" {
		t.Errorf("Incorrect mapscripts name. Got '%s' instead of '%s'", stmt.Name.Value, "MyMap_MapScripts")
	}
	if len(stmt.MapScripts) != 3 {
		t.Fatalf("Incorrect length of MapScripts. Got '%d' instead of '%d'", len(stmt.MapScripts), 3)
	}
	testNamedMapScript(t, stmt.MapScripts[0], "MyMap_OnTransition", "MAP_SCRIPT_ON_TRANSITION")
	testNamedMapScript(t, stmt.MapScripts[1], "MyMap_OnResume", "MAP_SCRIPT_ON_RESUME")
	testScriptedMapScript(t, stmt.MapScripts[2], "MyMap_MapScripts_MAP_SCRIPT_ON_TRANSITION", "MAP_SCRIPT_ON_TRANSITION", 2)

	if len(stmt.TableMapScripts) != 2 {
		t.Fatalf("Incorrect length of TableMapScripts. Got '%d' instead of '%d'", len(stmt.TableMapScripts), 1)
	}
	testTableMapScript(t, stmt.TableMapScripts[0], "MyMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE", "MAP_SCRIPT_ON_FRAME_TABLE", 3)
	testTableMapScriptEntry(t, stmt.TableMapScripts[0].Entries[0], "VAR_LITTLEROOT_INTRO_STATE", "1", "MyMap_OnFrame_FirstThing")
	testTableMapScriptEntry(t, stmt.TableMapScripts[0].Entries[1], "VAR_LITTLEROOT_INTRO_STATE + 2", "1 + BASE_THING", "MyMap_OnFrame_2")
	testScriptedTableMapScriptEntry(t, stmt.TableMapScripts[0].Entries[2], "VAR_OTHER", "3", "MyMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2", 3)
	testTableMapScript(t, stmt.TableMapScripts[1], "MyMap_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE", "MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE", 2)
	testScriptedTableMapScriptEntry(t, stmt.TableMapScripts[1].Entries[0], "VAR_TEMP_1", "0", "MyMap_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0", 1)
	testScriptedTableMapScriptEntry(t, stmt.TableMapScripts[1].Entries[1], "VAR_TEMP_1", "1", "MyMap_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1", 3)
}

func testNamedMapScript(t *testing.T, mapScript ast.MapScript, expectedName string, expectedType string) {
	if mapScript.Name != expectedName {
		t.Errorf("Incorrect mapScript name. Got '%s' instead of '%s'", mapScript.Name, expectedName)
	}
	if mapScript.Type.Literal != expectedType {
		t.Errorf("Incorrect mapScript type. Got '%s' instead of '%s'", mapScript.Type.Literal, expectedType)
	}
	if mapScript.Script != nil {
		t.Errorf("mapScript is supposed to be nil")
	}
}

func testScriptedMapScript(t *testing.T, mapScript ast.MapScript, expectedName string, expectedType string, expectedNumStatements int) {
	if mapScript.Name != expectedName {
		t.Errorf("Incorrect scripted mapScript name. Got '%s' instead of '%s'", mapScript.Name, expectedName)
	}
	if mapScript.Type.Literal != expectedType {
		t.Errorf("Incorrect scripted mapScript type. Got '%s' instead of '%s'", mapScript.Type.Literal, expectedType)
	}
	if mapScript.Script == nil {
		t.Errorf("mapScript.Script is not supposed to be nil")
	}
	if len(mapScript.Script.Body.Statements) != expectedNumStatements {
		t.Errorf("Incorrect scripted mapScript number of statements. Got '%d' instead of '%d'", len(mapScript.Script.Body.Statements), expectedNumStatements)
	}
}

func testTableMapScript(t *testing.T, mapScript ast.TableMapScript, expectedName string, expectedType string, expectedNumEntries int) {
	if mapScript.Name != expectedName {
		t.Errorf("Incorrect table mapScript name. Got '%s' instead of '%s'", mapScript.Name, expectedName)
	}
	if mapScript.Type.Literal != expectedType {
		t.Errorf("Incorrect table mapScript type. Got '%s' instead of '%s'", mapScript.Type.Literal, expectedType)
	}
	if len(mapScript.Entries) != expectedNumEntries {
		t.Errorf("Incorrect table mapScript number of entries. Got '%d' instead of '%d'", len(mapScript.Entries), expectedNumEntries)
	}
}

func testTableMapScriptEntry(t *testing.T, mapScriptEntry ast.TableMapScriptEntry, expectedCondition, expectedComparison, expectedName string) {
	if mapScriptEntry.Condition.Literal != expectedCondition {
		t.Errorf("Incorrect table mapScript entry condition. Got '%s' instead of '%s'", mapScriptEntry.Condition.Literal, expectedCondition)
	}
	if mapScriptEntry.Comparison != expectedComparison {
		t.Errorf("Incorrect table mapScript entry comparison. Got '%s' instead of '%s'", mapScriptEntry.Comparison, expectedComparison)
	}
	if mapScriptEntry.Name != expectedName {
		t.Errorf("Incorrect table mapScript entry name. Got '%s' instead of '%s'", mapScriptEntry.Name, expectedName)
	}
	if mapScriptEntry.Script != nil {
		t.Errorf("mapScriptEntry.Script is supposed to be nil")
	}
}

func testScriptedTableMapScriptEntry(t *testing.T, mapScriptEntry ast.TableMapScriptEntry, expectedCondition, expectedComparison, expectedName string, expectedNumStatements int) {
	if mapScriptEntry.Condition.Literal != expectedCondition {
		t.Errorf("Incorrect table mapScript entry condition. Got '%s' instead of '%s'", mapScriptEntry.Condition.Literal, expectedCondition)
	}
	if mapScriptEntry.Comparison != expectedComparison {
		t.Errorf("Incorrect table mapScript entry comparison. Got '%s' instead of '%s'", mapScriptEntry.Comparison, expectedComparison)
	}
	if mapScriptEntry.Name != expectedName {
		t.Errorf("Incorrect table mapScript entry name. Got '%s' instead of '%s'", mapScriptEntry.Name, expectedName)
	}
	if mapScriptEntry.Script == nil {
		t.Errorf("mapScriptEntry.Script is supposed to be nil")
	}
	if len(mapScriptEntry.Script.Body.Statements) != expectedNumStatements {
		t.Errorf("Incorrect scripted mapScriptEntry number of statements. Got '%d' instead of '%d'", len(mapScriptEntry.Script.Body.Statements), expectedNumStatements)
	}
}

func TestScopeModifiers(t *testing.T) {
	input := `
script Script1 {}
script(local) Script2 {}
script(global) Script3 {}
text Text1 {"test"}
text(local) Text2 {"test"}
text(global) Text3 {"test"}
movement Movement1 {}
movement(local) Movement2 {}
movement(global) Movement3 {}
mapscripts MapScripts1 {}
mapscripts(local) MapScripts2 {}
mapscripts(global) MapScripts3 {}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	if len(program.TopLevelStatements) != 12 {
		t.Fatalf("len(program.TopLevelStatements) != 12. Got '%d' instead.", len(program.TopLevelStatements))
	}
	expectedScopes := []token.Type{
		token.GLOBAL,
		token.LOCAL,
		token.GLOBAL,
		token.GLOBAL,
		token.LOCAL,
		token.GLOBAL,
		token.LOCAL,
		token.LOCAL,
		token.GLOBAL,
		token.GLOBAL,
		token.LOCAL,
		token.GLOBAL,
	}
	for i, expectedScope := range expectedScopes {
		testScope(t, i, program.TopLevelStatements[i], expectedScope)
	}
}

func testScope(t *testing.T, i int, statement ast.Statement, expectedScope token.Type) {
	if script, ok := statement.(*ast.ScriptStatement); ok {
		if script.Scope != expectedScope {
			t.Errorf("%d: Expected script scope %s, but got %s", i, expectedScope, script.Scope)
		}
	} else if text, ok := statement.(*ast.TextStatement); ok {
		if text.Scope != expectedScope {
			t.Errorf("%d: Expected text scope %s, but got %s", i, expectedScope, text.Scope)
		}
	} else if movement, ok := statement.(*ast.MovementStatement); ok {
		if movement.Scope != expectedScope {
			t.Errorf("%d: Expected movement scope %s, but got %s", i, expectedScope, movement.Scope)
		}
	} else if mapscripts, ok := statement.(*ast.MapScriptsStatement); ok {
		if mapscripts.Scope != expectedScope {
			t.Errorf("%d: Expected mapscripts scope %s, but got %s", i, expectedScope, mapscripts.Scope)
		}
	}
}

func TestConstants(t *testing.T) {
	input := `
const FOO = 2
const BAR = FLAG_TEMP_1 +   3
	- FLAG_BASE   const PROF_BIRCH = FOO+1
const PROF_ELM = PROF_BIRCH - 1

script Script1 {
	command1(FOO)
	command2(1, 2 + BAR)
	command3(2, (PROF_ELM) - ((PROF_BIRCH + FOO)))
	if (flag(PROF_ELM)) {}
	if (var(PROF_BIRCH) == PROF_ELM +1) {}
	switch (var(PROF_ELM)) {
		case FOO: commandfood()
		default: command()
	}
}

mapscripts MyMapScript {
	MAP_SCRIPT_ON_FRAME_TABLE [
		PROF_ELM, FOO: MyOnFrameScript
	]
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	script := program.TopLevelStatements[0].(*ast.ScriptStatement)
	command1 := script.Body.Statements[0].(*ast.CommandStatement)
	command2 := script.Body.Statements[1].(*ast.CommandStatement)
	command3 := script.Body.Statements[2].(*ast.CommandStatement)
	testConstant(t, "2", command1.Args[0])
	testConstant(t, "2 + FLAG_TEMP_1 + 3 - FLAG_BASE", command2.Args[1])
	testConstant(t, "( 2 + 1 - 1 ) - ( ( 2 + 1 + 2 ) )", command3.Args[1])

	if1 := script.Body.Statements[3].(*ast.IfStatement)
	op1 := if1.Consequence.Expression.(*ast.OperatorExpression)
	testConstant(t, "2 + 1 - 1", op1.Operand.Literal)

	if2 := script.Body.Statements[4].(*ast.IfStatement)
	op2 := if2.Consequence.Expression.(*ast.OperatorExpression)
	testConstant(t, "2 + 1", op2.Operand.Literal)
	testConstant(t, "2 + 1 - 1 + 1", op2.ComparisonValue)

	sw := script.Body.Statements[5].(*ast.SwitchStatement)
	testConstant(t, "2 + 1 - 1", sw.Operand.Literal)
	testConstant(t, "2", sw.Cases[0].Value.Literal)

	ms := program.TopLevelStatements[1].(*ast.MapScriptsStatement)
	frame := ms.TableMapScripts[0].Entries[0]
	testConstant(t, "2 + 1 - 1", frame.Condition.Literal)
	testConstant(t, "2", frame.Comparison)
}

func testConstant(t *testing.T, expected, actual string) {
	if actual != expected {
		t.Errorf("Expected '%s', but got '%s'", expected, actual)
	}
}

type labelTest struct {
	commandIndex int
	name         string
	isGlobal     bool
}

func TestLabelStatements(t *testing.T) {
	input := `
script MyScript {
	lock
MyLabel:
	foo(1, 2)
MyLabel2(global): bar
	release
}

script MyScript2 {MyLabel3:}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{}, "../font_config.json", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}
	if len(program.TopLevelStatements) != 2 {
		t.Fatalf("program.TopLevelStatements does not contain 2 statements. got=%d", len(program.TopLevelStatements))
	}

	tests := []struct {
		expectedLabels []labelTest
	}{
		{
			[]labelTest{
				{
					commandIndex: 1,
					name:         "MyLabel",
					isGlobal:     false,
				},
				{
					commandIndex: 3,
					name:         "MyLabel2",
					isGlobal:     true,
				},
			},
		},
		{
			[]labelTest{
				{
					commandIndex: 0,
					name:         "MyLabel3",
					isGlobal:     false,
				},
			},
		},
	}

	for i, tt := range tests {
		stmt := program.TopLevelStatements[i]
		if !testLabels(t, stmt, tt.expectedLabels) {
			return
		}
	}
}

func testLabels(t *testing.T, s ast.Statement, expectedLabels []labelTest) bool {
	if s.TokenLiteral() != "script" {
		t.Errorf("s.TokenLiteral not 'script'. got=%q", s.TokenLiteral())
		return false
	}

	scriptStmt, ok := s.(*ast.ScriptStatement)
	if !ok {
		t.Errorf("s not %T. got=%T", &ast.ScriptStatement{}, s)
		return false
	}

	if scriptStmt.Body == nil {
		t.Errorf("scriptStmt.Body was nil")
		return false
	}

	for _, expectedLabelTest := range expectedLabels {
		expectedLabel := scriptStmt.Body.Statements[expectedLabelTest.commandIndex]
		labelStmt, ok := expectedLabel.(*ast.LabelStatement)
		if !ok {
			t.Errorf("s not %T. got=%T", &ast.LabelStatement{}, s)
			return false
		}

		if labelStmt.Name.Value != expectedLabelTest.name {
			t.Errorf("labelStmt.Name.Value not '%s'. got=%s", expectedLabelTest.name, labelStmt.Name.Value)
			return false
		}

		if labelStmt.IsGlobal != expectedLabelTest.isGlobal {
			t.Errorf("labelStmt.IsGlobal not '%t'. got=%t", expectedLabelTest.isGlobal, labelStmt.IsGlobal)
			return false
		}
	}

	return true
}

var zero = 0

func TestAutoVarCommandsSwitchStatement(t *testing.T) {
	input := `
script Test {
	switch (multichoice(0, 0, MULTI_WHERES_RAYQUAZA, FALSE)) {
		case 2:
			two()
		case 1:
		case 0:
			oneandzero()
	}
	switch (specialvar(VAR_FOO, DoSpecialThing)) {
		case 4:
			four()
		case 5:
		case 6:
			fiveandsix()
	}
}
`
	l := lexer.New(input)
	p := New(l, CommandConfig{
		AutoVarCommands: map[string]AutoVarCommand{
			"multichoice": {VarName: "VAR_MULTICHOICE_RESULT"},
			"specialvar":  {VarNameArgPosition: &zero},
		},
	}, "", "", 0, nil)
	program, err := p.ParseProgram()
	if err != nil {
		t.Fatalf(err.Error())
	}

	scriptStmt := program.TopLevelStatements[0].(*ast.ScriptStatement)
	multichoiceStmt, ok := scriptStmt.Body.Statements[0].(*ast.CommandStatement)
	if !ok {
		t.Fatalf("not a command statement\n")
	}
	if multichoiceStmt.Name.Value != "multichoice" {
		t.Fatalf("autovar switch command != 'multichoice'. Got '%s' instead.", multichoiceStmt.Name.Value)
	}
	if len(multichoiceStmt.Args) != 4 {
		t.Fatalf("autovar switch multichoice should have 4 args. Got '%d' instead.", len(multichoiceStmt.Args))
	}
	switchStmt, ok := scriptStmt.Body.Statements[1].(*ast.SwitchStatement)
	if !ok {
		t.Fatalf("not a switch statement\n")
	}
	if switchStmt.Operand.Literal != "VAR_MULTICHOICE_RESULT" {
		t.Fatalf("autovar switchStmt.Operand != VAR_MULTICHOICE_RESULT. Got '%s' instead.", switchStmt.Operand.Literal)
	}
	if len(switchStmt.Cases) != 3 {
		t.Fatalf("len(switchStmt.Cases) != 3. Got '%d' instead.", len(switchStmt.Cases))
	}
	if switchStmt.DefaultCase != nil {
		t.Fatalf("switchStmt.DefaultCase is expected to be nil")
	}
	testSwitchCase(t, switchStmt.Cases[0], "2", 1)
	testSwitchCase(t, switchStmt.Cases[1], "1", 0)
	testSwitchCase(t, switchStmt.Cases[2], "0", 1)

	specialvar, ok := scriptStmt.Body.Statements[2].(*ast.CommandStatement)
	if !ok {
		t.Fatalf("not a command statement\n")
	}
	if specialvar.Name.Value != "specialvar" {
		t.Fatalf("autovar switch command != 'specialvar'. Got '%s' instead.", specialvar.Name.Value)
	}
	if len(specialvar.Args) != 2 {
		t.Fatalf("autovar switch specialvar should have 2 args. Got '%d' instead.", len(specialvar.Args))
	}
	switchStmt, ok = scriptStmt.Body.Statements[3].(*ast.SwitchStatement)
	if !ok {
		t.Fatalf("not a switch statement\n")
	}
	if switchStmt.Operand.Literal != "VAR_FOO" {
		t.Fatalf("autovar switchStmt.Operand != VAR_FOO. Got '%s' instead.", switchStmt.Operand.Literal)
	}
	if len(switchStmt.Cases) != 3 {
		t.Fatalf("len(switchStmt.Cases) != 3. Got '%d' instead.", len(switchStmt.Cases))
	}
	if switchStmt.DefaultCase != nil {
		t.Fatalf("switchStmt.DefaultCase is expected to be nil")
	}
	testSwitchCase(t, switchStmt.Cases[0], "4", 1)
	testSwitchCase(t, switchStmt.Cases[1], "5", 0)
	testSwitchCase(t, switchStmt.Cases[2], "6", 1)
}

func TestErrors(t *testing.T) {
	tests := []struct {
		input              string
		expectedError      ParseError
		expectedErrorMsg   string
		expectedErrorRegex string
	}{
		{
			input: `
script Script1 {
	break
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 6, Utf8CharEnd: 6, Message: "'break' statement outside of any break-able scope"},
			expectedErrorMsg: "line 3: 'break' statement outside of any break-able scope",
		},
		{
			input: `
script Script1 {
	while (flag(FLAG_1)) {
		somestuff
		break
	}
	break
}`,
			expectedError:    ParseError{LineNumberStart: 7, LineNumberEnd: 7, CharStart: 1, Utf8CharStart: 1, CharEnd: 6, Utf8CharEnd: 6, Message: "'break' statement outside of any break-able scope"},
			expectedErrorMsg: "line 7: 'break' statement outside of any break-able scope",
		},
		{
			input: `
script Script1 {
	while (flag(FLAG_1)) {
		somestuff
		continue
	}
	continue
}`,
			expectedError:    ParseError{LineNumberStart: 7, LineNumberEnd: 7, CharStart: 1, Utf8CharStart: 1, CharEnd: 9, Utf8CharEnd: 9, Message: "'continue' statement outside of any continue-able scope"},
			expectedErrorMsg: "line 7: 'continue' statement outside of any continue-able scope",
		},
		{
			input: `
script Script1 {
	switch (var(VAR_1)) {
	case 1:
		msgbox
		break
	case 2:
		continue
	}
}`,
			expectedError:    ParseError{LineNumberStart: 8, LineNumberEnd: 8, CharStart: 2, Utf8CharStart: 2, CharEnd: 10, Utf8CharEnd: 10, Message: "'continue' statement outside of any continue-able scope"},
			expectedErrorMsg: "line 8: 'continue' statement outside of any continue-able scope",
		},
		{
			input: `
script Script1 {}
raw ` + "``" + `
invalid
`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 0, Utf8CharStart: 0, CharEnd: 7, Utf8CharEnd: 7, Message: "could not parse top-level statement for 'invalid'"},
			expectedErrorMsg: "line 4: could not parse top-level statement for 'invalid'",
		},
		{
			input: `
raw "stuff"
`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 0, Utf8CharStart: 0, CharEnd: 11, Utf8CharEnd: 11, Message: "raw statement must begin with a backtick character '`'"},
			expectedErrorMsg: "line 2: raw statement must begin with a backtick character '`'",
		},
		{
			input: `
script {
	foo
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 0, Utf8CharStart: 0, CharEnd: 8, Utf8CharEnd: 8, Message: "missing name for script"},
			expectedErrorMsg: "line 2: missing name for script",
		},
		{
			input: `
script MyScript
	foo
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 3, CharStart: 0, Utf8CharStart: 0, CharEnd: 4, Utf8CharEnd: 4, Message: "missing opening curly brace for script 'MyScript'"},
			expectedErrorMsg: "line 2: missing opening curly brace for script 'MyScript'",
		},
		{
			input: `
script MyScript {
	if (var(VAR_1)) {
	foo
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 16, Utf8CharStart: 16, CharEnd: 17, Utf8CharEnd: 17, Message: "missing closing curly brace for block statement"},
			expectedErrorMsg: "line 2: missing closing curly brace for block statement",
		},
		{
			input: `
script MyScript {
	switch (var(VAR_1)) {
	case 1: foo
`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 5, CharStart: 21, Utf8CharStart: 21, CharEnd: 0, Utf8CharEnd: 0, Message: "missing end for switch case body"},
			expectedErrorMsg: "line 3: missing end for switch case body",
		},
		{
			input: `
script MyScript {
	foo
	<
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 1, Utf8CharStart: 1, CharEnd: 2, Utf8CharEnd: 2, Message: "could not parse statement for '<'"},
			expectedErrorMsg: "line 4: could not parse statement for '<'",
		},
		{
			input: `
script MyScript {
	if (flag(FLAG_1)) {
		foo
	} else
		bar
	}
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 6, CharStart: 3, Utf8CharStart: 3, CharEnd: 5, Utf8CharEnd: 5, Message: "missing opening curly brace of else statement"},
			expectedErrorMsg: "line 5: missing opening curly brace of else statement",
		},
		{
			input: `
script MyScript {
	do
		foo
	while (flag(FLAG_1))
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 4, CharStart: 1, Utf8CharStart: 1, CharEnd: 5, Utf8CharEnd: 5, Message: "missing opening curly brace of do...while statement"},
			expectedErrorMsg: "line 3: missing opening curly brace of do...while statement",
		},
		{
			input: `
script MyScript {
	do {
		foo
	} (flag(FLAG_1))
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 5, CharStart: 1, Utf8CharStart: 1, CharEnd: 4, Utf8CharEnd: 4, Message: "missing 'while' after body of do...while statement"},
			expectedErrorMsg: "line 5: missing 'while' after body of do...while statement",
		},
		{
			input: `
script MyScript {
	do {
		foo
	} while flag(FLAG_1)
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 5, CharStart: 3, Utf8CharStart: 3, CharEnd: 13, Utf8CharEnd: 13, Message: "missing '(' to start condition for do...while statement"},
			expectedErrorMsg: "line 5: missing '(' to start condition for do...while statement",
		},
		{
			input: `
script MyScript {
	while (flag(FLAG_1)) {
		continue
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 2, Utf8CharStart: 2, CharEnd: 10, Utf8CharEnd: 10, Message: "'continue' must be the last statement in block scope"},
			expectedErrorMsg: "line 4: 'continue' must be the last statement in block scope",
		},
		{
			input: `
script MyScript {
	switch flag(FLAG_1) {
	case 1:
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 12, Utf8CharEnd: 12, Message: "missing opening parenthesis of switch statement operand"},
			expectedErrorMsg: "line 3: missing opening parenthesis of switch statement operand",
		},
		{
			input: `
script MyScript {
	switch (flag(FLAG_1)) {
	case 1:
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 9, Utf8CharStart: 9, CharEnd: 13, Utf8CharEnd: 13, Message: "expected next token to be 'VAR' or auto-var command, got 'flag' instead"},
			expectedErrorMsg: "line 3: expected next token to be 'VAR' or auto-var command, got 'flag' instead",
		},
		{
			input: `
script MyScript {
	switch (specialvar(foo, bar)) {
	case 1:
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 9, Utf8CharStart: 9, CharEnd: 29, Utf8CharEnd: 29, Message: "auto-var command specialvar has an arg position of 2, but only 2 arguments were provided"},
			expectedErrorMsg: "line 3: auto-var command specialvar has an arg position of 2, but only 2 arguments were provided",
		},
		{
			input: `
script MyScript {
	switch (var FLéG_1) {
	case 1:
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 9, Utf8CharStart: 9, CharEnd: 20, Utf8CharEnd: 19, Message: "missing '(' after var operator. Got 'FLéG_1` instead"},
			expectedErrorMsg: "line 3: missing '(' after var operator. Got 'FLéG_1` instead",
		},
		{
			input: `
script MyScript {
	switch (var(FLAG_1 + 2`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 7, Utf8CharEnd: 7, Message: "missing closing parenthesis of switch statement value"},
			expectedErrorMsg: "line 3: missing closing parenthesis of switch statement value",
		},
		{
			input: `
script MyScript {
	switch (var(FLAG_1))
	case 1:
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 4, CharStart: 20, Utf8CharStart: 20, CharEnd: 5, Utf8CharEnd: 5, Message: "missing opening curly brace of switch statement"},
			expectedErrorMsg: "line 3: missing opening curly brace of switch statement",
		},
		{
			input: `
script MyScript {
	switch (var(FLAG_1)) {
	case 1:
	case 2:
		foo
	case 1:
		bar
	}
}`,
			expectedError:    ParseError{LineNumberStart: 7, LineNumberEnd: 7, CharStart: 1, Utf8CharStart: 1, CharEnd: 8, Utf8CharEnd: 8, Message: "duplicate switch cases detected for case '1'"},
			expectedErrorMsg: "line 7: duplicate switch cases detected for case '1'",
		},
		{
			input: `
script MyScript {
	switch (var(FLAG_1)) {
	case 2:
		foo
	default
		baz
	}
}`,
			expectedError:    ParseError{LineNumberStart: 6, LineNumberEnd: 6, CharStart: 1, Utf8CharStart: 1, CharEnd: 8, Utf8CharEnd: 8, Message: "missing `:` after default"},
			expectedErrorMsg: "line 6: missing `:` after default",
		},
		{
			input: `
script MyScript {
	switch (var(FLAG_1)) {
	case 2:
	case 7
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 5, CharStart: 1, Utf8CharStart: 1, CharEnd: 5, Utf8CharEnd: 5, Message: "missing `:` after 'case'"},
			expectedErrorMsg: "line 5: missing `:` after 'case'",
		},
		{
			input: `
script MyScript {
	switch (var(FLAG_1)) {
		foo
	}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 2, Utf8CharStart: 2, CharEnd: 5, Utf8CharEnd: 5, Message: "invalid start of switch case 'foo'. Expected 'case' or 'default'"},
			expectedErrorMsg: "line 4: invalid start of switch case 'foo'. Expected 'case' or 'default'",
		},
		{
			input: `
script MyScript {
	switch (var(FLAG_1)) {
	}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 4, CharStart: 1, Utf8CharStart: 1, CharEnd: 2, Utf8CharEnd: 2, Message: "switch statement has no cases or default case"},
			expectedErrorMsg: "line 3: switch statement has no cases or default case",
		},
		{
			input: `
script MyScript {
	if var(FLAG_1)) {
	}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 7, Utf8CharEnd: 7, Message: "missing '(' to start boolean expression"},
			expectedErrorMsg: "line 3: missing '(' to start boolean expression",
		},
		{
			input: `
script MyScript {
	if (var(FLAG_1) ||) {
	}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 19, Utf8CharStart: 19, CharEnd: 20, Utf8CharEnd: 20, Message: "left side of binary expression must be var(), flag(), defeated(), or autovar command. Instead, found ')'"},
			expectedErrorMsg: "line 3: left side of binary expression must be var(), flag(), defeated(), or autovar command. Instead, found ')'",
		},
		{
			input: `
script MyScript {
	if (var(FLAG_1))
		foo
	}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 2, Utf8CharStart: 2, CharEnd: 5, Utf8CharEnd: 5, Message: "expected next token to be '{', got 'foo' instead"},
			expectedErrorMsg: "line 4: expected next token to be '{', got 'foo' instead",
		},
		{
			input: `
script MyScript {
	if (var(FLAG_1) && (var(VAR_1) == 1 {
		foo
	}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 5, CharStart: 35, Utf8CharStart: 35, CharEnd: 2, Utf8CharEnd: 2, Message: "missing ')', '&&' or '||' when evaluating 'var' operator"},
			expectedErrorMsg: "line 3: missing ')', '&&' or '||' when evaluating 'var' operator",
		},
		{
			input: `
script MyScript {
	if (specialvar(foo)) {
		stuff
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 5, Utf8CharStart: 5, CharEnd: 20, Utf8CharEnd: 20, Message: "auto-var command specialvar has an arg position of 2, but only 1 arguments were provided"},
			expectedErrorMsg: "line 3: auto-var command specialvar has an arg position of 2, but only 1 arguments were provided",
		},
		{
			input: `
script MyScript {
	if (var{FLAG_1) {
		foo
	}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 5, Utf8CharStart: 5, CharEnd: 9, Utf8CharEnd: 9, Message: "missing opening parenthesis for condition operator 'VAR'"},
			expectedErrorMsg: "line 3: missing opening parenthesis for condition operator 'VAR'",
		},
		{
			input: `
script MyScript {
	if (flag{FLAG_1) {
		foo
	}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 5, Utf8CharStart: 5, CharEnd: 10, Utf8CharEnd: 10, Message: "missing opening parenthesis for condition operator 'FLAG'"},
			expectedErrorMsg: "line 3: missing opening parenthesis for condition operator 'FLAG'",
		},
		{
			input: `
script MyScript {
	if (flag()) {
		foo
	}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 5, Utf8CharStart: 5, CharEnd: 11, Utf8CharEnd: 11, Message: "missing value for condition operator 'FLAG'"},
			expectedErrorMsg: "line 3: missing value for condition operator 'FLAG'",
		},
		{
			input: `
script MyScript {
	foo(sdfa
	bar()
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 4, Utf8CharEnd: 4, Message: "missing closing parenthesis for command 'foo'"},
			expectedErrorMsg: "line 3: missing closing parenthesis for command 'foo'",
		},
		{
			input: `
script MyScript {
	if (flag(FLAG_1)) {
		foo
	} elif (fla(FLAG_2)) {
		bar
	}
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 5, CharStart: 9, Utf8CharStart: 9, CharEnd: 12, Utf8CharEnd: 12, Message: "left side of binary expression must be var(), flag(), defeated(), or autovar command. Instead, found 'fla'"},
			expectedErrorMsg: "line 5: left side of binary expression must be var(), flag(), defeated(), or autovar command. Instead, found 'fla'",
		},
		{
			input: `
script MyScript {
	if (flag(FLAG_1)) {
		foo
	} else {
		else
	}
}`,
			expectedError:    ParseError{LineNumberStart: 6, LineNumberEnd: 6, CharStart: 2, Utf8CharStart: 2, CharEnd: 6, Utf8CharEnd: 6, Message: "could not parse statement for 'else'"},
			expectedErrorMsg: "line 6: could not parse statement for 'else'",
		},
		{
			input: `
script MyScript {
	do {
		continue
		break
	} while (flag(FLAG_1))
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 2, Utf8CharStart: 2, CharEnd: 10, Utf8CharEnd: 10, Message: "'continue' must be the last statement in block scope"},
			expectedErrorMsg: "line 4: 'continue' must be the last statement in block scope",
		},
		{
			input: `
script MyScript {
	do {
		continue
	} while (flag(FLAG_1) == 45)
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 5, CharStart: 26, Utf8CharStart: 26, CharEnd: 28, Utf8CharEnd: 28, Message: "invalid flag comparison value '45'. Only TRUE and FALSE are allowed"},
			expectedErrorMsg: "line 5: invalid flag comparison value '45'. Only TRUE and FALSE are allowed",
		},
		{
			input: `
script MyScript {
	switch (var(VAR_1)) {
	default:
		foo
	case 1:
		bar
	default:
		baz
	}
}`,
			expectedError:    ParseError{LineNumberStart: 8, LineNumberEnd: 8, CharStart: 1, Utf8CharStart: 1, CharEnd: 8, Utf8CharEnd: 8, Message: "multiple `default` cases found in switch statement. Only one `default` case is allowed"},
			expectedErrorMsg: "line 8: multiple `default` cases found in switch statement. Only one `default` case is allowed",
		},
		{
			input: `
script MyScript {
	switch (var(VAR_1)) {
	case 1:
		bar
	default:
		baz
		continue
	}
}`,
			expectedError:    ParseError{LineNumberStart: 8, LineNumberEnd: 8, CharStart: 2, Utf8CharStart: 2, CharEnd: 10, Utf8CharEnd: 10, Message: "'continue' statement outside of any continue-able scope"},
			expectedErrorMsg: "line 8: 'continue' statement outside of any continue-able scope",
		},
		{
			input: `
script MyScript {
	while ((flag(FLAG_1) {
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 8, Utf8CharStart: 8, CharEnd: 23, Utf8CharEnd: 23, Message: "missing closing ')' for nested boolean expression"},
			expectedErrorMsg: "line 3: missing closing ')' for nested boolean expression",
		},
		{
			input: `
script MyScript {
	while (flag(FLAG_1 {
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 8, Utf8CharStart: 8, CharEnd: 12, Utf8CharEnd: 12, Message: "missing closing ')' for condition operator value"},
			expectedErrorMsg: "line 3: missing closing ')' for condition operator value",
		},
		{
			input: `
script MyScript {
	while (flag(FLAG_1) == ) {
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 21, Utf8CharStart: 21, CharEnd: 25, Utf8CharEnd: 25, Message: "missing comparison value for flag operator"},
			expectedErrorMsg: "line 3: missing comparison value for flag operator",
		},
		{
			input: `
script MyScript {
	while (var(VAR_1) == ) {
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 19, Utf8CharStart: 19, CharEnd: 23, Utf8CharEnd: 23, Message: "missing comparison value for var operator"},
			expectedErrorMsg: "line 3: missing comparison value for var operator",
		},
		{
			input: `
script MyScript {
	if (defeated(TRAINER_FOO) == ) {
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 27, Utf8CharStart: 27, CharEnd: 31, Utf8CharEnd: 31, Message: "missing comparison value for defeated operator"},
			expectedErrorMsg: "line 3: missing comparison value for defeated operator",
		},
		{
			input: `
script MyScript {
	while (var(VAR_1) == 1 && flag(FLAG_1) == true && flag()) {
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 51, Utf8CharStart: 51, CharEnd: 57, Utf8CharEnd: 57, Message: "missing value for condition operator 'FLAG'"},
			expectedErrorMsg: "line 3: missing value for condition operator 'FLAG'",
		},
		{
			input: `
text {
	"MyText$"
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 0, Utf8CharStart: 0, CharEnd: 6, Utf8CharEnd: 6, Message: "missing name for text statement"},
			expectedErrorMsg: "line 2: missing name for text statement",
		},
		{
			input: `
text Text1
	"MyText$"
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 3, CharStart: 0, Utf8CharStart: 0, CharEnd: 10, Utf8CharEnd: 10, Message: "missing opening curly brace for text 'Text1'"},
			expectedErrorMsg: "line 2: missing opening curly brace for text 'Text1'",
		},
		{
			input: `
text Text1 {
	nottext
	"MyText$"
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 8, Utf8CharEnd: 8, Message: "body of text statement must be a string or formatted string. Got 'nottext' instead"},
			expectedErrorMsg: "line 3: body of text statement must be a string or formatted string. Got 'nottext' instead",
		},
		{
			input: `
text Text1 {
	"MyText$"
	notcurlybrace
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 1, Utf8CharStart: 1, CharEnd: 14, Utf8CharEnd: 14, Message: "expected closing curly brace for text. Got 'notcurlybrace' instead"},
			expectedErrorMsg: "line 4: expected closing curly brace for text. Got 'notcurlybrace' instead",
		},
		{
			input: `
script Script1 {
	msgbox("Hello")
}
text Script1_Text_0 {
	"MyText$"
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 5, CharStart: 0, Utf8CharStart: 0, CharEnd: 4, Utf8CharEnd: 4, Message: "duplicate text label 'Script1_Text_0'. Choose a unique label that won't clash with the auto-generated text labels"},
			expectedErrorMsg: "line 5: duplicate text label 'Script1_Text_0'. Choose a unique label that won't clash with the auto-generated text labels",
		},
		{
			input: `
script Script1 {
	applymovent(moves(walk_up))
}
movement Script1_Movement_0 {
	walk_down
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 5, CharStart: 0, Utf8CharStart: 0, CharEnd: 8, Utf8CharEnd: 8, Message: "duplicate movement label 'Script1_Movement_0'. Choose a unique label that won't clash with the auto-generated movement labels"},
			expectedErrorMsg: "line 5: duplicate movement label 'Script1_Movement_0'. Choose a unique label that won't clash with the auto-generated movement labels",
		},
		{
			input: `
script Script1 {
	applymovent(moves walk_up)
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 13, Utf8CharStart: 13, CharEnd: 18, Utf8CharEnd: 18, Message: "moves operator must begin with an open parenthesis '('"},
			expectedErrorMsg: "line 3: moves operator must begin with an open parenthesis '('",
		},
		{
			input: `
script Script1 {
	applymovent(moves(*))
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 19, Utf8CharStart: 19, CharEnd: 20, Utf8CharEnd: 20, Message: "expected movement command, but got '*' instead"},
			expectedErrorMsg: "line 3: expected movement command, but got '*' instead",
		},
		{
			input: `
movement {

}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 0, Utf8CharStart: 0, CharEnd: 10, Utf8CharEnd: 10, Message: "missing name for movement statement"},
			expectedErrorMsg: "line 2: missing name for movement statement",
		},
		{
			input: `
mart {

}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 0, Utf8CharStart: 0, CharEnd: 6, Utf8CharEnd: 6, Message: "missing name for mart statement"},
			expectedErrorMsg: "line 2: missing name for mart statement",
		},
		{
			input: `
movement Foo
	walk_up
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 3, CharStart: 0, Utf8CharStart: 0, CharEnd: 8, Utf8CharEnd: 8, Message: "missing opening curly brace for movement 'Foo'"},
			expectedErrorMsg: "line 2: missing opening curly brace for movement 'Foo'",
		},
		{
			input: `
mart FooMart
	walk_down
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 3, CharStart: 0, Utf8CharStart: 0, CharEnd: 10, Utf8CharEnd: 10, Message: "missing opening curly brace for mart 'FooMart'"},
			expectedErrorMsg: "line 2: missing opening curly brace for mart 'FooMart'",
		},
		{
			input: `
mart Foo {
	ITEM_FOO
	ITEM_BAR * 2
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 10, Utf8CharStart: 10, CharEnd: 11, Utf8CharEnd: 11, Message: "expected mart item, but got '*' instead"},
			expectedErrorMsg: "line 4: expected mart item, but got '*' instead",
		},
		{
			input: `
movement Foo {
	+
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 2, Utf8CharEnd: 2, Message: "expected movement command, but got '+' instead"},
			expectedErrorMsg: "line 3: expected movement command, but got '+' instead",
		},
		{
			input: `
movement Foo {
	walk_up * walk_down
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 11, Utf8CharStart: 11, CharEnd: 20, Utf8CharEnd: 20, Message: "expected mulplier number for movement command, but got 'walk_down' instead"},
			expectedErrorMsg: "line 3: expected mulplier number for movement command, but got 'walk_down' instead",
		},
		{
			input: `
movement Foo {
	walk_up * 999999999999999999999999999999999
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 11, Utf8CharStart: 11, CharEnd: 44, Utf8CharEnd: 44, Message: "invalid movement mulplier integer '999999999999999999999999999999999': strconv.ParseInt: parsing \"999999999999999999999999999999999\": value out of range"},
			expectedErrorMsg: "line 3: invalid movement mulplier integer '999999999999999999999999999999999': strconv.ParseInt: parsing \"999999999999999999999999999999999\": value out of range",
		},
		{
			input: `
movement Foo {
	walk_up * 10000
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 11, Utf8CharStart: 11, CharEnd: 16, Utf8CharEnd: 16, Message: "movement mulplier '10000' is too large. Maximum is 9999"},
			expectedErrorMsg: "line 3: movement mulplier '10000' is too large. Maximum is 9999",
		},
		{
			input: `
movement Foo {
	walk_up * 0
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 11, Utf8CharStart: 11, CharEnd: 12, Utf8CharEnd: 12, Message: "movement mulplier must be a positive integer, but got '0' instead"},
			expectedErrorMsg: "line 3: movement mulplier must be a positive integer, but got '0' instead",
		},
		{
			input: `
movement Foo {
	walk_up * -2
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 11, Utf8CharStart: 11, CharEnd: 13, Utf8CharEnd: 13, Message: "movement mulplier must be a positive integer, but got '-2' instead"},
			expectedErrorMsg: "line 3: movement mulplier must be a positive integer, but got '-2' instead",
		},
		{
			input: `
text Foo {
	format asdf
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 12, Utf8CharEnd: 12, Message: "format operator must begin with an open parenthesis '('"},
			expectedErrorMsg: "line 3: format operator must begin with an open parenthesis '('",
		},
		{
			input: `
text Foo {
	format()
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 8, Utf8CharStart: 8, CharEnd: 9, Utf8CharEnd: 9, Message: "invalid format() argument ')'. Expected a string literal"},
			expectedErrorMsg: "line 3: invalid format() argument ')'. Expected a string literal",
		},
		{
			input: `
text Foo {
	format("Hi", )
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 14, Utf8CharStart: 14, CharEnd: 15, Utf8CharEnd: 15, Message: "invalid format() parameter ')'"},
			expectedErrorMsg: "line 3: invalid format() parameter ')'",
		},
		{
			input: `
text Foo {
	format("Hi"
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 0, Utf8CharStart: 0, CharEnd: 1, Utf8CharEnd: 1, Message: "missing closing parenthesis ')' for format()"},
			expectedErrorMsg: "line 4: missing closing parenthesis ')' for format()",
		},
		{
			input: `
text Foo {
	format("Hi", invalid=5)
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 14, Utf8CharStart: 14, CharEnd: 21, Utf8CharEnd: 21, Message: "invalid format() named parameter 'invalid'"},
			expectedErrorMsg: "line 3: invalid format() named parameter 'invalid'",
		},
		{
			input: `
text Foo {
	format("Hi", numLines 5)
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 23, Utf8CharStart: 23, CharEnd: 24, Utf8CharEnd: 24, Message: "missing '=' after format() named parameter 'numLines'"},
			expectedErrorMsg: "line 3: missing '=' after format() named parameter 'numLines'",
		},
		{
			input: `
text Foo {
	format("Hi", fontId=5)
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 21, Utf8CharStart: 21, CharEnd: 22, Utf8CharEnd: 22, Message: "invalid fontId '5'. Expected string"},
			expectedErrorMsg: "line 3: invalid fontId '5'. Expected string",
		},
		{
			input: `
text Foo {
	format("Hi", maxLineLength="hi")
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 28, Utf8CharStart: 28, CharEnd: 32, Utf8CharEnd: 32, Message: "invalid maxLineLength 'hi'. Expected integer"},
			expectedErrorMsg: "line 3: invalid maxLineLength 'hi'. Expected integer",
		},
		{
			input: `
text Foo {
	format("Hi", numLines="hi")
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 23, Utf8CharStart: 23, CharEnd: 27, Utf8CharEnd: 27, Message: "invalid numLines 'hi'. Expected integer"},
			expectedErrorMsg: "line 3: invalid numLines 'hi'. Expected integer",
		},
		{
			input: `
text Foo {
	format("Hi", cursorOverlapWidth="hi")
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 33, Utf8CharStart: 33, CharEnd: 37, Utf8CharEnd: 37, Message: "invalid cursorOverlapWidth 'hi'. Expected integer"},
			expectedErrorMsg: "line 3: invalid cursorOverlapWidth 'hi'. Expected integer",
		},
		{
			input: `
text Foo {
	format("Hi", "TEST", "NOT_AN_INT")
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 22, Utf8CharStart: 22, CharEnd: 34, Utf8CharEnd: 34, Message: "invalid format() maxLineLength 'NOT_AN_INT'. Expected integer"},
			expectedErrorMsg: "line 3: invalid format() maxLineLength 'NOT_AN_INT'. Expected integer",
		},
		{
			input: `
text Foo {
	format("Hi", 100, 42)
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 19, Utf8CharStart: 19, CharEnd: 21, Utf8CharEnd: 21, Message: "invalid format() fontId '42'. Expected string"},
			expectedErrorMsg: "line 3: invalid format() fontId '42'. Expected string",
		},
		{
			input: `
script Foo {
	msgbox(format("Hi", ))
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 21, Utf8CharStart: 21, CharEnd: 22, Utf8CharEnd: 22, Message: "invalid format() parameter ')'"},
			expectedErrorMsg: "line 3: invalid format() parameter ')'",
		},
		{
			input: `
text Foo {
	format("Hi", "invalidFontID")
}`,
			expectedError:      ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 14, Utf8CharStart: 14, CharEnd: 29, Utf8CharEnd: 29},
			expectedErrorRegex: `line 3: unknown fontID 'invalidFontID' used in format\(\)\. List of valid fontIDs are '\[((1_latin_rse)|(1_latin_frlg)| )+\]'`,
		},
		{
			input: `
text Foo {
	format("Hi", cursorOverlapWidth=3, 100)
}`,
			expectedError:      ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 36, Utf8CharStart: 36, CharEnd: 39, Utf8CharEnd: 39, Message: "invalid parameter '100'. Expected named parameter"},
			expectedErrorRegex: `line 3: invalid parameter '100'. Expected named parameter`,
		},
		{
			input: `
text Foo {
	format("Hi", cursorOverlapWidth=3, cursorOverlapWidth=4)
}`,
			expectedError:      ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 36, Utf8CharStart: 36, CharEnd: 54, Utf8CharEnd: 54, Message: "duplicate parameter 'cursorOverlapWidth'"},
			expectedErrorRegex: `line 3: duplicate parameter 'cursorOverlapWidth'`,
		},
		{
			input: `
text Foo {
	format("Hi", "fakeFont", fontId="otherfont)
}`,
			expectedError:      ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 26, Utf8CharStart: 26, CharEnd: 32, Utf8CharEnd: 32, Message: "duplicate parameter 'fontId'"},
			expectedErrorRegex: `line 3: duplicate parameter 'fontId'`,
		},
		{
			input: `
text Foo {
	format("Hi", 100, maxLineLength=50)
}`,
			expectedError:      ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 19, Utf8CharStart: 19, CharEnd: 32, Utf8CharEnd: 32, Message: "duplicate parameter 'maxLineLength'"},
			expectedErrorRegex: `line 3: duplicate parameter 'maxLineLength'`,
		},
		{
			input: `
mapscripts {
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 0, Utf8CharStart: 0, CharEnd: 12, Utf8CharEnd: 12, Message: "missing name for mapscripts statement"},
			expectedErrorMsg: "line 2: missing name for mapscripts statement",
		},
		{
			input: `
mapscripts MyMapScripts
}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 3, CharStart: 0, Utf8CharStart: 0, CharEnd: 1, Utf8CharEnd: 1, Message: "missing opening curly brace for mapscripts 'MyMapScripts'"},
			expectedErrorMsg: "line 2: missing opening curly brace for mapscripts 'MyMapScripts'",
		},
		{
			input: `
mapscripts MyMapScripts {
	+
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 1, Utf8CharStart: 1, CharEnd: 2, Utf8CharEnd: 2, Message: "expected map script type, but got '+' instead"},
			expectedErrorMsg: "line 3: expected map script type, but got '+' instead",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE: 5
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 12, Utf8CharStart: 12, CharEnd: 13, Utf8CharEnd: 13, Message: "expected map script label after ':', but got '5' instead"},
			expectedErrorMsg: "line 3: expected map script label after ':', but got '5' instead",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE MyScript
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 11, Utf8CharStart: 11, CharEnd: 19, Utf8CharEnd: 19, Message: "expected ':', '[', or '{' after map script type 'SOME_TYPE', but got 'MyScript' instead"},
			expectedErrorMsg: "line 3: expected ':', '[', or '{' after map script type 'SOME_TYPE', but got 'MyScript' instead",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE {
		if (sdf)
	}
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 6, Utf8CharStart: 6, CharEnd: 9, Utf8CharEnd: 9, Message: "left side of binary expression must be var(), flag(), defeated(), or autovar command. Instead, found 'sdf'"},
			expectedErrorMsg: "line 4: left side of binary expression must be var(), flag(), defeated(), or autovar command. Instead, found 'sdf'",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE [
		VAR_TEMP
	]
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 2, Utf8CharStart: 2, CharEnd: 10, Utf8CharEnd: 10, Message: "missing ',' to specify map script table entry comparison value"},
			expectedErrorMsg: "line 4: missing ',' to specify map script table entry comparison value",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE [
		VAR_TEMP, : Foo
	]
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 2, Utf8CharStart: 2, CharEnd: 13, Utf8CharEnd: 13, Message: "expected comparison value for map script table entry, but it was empty"},
			expectedErrorMsg: "line 4: expected comparison value for map script table entry, but it was empty",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE [
		VAR_TEMP, FOO
	]
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 2, Utf8CharStart: 2, CharEnd: 15, Utf8CharEnd: 15, Message: "missing ':' or '{' to specify map script table entry"},
			expectedErrorMsg: "line 4: missing ':' or '{' to specify map script table entry",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE [
		, FOO: Foo Script
	]
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 2, Utf8CharStart: 2, CharEnd: 3, Utf8CharEnd: 3, Message: "expected condition for map script table entry, but it was empty"},
			expectedErrorMsg: "line 4: expected condition for map script table entry, but it was empty",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE [
		VAR_TEMP, 1: 5
	]
}`,
			expectedError:    ParseError{LineNumberStart: 4, LineNumberEnd: 4, CharStart: 15, Utf8CharStart: 15, CharEnd: 16, Utf8CharEnd: 16, Message: "expected map script label after ':', but got '5' instead"},
			expectedErrorMsg: "line 4: expected map script label after ':', but got '5' instead",
		},
		{
			input: `
mapscripts MyMapScripts {
	SOME_TYPE [
		VAR_TEMP, 1 {
			msgbox(
		}
	]
}`,
			expectedError:    ParseError{LineNumberStart: 5, LineNumberEnd: 5, CharStart: 3, Utf8CharStart: 3, CharEnd: 9, Utf8CharEnd: 9, Message: "missing closing parenthesis for command 'msgbox'"},
			expectedErrorMsg: "line 5: missing closing parenthesis for command 'msgbox'",
		},
		{
			input: `
script(asdf) MyScript {}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 7, Utf8CharStart: 7, CharEnd: 11, Utf8CharEnd: 11, Message: "scope modifier must be 'global' or 'local', but got 'asdf' instead"},
			expectedErrorMsg: "line 2: scope modifier must be 'global' or 'local', but got 'asdf' instead",
		},
		{
			input: `
script(local MyScript {}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 7, Utf8CharStart: 7, CharEnd: 12, Utf8CharEnd: 12, Message: "missing ')' after scope modifier. Got 'MyScript' instead"},
			expectedErrorMsg: "line 2: missing ')' after scope modifier. Got 'MyScript' instead",
		},
		{
			input: `
text(local MyText {"test"}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 5, Utf8CharStart: 5, CharEnd: 10, Utf8CharEnd: 10, Message: "missing ')' after scope modifier. Got 'MyText' instead"},
			expectedErrorMsg: "line 2: missing ')' after scope modifier. Got 'MyText' instead",
		},
		{
			input: `
movement() MyMovement {walk_left}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 9, Utf8CharStart: 9, CharEnd: 10, Utf8CharEnd: 10, Message: "scope modifier must be 'global' or 'local', but got ')' instead"},
			expectedErrorMsg: "line 2: scope modifier must be 'global' or 'local', but got ')' instead",
		},
		{
			input: `
mart() MyMart {ITEM_FOO}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 5, Utf8CharStart: 5, CharEnd: 6, Utf8CharEnd: 6, Message: "scope modifier must be 'global' or 'local', but got ')' instead"},
			expectedErrorMsg: "line 2: scope modifier must be 'global' or 'local', but got ')' instead",
		},
		{
			input: `
mapscripts() MyMapScripts {}`,
			expectedError:    ParseError{LineNumberStart: 2, LineNumberEnd: 2, CharStart: 11, Utf8CharStart: 11, CharEnd: 12, Utf8CharEnd: 12, Message: "scope modifier must be 'global' or 'local', but got ')' instead"},
			expectedErrorMsg: "line 2: scope modifier must be 'global' or 'local', but got ')' instead",
		},
		{
			input:            `const 45`,
			expectedError:    ParseError{LineNumberStart: 1, LineNumberEnd: 1, CharStart: 6, Utf8CharStart: 6, CharEnd: 8, Utf8CharEnd: 8, Message: "expected identifier after const, but got '45' instead"},
			expectedErrorMsg: "line 1: expected identifier after const, but got '45' instead",
		},
		{
			input:            `const FOO`,
			expectedError:    ParseError{LineNumberStart: 1, LineNumberEnd: 1, CharStart: 6, Utf8CharStart: 6, CharEnd: 9, Utf8CharEnd: 9, Message: "missing equals sign after const name 'FOO'"},
			expectedErrorMsg: "line 1: missing equals sign after const name 'FOO'",
		},
		{
			input:            `const FOO = 4 const FOO = 5`,
			expectedError:    ParseError{LineNumberStart: 1, LineNumberEnd: 1, CharStart: 20, Utf8CharStart: 20, CharEnd: 23, Utf8CharEnd: 23, Message: "duplicate const 'FOO'. Must use unique const names"},
			expectedErrorMsg: "line 1: duplicate const 'FOO'. Must use unique const names",
		},
		{
			input:            `const FOO = `,
			expectedError:    ParseError{LineNumberStart: 1, LineNumberEnd: 1, CharStart: 0, Utf8CharStart: 0, CharEnd: 11, Utf8CharEnd: 11, Message: "missing value for const 'FOO'"},
			expectedErrorMsg: "line 1: missing value for const 'FOO'",
		},
		{
			input: `const FOO =
script MyScript {}`,
			expectedError:    ParseError{LineNumberStart: 1, LineNumberEnd: 1, CharStart: 0, Utf8CharStart: 0, CharEnd: 11, Utf8CharEnd: 11, Message: "missing value for const 'FOO'"},
			expectedErrorMsg: "line 1: missing value for const 'FOO'",
		},
		{
			input: `
script MyScript {
	if (var(VAR_1) != value 4)) {
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 25, Utf8CharStart: 25, CharEnd: 26, Utf8CharEnd: 26, Message: "expected next token to be '(', got '4' instead"},
			expectedErrorMsg: "line 3: expected next token to be '(', got '4' instead",
		},
		{
			input: `
script MyScript {
	if (var(VAR_1) != value(4 {
		foo
	}
}`,
			expectedError:    ParseError{LineNumberStart: 3, LineNumberEnd: 3, CharStart: 19, Utf8CharStart: 19, CharEnd: 24, Utf8CharEnd: 24, Message: "missing ')' when evaluating 'value'"},
			expectedErrorMsg: "line 3: missing ')' when evaluating 'value'",
		},
	}

	for _, test := range tests {
		testForParseError(t, test.input, test.expectedError, test.expectedErrorMsg, test.expectedErrorRegex)
	}
}

var two = 2

func testForParseError(t *testing.T, input string, expectedError ParseError, expectedErrorMsg, expectedErrorRegex string) {
	l := lexer.New(input)
	p := New(l, CommandConfig{
		AutoVarCommands: map[string]AutoVarCommand{
			"specialvar": {VarNameArgPosition: &two},
		},
	}, "../font_config.json", "", 0, nil)
	_, err := p.ParseProgram()
	if err == nil {
		t.Fatalf("Expected error '%s', but no error occurred", expectedError)
	}
	var parseErr ParseError
	if !errors.As(err, &parseErr) {
		t.Fatalf("Expected ParseError type, but got '%s'", err.Error())
	}
	if parseErr.CharEnd != expectedError.CharEnd || parseErr.CharStart != expectedError.CharStart ||
		parseErr.LineNumberEnd != expectedError.LineNumberEnd || parseErr.LineNumberStart != expectedError.LineNumberStart {
		t.Fatalf("Expected error:\n\n%s\n\nbut got\n\n%v", prettyPrintParseError(expectedError), prettyPrintParseError(parseErr))
	}
	if expectedErrorMsg != "" && expectedErrorRegex == "" {
		if err.Error() != expectedErrorMsg {
			t.Fatalf("Expected error message '%s', but got '%s'", expectedErrorMsg, err.Error())
		}
	}
	if expectedErrorRegex != "" {
		isMatch, _ := regexp.MatchString(expectedErrorRegex, err.Error())
		if !isMatch {
			t.Fatalf("Expected error to match regex '%s', but got '%s'", expectedErrorRegex, err.Error())
		}
	}
}

func prettyPrintParseError(e ParseError) string {
	return fmt.Sprintf(
		"LineNumberStart: %d\nLineNumberEnd: %d\nCharStart: %d\nUtf8CharStart: %d\nCharEnd: %d\nUtf8CharEnd: %d\nMessage: %s",
		e.LineNumberStart,
		e.LineNumberEnd,
		e.CharStart,
		e.Utf8CharStart,
		e.CharEnd,
		e.Utf8CharEnd,
		e.Message)
}
