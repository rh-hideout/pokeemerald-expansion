package emitter

import (
	"errors"
	"fmt"
	"sort"
	"strings"

	"github.com/huderlem/poryscript/ast"
	"github.com/huderlem/poryscript/token"
)

// Emitter is responsible for transforming a parsed Poryscript program into
// the target assembler bytecode script.
type Emitter struct {
	program           *ast.Program
	optimize          bool
	enableLineMarkers bool
	inputFilepath     string
}

// New creates a new Poryscript program emitter.
func New(program *ast.Program, optimize, enableLineMarkers bool, inputFilepath string) *Emitter {
	return &Emitter{
		program:           program,
		optimize:          optimize,
		enableLineMarkers: enableLineMarkers,
		inputFilepath:     inputFilepath,
	}
}

// Emit the target assembler bytecode script.
func (e *Emitter) Emit() (string, error) {
	var sb strings.Builder

	// Build a collection of text labels for error-reporting purposes.
	textLabels := map[string]struct{}{}
	for _, text := range e.program.Texts {
		textLabels[text.Name] = struct{}{}
	}

	i := 0
	for _, stmt := range e.program.TopLevelStatements {
		_, ok := stmt.(*ast.TextStatement)
		if ok {
			// Text is rendered separately after the other statements are rendered.
			continue
		}

		// Separate statements with newline.
		if i > 0 {
			sb.WriteString("\n")
		}

		mapScriptsStmt, ok := stmt.(*ast.MapScriptsStatement)
		if ok {
			output, err := e.emitMapScriptStatement(mapScriptsStmt, textLabels)
			if err != nil {
				return "", err
			}
			sb.WriteString(output)
			i++
			continue
		}

		scriptStmt, ok := stmt.(*ast.ScriptStatement)
		if ok {
			output, err := e.emitScriptStatement(scriptStmt, textLabels)
			if err != nil {
				return "", err
			}
			sb.WriteString(output)
			i++
			continue
		}

		rawStmt, ok := stmt.(*ast.RawStatement)
		if ok {
			sb.WriteString(e.emitRawStatement(rawStmt))
			i++
			continue
		}

		movementStmt, ok := stmt.(*ast.MovementStatement)
		if ok {
			sb.WriteString(e.emitMovementStatement(movementStmt))
			i++
			continue
		}

		martStmt, ok := stmt.(*ast.MartStatement)
		if ok {
			sb.WriteString(e.emitMartStatement(martStmt))
			i++
			continue
		}

		return "", fmt.Errorf("could not emit unrecognized top-level statement '%s'", stmt.TokenLiteral())
	}

	for j, text := range e.program.Texts {
		if i+j > 0 {
			sb.WriteString("\n")
		}

		emitted := e.emitText(text)
		sb.WriteString(emitted)
	}
	return sb.String(), nil
}

