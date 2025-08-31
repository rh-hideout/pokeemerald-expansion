package emitter

import (
	"fmt"
	"strings"

	"github.com/huderlem/poryscript/ast"
	"github.com/huderlem/poryscript/token"
)

// Interface that manages chunk branching behavior.
type brancher interface {
	renderBranchConditions(sb *strings.Builder, scriptName string, nextChunkID int, registerJumpChunk func(int), enableLineMarkers bool, inputFilepath string) bool
	getTailChunkID() int
}

// Helper types for keeping track of script chunk branching logic.
type conditionDestination struct {
	id                 int
	operatorExpression *ast.OperatorExpression
}

// Represents the initial jump to a loop or comparison chunk.
type jump struct {
	destChunkID int
}

// Satisfies brancher interface.
func (j *jump) renderBranchConditions(sb *strings.Builder, scriptName string, nextChunkID int, registerJumpChunk func(int), enableLineMarkers bool, inputFilepath string) bool {
	if j.destChunkID != nextChunkID {
		registerJumpChunk(j.destChunkID)
		sb.WriteString(fmt.Sprintf("\tgoto %s_%d\n", scriptName, j.destChunkID))
		return false
	}
	return true
}

// Satisfies brancher interface.
func (j *jump) getTailChunkID() int {
	return j.destChunkID
}

// Represents a break statement, where it branches to after its loop scope.
type breakContext struct {
	destChunkID int
}

// Satisfies brancher interface.
func (bc *breakContext) renderBranchConditions(sb *strings.Builder, scriptName string, nextChunkID int, registerJumpChunk func(int), enableLineMarkers bool, inputFilepath string) bool {
	if bc.destChunkID == -1 {
		sb.WriteString("\treturn\n")
		return false
	} else if bc.destChunkID != nextChunkID {
		registerJumpChunk(bc.destChunkID)
		sb.WriteString(fmt.Sprintf("\tgoto %s_%d\n", scriptName, bc.destChunkID))
		return false
	}
	return true
}

// Satisfies brancher interface.
func (bc *breakContext) getTailChunkID() int {
	return bc.destChunkID
}

// Represents a leaf expression of a compound boolean expression.
type leafExpressionBranch struct {
	truthyDest        *conditionDestination
	falseyReturnID    int
	preambleStatement *ast.CommandStatement
}

// Satisfies brancher interface.
func (l *leafExpressionBranch) renderBranchConditions(sb *strings.Builder, scriptName string, nextChunkID int, registerJumpChunk func(int), enableLineMarkers bool, inputFilepath string) bool {
	registerJumpChunk(l.truthyDest.id)
	if l.preambleStatement != nil {
		sb.WriteString(renderCommandStatement(l.preambleStatement))
	}
	renderBranchComparison(sb, l.truthyDest, scriptName, enableLineMarkers, inputFilepath)
	if l.falseyReturnID == -1 {
		sb.WriteString("\treturn\n")
		return false
	} else if l.falseyReturnID != nextChunkID {
		registerJumpChunk(l.falseyReturnID)
		sb.WriteString(fmt.Sprintf("\tgoto %s_%d\n", scriptName, l.falseyReturnID))
		return false
	}
	return true
}

// Satisfies brancher interface.
func (l *leafExpressionBranch) getTailChunkID() int {
	return l.falseyReturnID
}

type switchCaseBranch struct {
	comparisonValue token.Token
	destChunkID     int
}

// Represents the a switch statement branch behavior.
type switchBranch struct {
	operand     token.Token
	cases       []*switchCaseBranch
	defaultCase *switchCaseBranch
	destChunkID int
}

