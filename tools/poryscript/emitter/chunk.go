package emitter

import (
	"fmt"
	"strings"

	"github.com/huderlem/poryscript/ast"
	"github.com/huderlem/poryscript/parser"
)

// Represents a single chunk of script output. Each chunk has an associated label in
// the emitted bytecode output.
type chunk struct {
	id               int
	returnID         int
	useEndTerminator bool
	statements       []ast.Statement
	branchBehavior   brancher
}

func (c *chunk) getLabel(scriptName string) string {
	if c.id == 0 {
		// Main script entrypoint label.
		return scriptName
	}
	return fmt.Sprintf("%s_%d", scriptName, c.id)
}

func (c *chunk) renderLabel(scriptName string, isGlobal bool, sb *strings.Builder) {
	label := c.getLabel(scriptName)
	isMainEntryPoint := c.id == 0
	if isMainEntryPoint && isGlobal {
		sb.WriteString(fmt.Sprintf("%s::\n", label))
	} else {
		sb.WriteString(fmt.Sprintf("%s:\n", label))
	}
}

func (c *chunk) renderStatements(sb *strings.Builder, chunkLabels map[string]struct{}, textLabels map[string]struct{}, enableLineMarkers bool, inputFilepath string) error {
	// Render basic non-branching commands.
	for _, stmt := range c.statements {
		commandStmt, ok := stmt.(*ast.CommandStatement)
		if ok {
			tryEmitLineMarker(sb, commandStmt.Token, enableLineMarkers, inputFilepath)
			sb.WriteString(renderCommandStatement(commandStmt))
		} else {
			labelStmt, ok := stmt.(*ast.LabelStatement)
			if ok {
				// Error if the user-defined label collides with one of the auto-generated
				// chunk or text labels.
				if _, ok := chunkLabels[labelStmt.Name.Value]; ok {
					return parser.NewParseError(labelStmt.Token, fmt.Sprintf("duplicate script label '%s'. Choose a unique label that won't clash with the auto-generated script labels", labelStmt.Name.Value))
				}
				if _, ok := textLabels[labelStmt.Name.Value]; ok {
					return parser.NewParseError(labelStmt.Token, fmt.Sprintf("duplicate text label '%s'. Choose a unique label that won't clash with the auto-generated text labels", labelStmt.Name.Value))
				}
				tryEmitLineMarker(sb, labelStmt.Token, enableLineMarkers, inputFilepath)
				sb.WriteString(renderLabelStatement(labelStmt))
			} else {
				return fmt.Errorf("could not render chunk statement '%q' because it is not a command or label statement", stmt.TokenLiteral())
			}
		}
	}
	return nil
}

func (c *chunk) renderBranching(scriptName string, sb *strings.Builder, nextChunkID int, registerJumpChunk func(int), enableLineMarkers bool, inputFilepath string) bool {
	if c.branchBehavior != nil {
		isFallThrough := c.branchBehavior.renderBranchConditions(sb, scriptName, nextChunkID, registerJumpChunk, enableLineMarkers, inputFilepath)
		return isFallThrough
	}

	// Handle natural return logic that wasn't covered by a branch behavior.
	if c.returnID == -1 {
		sb.WriteString(fmt.Sprintf("\t%s\n", c.getTerminatorCommand()))
		return false
	} else if c.returnID != nextChunkID {
		registerJumpChunk(c.returnID)
		sb.WriteString(fmt.Sprintf("\tgoto %s_%d\n", scriptName, c.returnID))
		return false
	}

	// Fallthrough to next chunk.
	return true
}

func (c *chunk) getTerminatorCommand() string {
	if c.useEndTerminator {
		return "end"
	}
	return "return"
}

func (c *chunk) splitChunkForBranch(statementIndex int, chunkCounter *int, remainingChunks []*chunk) ([]*chunk, int) {
	var returnID int
	if c.isLastStatement(statementIndex) {
		// The statement is the last of the current chunk, so it
		// has the same return point as the current chunk.
		returnID = c.returnID
	} else {
		// The statement needs to return to a chunk of logic
		// that occurs directly after it. So, create a new Chunk for
		// that logic.
		*chunkCounter++
		newChunk := c.createPostLogicChunk(*chunkCounter, statementIndex)
		remainingChunks = append(remainingChunks, newChunk)
		returnID = newChunk.id
		c.returnID = newChunk.id
	}
	return remainingChunks, returnID
}

func (c *chunk) isLastStatement(statementIndex int) bool {
	return statementIndex == len(c.statements)-1
}

func (c *chunk) createPostLogicChunk(id int, lastStatementIndex int) *chunk {
	newChunk := &chunk{
		id:         id,
		returnID:   c.returnID,
		statements: c.statements[lastStatementIndex+1:],
	}
	return newChunk
}

func renderCommandStatement(commandStmt *ast.CommandStatement) string {
	var sb strings.Builder
	sb.WriteString(fmt.Sprintf("\t%s", commandStmt.Name.Value))
	if len(commandStmt.Args) > 0 {
		sb.WriteString(fmt.Sprintf(" %s", strings.Join(commandStmt.Args, ", ")))
	}
	sb.WriteString("\n")
	return sb.String()
}

func renderLabelStatement(labelStmt *ast.LabelStatement) string {
	var sb strings.Builder
	if labelStmt.IsGlobal {
		sb.WriteString(fmt.Sprintf("%s::\n", labelStmt.Name.Value))
	} else {
		sb.WriteString(fmt.Sprintf("%s:\n", labelStmt.Name.Value))
	}
	return sb.String()
}