func (e *Emitter) emitMapScriptStatement(mapScriptStmt *ast.MapScriptsStatement, textLabels map[string]struct{}) (string, error) {
	var sb strings.Builder
	if mapScriptStmt.Scope == token.GLOBAL {
		sb.WriteString(fmt.Sprintf("%s::\n", mapScriptStmt.Name.Value))
	} else {
		sb.WriteString(fmt.Sprintf("%s:\n", mapScriptStmt.Name.Value))
	}
	for _, mapScript := range mapScriptStmt.MapScripts {
		tryEmitLineMarker(&sb, mapScript.Type, e.enableLineMarkers, e.inputFilepath)
		sb.WriteString(fmt.Sprintf("\tmap_script %s, %s\n", mapScript.Type.Literal, mapScript.Name))
	}
	for _, tableMapScript := range mapScriptStmt.TableMapScripts {
		tryEmitLineMarker(&sb, tableMapScript.Type, e.enableLineMarkers, e.inputFilepath)
		sb.WriteString(fmt.Sprintf("\tmap_script %s, %s\n", tableMapScript.Type.Literal, tableMapScript.Name))
	}
	sb.WriteString("\t.byte 0\n\n")

	for _, mapScript := range mapScriptStmt.MapScripts {
		if mapScript.Script != nil {
			scriptOutput, err := e.emitScriptStatement(mapScript.Script, textLabels)
			if err != nil {
				return "", err
			}
			sb.WriteString(scriptOutput)
		}
	}
	for _, tableMapScript := range mapScriptStmt.TableMapScripts {
		sb.WriteString(fmt.Sprintf("%s:\n", tableMapScript.Name))
		for _, scriptEntry := range tableMapScript.Entries {
			tryEmitLineMarker(&sb, scriptEntry.Condition, e.enableLineMarkers, e.inputFilepath)
			sb.WriteString(fmt.Sprintf("\tmap_script_2 %s, %s, %s\n", scriptEntry.Condition.Literal, scriptEntry.Comparison, scriptEntry.Name))
		}
		sb.WriteString("\t.2byte 0\n\n")
		for _, scriptEntry := range tableMapScript.Entries {
			if scriptEntry.Script != nil {
				scriptOutput, err := e.emitScriptStatement(scriptEntry.Script, textLabels)
				if err != nil {
					return "", err
				}
				sb.WriteString(scriptOutput)
			}
		}
	}

	return sb.String(), nil
}