// Satisfies brancher interface.
func (s *switchBranch) renderBranchConditions(sb *strings.Builder, scriptName string, nextChunkID int, registerJumpChunk func(int), enableLineMarkers bool, inputFilepath string) bool {
	tryEmitLineMarker(sb, s.operand, enableLineMarkers, inputFilepath)
	sb.WriteString(fmt.Sprintf("\tswitch %s\n", s.operand.Literal))
	for _, switchCase := range s.cases {
		registerJumpChunk(switchCase.destChunkID)
		tryEmitLineMarker(sb, switchCase.comparisonValue, enableLineMarkers, inputFilepath)
		sb.WriteString(fmt.Sprintf("\tcase %s, %s_%d\n", switchCase.comparisonValue.Literal, scriptName, switchCase.destChunkID))
	}

	if s.defaultCase != nil {
		if s.defaultCase.destChunkID != nextChunkID {
			registerJumpChunk(s.defaultCase.destChunkID)
			sb.WriteString(fmt.Sprintf("\tgoto %s_%d\n", scriptName, s.defaultCase.destChunkID))
			return false
		}
	} else if s.destChunkID != nextChunkID {
		if s.destChunkID == -1 {
			sb.WriteString("\treturn\n")
		} else {
			registerJumpChunk(s.destChunkID)
			sb.WriteString(fmt.Sprintf("\tgoto %s_%d\n", scriptName, s.destChunkID))
		}
		return false
	}

	return true
}

// Satisfies brancher interface.
func (s *switchBranch) getTailChunkID() int {
	if s.defaultCase != nil {
		return s.defaultCase.destChunkID
	}
	return s.destChunkID
}

func renderBranchComparison(sb *strings.Builder, dest *conditionDestination, scriptName string, enableLineMarkers bool, inputFilepath string) {
	tryEmitLineMarker(sb, dest.operatorExpression.Operand, enableLineMarkers, inputFilepath)
	switch dest.operatorExpression.Type {
	case token.FLAG:
		renderFlagComparison(sb, dest, scriptName)
	case token.VAR:
		renderVarComparison(sb, dest, scriptName)
	case token.DEFEATED:
		renderDefeatedComparison(sb, dest, scriptName)
	}
}

func renderFlagComparison(sb *strings.Builder, dest *conditionDestination, scriptName string) {
	if (dest.operatorExpression.Operator == token.EQ && dest.operatorExpression.ComparisonValue == token.TRUE) ||
		(dest.operatorExpression.Operator == token.NEQ && dest.operatorExpression.ComparisonValue == token.FALSE) {
		sb.WriteString(fmt.Sprintf("\tgoto_if_set %s, %s_%d\n", dest.operatorExpression.Operand.Literal, scriptName, dest.id))
	} else {
		sb.WriteString(fmt.Sprintf("\tgoto_if_unset %s, %s_%d\n", dest.operatorExpression.Operand.Literal, scriptName, dest.id))
	}
}

func renderVarComparison(sb *strings.Builder, dest *conditionDestination, scriptName string) {
	compareCommand := "compare"
	if dest.operatorExpression.ComparisonValueType == ast.StrictValueComparison {
		compareCommand = "compare_var_to_value"
	}
	sb.WriteString(fmt.Sprintf("\t%s %s, %s\n", compareCommand, dest.operatorExpression.Operand.Literal, dest.operatorExpression.ComparisonValue))
	switch dest.operatorExpression.Operator {
	case token.EQ:
		sb.WriteString(fmt.Sprintf("\tgoto_if_eq %s_%d\n", scriptName, dest.id))
	case token.NEQ:
		sb.WriteString(fmt.Sprintf("\tgoto_if_ne %s_%d\n", scriptName, dest.id))
	case token.LT:
		sb.WriteString(fmt.Sprintf("\tgoto_if_lt %s_%d\n", scriptName, dest.id))
	case token.LTE:
		sb.WriteString(fmt.Sprintf("\tgoto_if_le %s_%d\n", scriptName, dest.id))
	case token.GT:
		sb.WriteString(fmt.Sprintf("\tgoto_if_gt %s_%d\n", scriptName, dest.id))
	case token.GTE:
		sb.WriteString(fmt.Sprintf("\tgoto_if_ge %s_%d\n", scriptName, dest.id))
	}
}

func renderDefeatedComparison(sb *strings.Builder, dest *conditionDestination, scriptName string) {
	sb.WriteString(fmt.Sprintf("\tchecktrainerflag %s\n", dest.operatorExpression.Operand.Literal))
	if (dest.operatorExpression.Operator == token.EQ && dest.operatorExpression.ComparisonValue == token.TRUE) ||
		(dest.operatorExpression.Operator == token.NEQ && dest.operatorExpression.ComparisonValue == token.FALSE) {
		sb.WriteString(fmt.Sprintf("\tgoto_if 1, %s_%d\n", scriptName, dest.id))
	} else {
		sb.WriteString(fmt.Sprintf("\tgoto_if 0, %s_%d\n", scriptName, dest.id))
	}
}