func (e *Emitter) emitScriptStatement(scriptStmt *ast.ScriptStatement, textLabels map[string]struct{}) (string, error) {
	// The algorithm for emitting script statements is to split the scripts into
	// self-contained chunks that logically branch to one another. When branching logic
	// occurs, create a new chunk for any shared logic that follows the branching, as well
	// as new chunks for the destination of the branching logic. When creating and processing
	// new chunks, it's important to remember where the chunks should return to.
	chunkCounter := 0
	finalChunks := make(map[int]*chunk)
	remainingChunks := []*chunk{
		{id: chunkCounter, returnID: -1, statements: scriptStmt.Body.Statements[:]},
	}
	breakStatementReturnChunks := make(map[ast.Statement]int)
	breakStatementOriginChunks := make(map[ast.Statement]int)
	for len(remainingChunks) > 0 {
		// Grab an unprocessed script chunk.
		curChunk := remainingChunks[0]
		remainingChunks = remainingChunks[1:]

		// Skip over basic command and label statements.
		i := 0
		shouldContinue := false
		for _, stmt := range curChunk.statements {
			_, ok := stmt.(*ast.LabelStatement)
			if ok {
				i++
				continue
			}

			commandStmt, ok := stmt.(*ast.CommandStatement)
			if !ok {
				break
			}
			// "end" and "return" are special control-flow commands that end execution of
			// the current logic scope. Since labels could occur after these commands in the
			// current chunk, we only finalize the chunk when these commands are the last
			// command of the current chunk. Otherwise, it would would cause the elimination
			// of any forthcoming labels in this chunk's statements.
			if i == len(curChunk.statements)-1 && (commandStmt.Name.Value == "end" || commandStmt.Name.Value == "return") {
				completeChunk := &chunk{
					id:               curChunk.id,
					returnID:         -1,
					useEndTerminator: commandStmt.Name.Value == "end",
					statements:       curChunk.statements[:i],
				}
				finalChunks[completeChunk.id] = completeChunk
				shouldContinue = true
				break
			}
			i++
		}
		if shouldContinue {
			continue
		}

		if i == len(curChunk.statements) {
			// Finalize a new chunk, if we reached the end of the statements.
			finalChunks[curChunk.id] = curChunk
			continue
		}

		// Create new chunks from if statement blocks.
		if stmt, ok := curChunk.statements[i].(*ast.IfStatement); ok {
			newRemainingChunks, ifBranch := createIfStatementChunks(stmt, i, curChunk, remainingChunks, &chunkCounter)
			remainingChunks = newRemainingChunks
			completeChunk := &chunk{
				id:             curChunk.id,
				returnID:       curChunk.returnID,
				statements:     curChunk.statements[:i],
				branchBehavior: ifBranch,
			}
			finalChunks[completeChunk.id] = completeChunk
		} else if stmt, ok := curChunk.statements[i].(*ast.WhileStatement); ok {
			newRemainingChunks, jump, returnID := createWhileStatementChunks(stmt, i, curChunk, remainingChunks, &chunkCounter)
			remainingChunks = newRemainingChunks
			completeChunk := &chunk{
				id:             curChunk.id,
				returnID:       curChunk.returnID,
				statements:     curChunk.statements[:i],
				branchBehavior: jump,
			}
			finalChunks[completeChunk.id] = completeChunk
			breakStatementReturnChunks[stmt] = returnID
			breakStatementOriginChunks[stmt] = jump.destChunkID
		} else if stmt, ok := curChunk.statements[i].(*ast.DoWhileStatement); ok {
			newRemainingChunks, jump, returnID := createDoWhileStatementChunks(stmt, i, curChunk, remainingChunks, &chunkCounter)
			remainingChunks = newRemainingChunks
			completeChunk := &chunk{
				id:             curChunk.id,
				returnID:       curChunk.returnID,
				statements:     curChunk.statements[:i],
				branchBehavior: jump,
			}
			finalChunks[completeChunk.id] = completeChunk
			breakStatementReturnChunks[stmt] = returnID
			breakStatementOriginChunks[stmt] = jump.destChunkID
		} else if stmt, ok := curChunk.statements[i].(*ast.BreakStatement); ok {
			destChunkID, ok := breakStatementReturnChunks[stmt.ScopeStatment]
			if !ok {
				return "", errors.New("could not emit 'break' statement because its return point is unknown")
			}
			completeChunk := &chunk{
				id:             curChunk.id,
				returnID:       curChunk.returnID,
				statements:     curChunk.statements[:i],
				branchBehavior: &breakContext{destChunkID: destChunkID},
			}
			finalChunks[completeChunk.id] = completeChunk
		} else if stmt, ok := curChunk.statements[i].(*ast.ContinueStatement); ok {
			destChunkID, ok := breakStatementOriginChunks[stmt.LoopStatment]
			if !ok {
				return "", errors.New("could not emit 'continue' statement because its return point is unknown")
			}
			completeChunk := &chunk{
				id:             curChunk.id,
				returnID:       curChunk.returnID,
				statements:     curChunk.statements[:i],
				branchBehavior: &breakContext{destChunkID: destChunkID},
			}
			finalChunks[completeChunk.id] = completeChunk
		} else if stmt, ok := curChunk.statements[i].(*ast.SwitchStatement); ok {
			newRemainingChunks, jump, returnID := createSwitchStatementChunks(stmt, i, curChunk, remainingChunks, &chunkCounter)
			remainingChunks = newRemainingChunks
			completeChunk := &chunk{
				id:             curChunk.id,
				returnID:       curChunk.returnID,
				statements:     curChunk.statements[:i],
				branchBehavior: jump,
			}
			finalChunks[completeChunk.id] = completeChunk
			breakStatementReturnChunks[stmt] = returnID
			breakStatementOriginChunks[stmt] = jump.destChunkID
		} else {
			completeChunk := &chunk{
				id:         curChunk.id,
				returnID:   curChunk.returnID,
				statements: curChunk.statements[:i],
			}
			finalChunks[completeChunk.id] = completeChunk
		}
	}

	return e.renderChunks(finalChunks, scriptStmt.Name.Value, scriptStmt.Scope == token.GLOBAL, textLabels)
}

func createConditionDestination(destinationChunk int, operatorExpression *ast.OperatorExpression) *conditionDestination {
	return &conditionDestination{
		id:                 destinationChunk,
		operatorExpression: operatorExpression,
	}
}

func createIfStatementChunks(stmt *ast.IfStatement, i int, curChunk *chunk, remainingChunks []*chunk, chunkCounter *int) ([]*chunk, *jump) {
	remainingChunks, returnID := curChunk.splitChunkForBranch(i, chunkCounter, remainingChunks)

	*chunkCounter++
	consequenceChunk := &chunk{
		id:         *chunkCounter,
		returnID:   returnID,
		statements: stmt.Consequence.Body.Statements,
	}
	remainingChunks = append(remainingChunks, consequenceChunk)

	elifChunks := []*chunk{}
	for _, elifStmt := range stmt.ElifConsequences {
		*chunkCounter++
		elifChunk := &chunk{
			id:         *chunkCounter,
			returnID:   returnID,
			statements: elifStmt.Body.Statements,
		}
		remainingChunks = append(remainingChunks, elifChunk)
		elifChunks = append(elifChunks, elifChunk)
	}

	var elseChunk *chunk
	if stmt.ElseConsequence != nil {
		*chunkCounter++
		elseChunk = &chunk{
			id:         *chunkCounter,
			returnID:   returnID,
			statements: stmt.ElseConsequence.Statements,
		}
		remainingChunks = append(remainingChunks, elseChunk)
	}

	// Stitch together the return ids for the cascading if statements in reverse order.
	prevElifEntryID := -1
	if len(elifChunks) > 0 {
		for i := len(elifChunks) - 1; i >= 0; i-- {
			if i == len(elifChunks)-1 {
				if elseChunk != nil {
					remainingChunks, _, prevElifEntryID = splitBooleanExpressionChunks(stmt.ElifConsequences[i].Expression, chunkCounter, elifChunks[i].id, elseChunk.id, remainingChunks, -1)
				} else {
					remainingChunks, _, prevElifEntryID = splitBooleanExpressionChunks(stmt.ElifConsequences[i].Expression, chunkCounter, elifChunks[i].id, returnID, remainingChunks, -1)
				}
			} else {
				remainingChunks, _, prevElifEntryID = splitBooleanExpressionChunks(stmt.ElifConsequences[i].Expression, chunkCounter, elifChunks[i].id, prevElifEntryID, remainingChunks, -1)
			}
		}
	}

	var initialEntryChunkID int
	if len(elifChunks) > 0 {
		remainingChunks, _, initialEntryChunkID = splitBooleanExpressionChunks(stmt.Consequence.Expression, chunkCounter, consequenceChunk.id, prevElifEntryID, remainingChunks, -1)
	} else if elseChunk != nil {
		remainingChunks, _, initialEntryChunkID = splitBooleanExpressionChunks(stmt.Consequence.Expression, chunkCounter, consequenceChunk.id, elseChunk.id, remainingChunks, -1)
	} else {
		remainingChunks, _, initialEntryChunkID = splitBooleanExpressionChunks(stmt.Consequence.Expression, chunkCounter, consequenceChunk.id, returnID, remainingChunks, -1)
	}

	return remainingChunks, &jump{destChunkID: initialEntryChunkID}
}

func splitBooleanExpressionChunks(expression ast.BooleanExpression, chunkCounter *int, successChunkID int, failureChunkID int, remainingChunks []*chunk, firstID int) ([]*chunk, *chunk, int) {
	if operatorExpression, ok := expression.(*ast.OperatorExpression); ok {
		dest := createConditionDestination(successChunkID, operatorExpression)
		*chunkCounter++
		newChunk := &chunk{
			id:             *chunkCounter,
			statements:     []ast.Statement{},
			branchBehavior: &leafExpressionBranch{truthyDest: dest, falseyReturnID: failureChunkID, preambleStatement: operatorExpression.PreambleStatement},
		}
		remainingChunks = append(remainingChunks, newChunk)
		if firstID == -1 {
			firstID = newChunk.id
		}
		return remainingChunks, newChunk, firstID
	}

	if binaryExpression, ok := expression.(*ast.BinaryExpression); ok {
		if binaryExpression.Operator == token.AND {
			*chunkCounter++
			successChunk := &chunk{
				id:         *chunkCounter,
				statements: []ast.Statement{},
			}
			var linkChunk *chunk
			var leftLink *chunk
			remainingChunks, leftLink, firstID = splitBooleanExpressionChunks(binaryExpression.Left, chunkCounter, successChunk.id, failureChunkID, remainingChunks, firstID)
			remainingChunks, linkChunk, firstID = splitBooleanExpressionChunks(binaryExpression.Right, chunkCounter, successChunkID, failureChunkID, remainingChunks, firstID)
			successChunk.branchBehavior = &jump{destChunkID: linkChunk.id}
			remainingChunks = append(remainingChunks, successChunk)
			return remainingChunks, leftLink, firstID
		} else if binaryExpression.Operator == token.OR {
			*chunkCounter++
			failChunk := &chunk{
				id:         *chunkCounter,
				statements: []ast.Statement{},
			}
			var linkChunk *chunk
			var leftLink *chunk
			remainingChunks, leftLink, firstID = splitBooleanExpressionChunks(binaryExpression.Left, chunkCounter, successChunkID, failChunk.id, remainingChunks, firstID)
			remainingChunks, linkChunk, firstID = splitBooleanExpressionChunks(binaryExpression.Right, chunkCounter, successChunkID, failureChunkID, remainingChunks, firstID)
			failChunk.branchBehavior = &jump{destChunkID: linkChunk.id}
			remainingChunks = append(remainingChunks, failChunk)
			return remainingChunks, leftLink, firstID
		}
	}

	return remainingChunks, nil, firstID
}

func createWhileStatementChunks(stmt *ast.WhileStatement, i int, curChunk *chunk, remainingChunks []*chunk, chunkCounter *int) ([]*chunk, *jump, int) {

	remainingChunks, returnID := curChunk.splitChunkForBranch(i, chunkCounter, remainingChunks)

	*chunkCounter++
	headerChunk := &chunk{
		id:         *chunkCounter,
		returnID:   returnID,
		statements: []ast.Statement{},
	}

	*chunkCounter++
	consequenceChunk := &chunk{
		id:         *chunkCounter,
		returnID:   headerChunk.id,
		statements: stmt.Consequence.Body.Statements,
	}

	if stmt.Consequence.Expression == nil {
		// Infinite while loop.
		headerChunk.branchBehavior = &jump{destChunkID: consequenceChunk.id}
	} else {
		var entryChunkID int
		remainingChunks, _, entryChunkID = splitBooleanExpressionChunks(stmt.Consequence.Expression, chunkCounter, consequenceChunk.id, returnID, remainingChunks, -1)
		headerChunk.branchBehavior = &jump{destChunkID: entryChunkID}
	}
	remainingChunks = append(remainingChunks, consequenceChunk)
	remainingChunks = append(remainingChunks, headerChunk)

	return remainingChunks, &jump{destChunkID: headerChunk.id}, returnID
}

func createDoWhileStatementChunks(stmt *ast.DoWhileStatement, i int, curChunk *chunk, remainingChunks []*chunk, chunkCounter *int) ([]*chunk, *jump, int) {
	remainingChunks, returnID := curChunk.splitChunkForBranch(i, chunkCounter, remainingChunks)

	*chunkCounter++
	headerChunk := &chunk{
		id:         *chunkCounter,
		returnID:   returnID,
		statements: []ast.Statement{},
	}

	*chunkCounter++
	consequenceChunk := &chunk{
		id:         *chunkCounter,
		returnID:   headerChunk.id,
		statements: stmt.Consequence.Body.Statements,
	}

	var entryChunkID int
	remainingChunks, _, entryChunkID = splitBooleanExpressionChunks(stmt.Consequence.Expression, chunkCounter, consequenceChunk.id, returnID, remainingChunks, -1)
	headerChunk.branchBehavior = &jump{destChunkID: entryChunkID}
	remainingChunks = append(remainingChunks, consequenceChunk)
	remainingChunks = append(remainingChunks, headerChunk)

	return remainingChunks, &jump{destChunkID: consequenceChunk.id}, returnID
}

func createSwitchStatementChunks(stmt *ast.SwitchStatement, statementIndex int, curChunk *chunk, remainingChunks []*chunk, chunkCounter *int) ([]*chunk, *jump, int) {
	remainingChunks, returnID := curChunk.splitChunkForBranch(statementIndex, chunkCounter, remainingChunks)

	*chunkCounter++
	switchChunk := &chunk{
		id:       *chunkCounter,
		returnID: returnID,
	}
	remainingChunks = append(remainingChunks, switchChunk)

	branchBehavior := &switchBranch{operand: stmt.Operand}
	branchCases := []*switchCaseBranch{}
	i := 0
	processedDefaultCase := false
	for i < len(stmt.Cases) {
		switchCase := stmt.Cases[i]
		destChunkID := -1
		if len(switchCase.Body.Statements) > 0 {
			*chunkCounter++
			caseChunk := &chunk{
				id:         *chunkCounter,
				returnID:   returnID,
				statements: switchCase.Body.Statements,
			}
			remainingChunks = append(remainingChunks, caseChunk)
			destChunkID = caseChunk.id
			if switchCase.IsDefault {
				branchBehavior.defaultCase = &switchCaseBranch{
					comparisonValue: stmt.DefaultCase.Value,
					destChunkID:     caseChunk.id,
				}
				processedDefaultCase = true
			}
		} else {
			// Scan forward for the shared case body.
			for j := i + 1; j < len(stmt.Cases); j++ {
				if len(stmt.Cases[j].Body.Statements) > 0 {
					*chunkCounter++
					caseChunk := &chunk{
						id:         *chunkCounter,
						returnID:   returnID,
						statements: stmt.Cases[j].Body.Statements,
					}
					remainingChunks = append(remainingChunks, caseChunk)
					destChunkID = caseChunk.id
					if stmt.Cases[j].IsDefault {
						branchBehavior.defaultCase = &switchCaseBranch{
							comparisonValue: stmt.DefaultCase.Value,
							destChunkID:     caseChunk.id,
						}
						processedDefaultCase = true
					}

					// Apply this chunk body to all of the previous shared cases.
					for i < j {
						if stmt.Cases[i].IsDefault {
							defaultChunk := &chunk{
								id:         *chunkCounter,
								returnID:   returnID,
								statements: stmt.Cases[j].Body.Statements,
							}
							remainingChunks = append(remainingChunks, defaultChunk)
							branchBehavior.defaultCase = &switchCaseBranch{
								comparisonValue: stmt.DefaultCase.Value,
								destChunkID:     destChunkID,
							}
							processedDefaultCase = true
						} else {
							branchCases = append(branchCases, &switchCaseBranch{
								comparisonValue: stmt.Cases[i].Value,
								destChunkID:     destChunkID,
							})
						}
						i++
					}
					break
				}
			}
		}
		if destChunkID == -1 {
			// If we're here, it means that there was no body for the last case(s).
			// This is syntactically fine, but if there are no other switch cases with
			// bodies, we want to completely omit even rendering the switch statement because
			// it's a no-op. By early-returning here, we avoid adding the switch branchBehavior,
			// which will result in the switch not being rendered in the output.
			if len(branchCases) == 0 {
				return remainingChunks, &jump{destChunkID: switchChunk.id}, returnID
			}
		} else if !stmt.Cases[i].IsDefault {
			branchCases = append(branchCases, &switchCaseBranch{
				comparisonValue: stmt.Cases[i].Value,
				destChunkID:     destChunkID,
			})
		}
		i++
	}

	branchBehavior.cases = branchCases
	if !processedDefaultCase {
		branchBehavior.destChunkID = returnID
	}
	switchChunk.branchBehavior = branchBehavior
	return remainingChunks, &jump{destChunkID: switchChunk.id}, returnID
}

func (e *Emitter) renderChunks(chunks map[int]*chunk, scriptName string, isGlobal bool, textLabels map[string]struct{}) (string, error) {
	// Get sorted list of final chunk ids.
	var chunkIDs []int
	if e.optimize {
		chunkIDs = optimizeChunkOrder(chunks)
	} else {
		chunkIDs = make([]int, 0)
		for k := range chunks {
			chunkIDs = append(chunkIDs, k)
		}
		sort.Ints(chunkIDs)
	}

	// Build a collection of chunk labels for error-reporting purposes.
	chunkLabels := map[string]struct{}{}
	for _, chunk := range chunks {
		chunkLabels[chunk.getLabel(scriptName)] = struct{}{}
	}

	// First, render the bodies of each chunk. We'll
	// render the actual chunk labels after, since there is
	// an opportunity to skip renering unnecessary labels.
	var nextChunkID int
	chunkBodies := make(map[int]*strings.Builder)
	jumpChunks := make(map[int]bool)
	registerJumpChunk := func(chunkID int) {
		jumpChunks[chunkID] = true
	}
	for i, chunkID := range chunkIDs {
		var sb strings.Builder
		chunkBodies[chunkID] = &sb
		if i < len(chunkIDs)-1 {
			nextChunkID = chunkIDs[i+1]
		} else {
			nextChunkID = -1
		}
		chunk := chunks[chunkID]
		err := chunk.renderStatements(&sb, chunkLabels, textLabels, e.enableLineMarkers, e.inputFilepath)
		if err != nil {
			return "", err
		}
		isFallThrough := chunk.renderBranching(scriptName, &sb, nextChunkID, registerJumpChunk, e.enableLineMarkers, e.inputFilepath)
		if !isFallThrough {
			sb.WriteString("\n")
		}
	}

	// Render the labels of each chunk, followed by its body.
	// A label doesn't need to be rendered if nothing ever jumps
	// to it.
	var sb strings.Builder
	for _, chunkID := range chunkIDs {
		chunk := chunks[chunkID]
		if chunkID == 0 || jumpChunks[chunkID] {
			chunk.renderLabel(scriptName, isGlobal, &sb)
		}
		sb.WriteString(chunkBodies[chunkID].String())
	}

	return sb.String(), nil
}

// Reorders chunks to take advantage of fall-throughs, rather than using
// unncessary wasteful "goto" commands.
func optimizeChunkOrder(chunks map[int]*chunk) []int {
	unvisited := make(map[int]bool)
	for k := range chunks {
		unvisited[k] = true
	}

	chunkIDs := make([]int, 0)
	if len(chunks) == 0 {
		return chunkIDs
	}

	chunkIDs = append(chunkIDs, 0)
	delete(unvisited, 0)
	i := 1
	for len(chunkIDs) < len(chunks) {
		curChunk := chunks[chunkIDs[len(chunkIDs)-1]]
		var nextChunkID int
		if curChunk.branchBehavior != nil {
			nextChunkID = curChunk.branchBehavior.getTailChunkID()
		} else {
			nextChunkID = curChunk.returnID
		}

		if nextChunkID != -1 {
			if _, ok := unvisited[nextChunkID]; ok {
				chunkIDs = append(chunkIDs, nextChunkID)
				delete(unvisited, nextChunkID)
				continue
			}
		}

		// Choose random unvisited chunk for the next one.
		for i < len(chunks) {
			_, ok := unvisited[i]
			if ok {
				chunkIDs = append(chunkIDs, i)
				delete(unvisited, i)
				break
			}
			i++
		}
	}
	return chunkIDs
}

func shouldEmitLineMarkers(enableLineMarkers bool, inputFilepath string) bool {
	return enableLineMarkers && len(inputFilepath) > 0
}

func emitLineMarker(sb *strings.Builder, lineNumber int, inputFilepath string) {
	sb.WriteString(fmt.Sprintf("# %d \"%s\"\n", lineNumber, strings.ReplaceAll(inputFilepath, `\`, `\\`)))
}

func tryEmitLineMarker(sb *strings.Builder, tok token.Token, enableLineMarkers bool, inputFilepath string) {
	if !shouldEmitLineMarkers(enableLineMarkers, inputFilepath) {
		return
	}
	emitLineMarker(sb, tok.LineNumber, inputFilepath)
}

func (e *Emitter) emitText(text ast.Text) string {
	var sb strings.Builder
	if text.IsGlobal {
		sb.WriteString(fmt.Sprintf("%s::\n", text.Name))
	} else {
		sb.WriteString(fmt.Sprintf("%s:\n", text.Name))
	}
	tryEmitLineMarker(&sb, text.Token, e.enableLineMarkers, e.inputFilepath)
	lines := strings.Split(text.Value, "\n")
	for _, line := range lines {
		directive := "string"
		if len(text.StringType) > 0 {
			directive = text.StringType
		}
		sb.WriteString(fmt.Sprintf("\t.%s \"%s\"\n", directive, line))
	}
	return sb.String()
}

func (e *Emitter) emitRawStatement(rawStmt *ast.RawStatement) string {
	var sb strings.Builder
	if shouldEmitLineMarkers(e.enableLineMarkers, e.inputFilepath) {
		lines := strings.Split(rawStmt.Value, "\n")
		for i, line := range lines {
			emitLineMarker(&sb, rawStmt.Token.LineNumber+i, e.inputFilepath)
			sb.WriteString(fmt.Sprintf("%s\n", line))
		}
	} else {
		sb.WriteString(fmt.Sprintf("%s\n", rawStmt.Value))
	}
	return sb.String()
}

func (e *Emitter) emitMovementStatement(movementStmt *ast.MovementStatement) string {
	terminator := "step_end"
	var sb strings.Builder
	tryEmitLineMarker(&sb, movementStmt.Token, e.enableLineMarkers, e.inputFilepath)
	if movementStmt.Scope == token.GLOBAL {
		sb.WriteString(fmt.Sprintf("%s::\n", movementStmt.Name.Value))
	} else {
		sb.WriteString(fmt.Sprintf("%s:\n", movementStmt.Name.Value))
	}
	for _, cmd := range movementStmt.MovementCommands {
		tryEmitLineMarker(&sb, cmd, e.enableLineMarkers, e.inputFilepath)
		sb.WriteString(fmt.Sprintf("\t%s\n", cmd.Literal))
		if cmd.Literal == terminator {
			return sb.String()
		}
	}
	sb.WriteString(fmt.Sprintf("\t%s\n", terminator))
	return sb.String()
}

func (e *Emitter) emitMartStatement(martStmt *ast.MartStatement) string {
	terminator := "ITEM_NONE"
	var sb strings.Builder
	sb.WriteString("\t.align 2\n")
	tryEmitLineMarker(&sb, martStmt.Token, e.enableLineMarkers, e.inputFilepath)
	if martStmt.Scope == token.GLOBAL {
		sb.WriteString(fmt.Sprintf("%s::\n", martStmt.Name.Value))
	} else {
		sb.WriteString(fmt.Sprintf("%s:\n", martStmt.Name.Value))
	}
	for i, item := range martStmt.Items {
		if item == terminator {
			break
		}
		tryEmitLineMarker(&sb, martStmt.TokenItems[i], e.enableLineMarkers, e.inputFilepath)
		sb.WriteString(fmt.Sprintf("\t.2byte %s\n", item))
	}
	sb.WriteString(fmt.Sprintf("\t.2byte %s\n", terminator))
	return sb.String()
}
