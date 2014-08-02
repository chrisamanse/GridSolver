//
//  GridSolver.cpp
//  IRC_AutoBot
//
//  Created by Chris Amanse on 8/1/14.
//  Copyright (c) 2014 Joe Christopher Paul Amanse. All rights reserved.
//

#include "GridSolver.h"

GridSolver::GridSolver() {
    grid = Grid();
}

GridSolver::GridSolver(Grid aGrid) {
    grid = aGrid;
}

Grid GridSolver::getGrid() {
    return grid;
}

boolean GridSolver::setStartingPoint(int row, int col) {
    if (grid.isValidRowCol(row, col)) {
        startingRow = row;
        startingCol = col;
        grid.setRowColToValue(row, col, 1);
        return true;
    }
    return false;
}

boolean GridSolver::setTargetPoint(int row, int col) {
    if (grid.isValidRowCol(row, col)) {
        targetRow = row;
        targetCol = col;
        return true;
    }
    return false;
}

boolean GridSolver::setNodeAtPoint(int row, int col) {
    if (grid.isValidRowCol(row, col)) {
        grid.setRowColToValue(row, col, grid.getArea()+1);
        return true;
    }
    return false;
}

boolean GridSolver::replaceValueAtPointWithValue(int row, int col, int value) {
    if (grid.isValidRowCol(row, col)) {
        if (grid.getValueAtRowCol(row, col) == 0
//            ||
//            (valueAtPoint > value &&
//             valueAtPoint != grid.getArea()+1
//             ) // Unnecessary condition: only necessary condition is when value at point is 0
            ) {
            grid.setRowColToValue(row, col, value);
            
            // Check if target found
            if (targetRow == row && targetCol == col) {
                targetFound = true;
            }
            
            return true;
        }
    }
    return false;
}

void GridSolver::drawWaveValue(int number, int& count) {
    int numberOfRows = grid.getNumberOfRows();
    int numberOfCols = grid.getNumberOfCols();
    
    int previousNumber = number-1;
    
    int currentCount = 0;
    int newCount = 0;
    boolean shouldBreak = false;
    
    for (int row = 0; row < numberOfRows; row++) {
        for (int col = 0; col < numberOfCols; col++) {
            int pointValue = grid.getValueAtRowCol(row, col);
            if (pointValue == previousNumber) {
                
                // Replace values at adjacent and increase count when replaced
                if (replaceValueAtPointWithValue(row+1, col, number)) {
                    newCount++;
                }
                if (replaceValueAtPointWithValue(row, col+1, number) && !targetFound) {
                    newCount++;
                }
                if (replaceValueAtPointWithValue(row-1, col, number) && !targetFound) {
                    newCount++;
                }
                if (replaceValueAtPointWithValue(row, col-1, number) && !targetFound) {
                    newCount++;
                }
                
                // Check if all points found
                currentCount++;
                if (currentCount == count || targetFound) {
                    shouldBreak = true;
                    break;
                }
            }
        }
        if (shouldBreak) {
            break;
        }
    }
    count = newCount;
}

void GridSolver::drawWaveform() {
    int initialCount = 1;
    for (int i = 2; i <= grid.getArea(); i++) {
        drawWaveValue(i, initialCount);
        
        // If target found, dont continue loop
        if (targetFound) {
            break;
        }
    }
}

GSMove * GridSolver::getMoves(int& maxMoves) {
    maxMoves = grid.getValueAtRowCol(targetRow, targetCol)-1;
    GSMove *moves = new GSMove[maxMoves];
    
    int currentRow = targetRow;
    int currentCol = targetCol;
//    GSMove previousMove = GSMoveNone;
    
    for (int currentValue = maxMoves+1; currentValue > 1; currentValue--) {
        // Check adjacents
        if (grid.getValueAtRowCol(currentRow+1, currentCol) < currentValue &&
            grid.getValueAtRowCol(currentRow+1, currentCol) != 0) {
            moves[currentValue-2] = GSMoveDown;
            currentRow++;
        } else if (grid.getValueAtRowCol(currentRow, currentCol+1) < currentValue &&
                   grid.getValueAtRowCol(currentRow, currentCol+1) != 0) {
            moves[currentValue-2] = GSMoveLeft;
            currentCol++;
        } else if (grid.getValueAtRowCol(currentRow-1, currentCol) < currentValue &&
                   grid.getValueAtRowCol(currentRow-1, currentCol) != 0) {
            moves[currentValue-2] = GSMoveUp;
            currentRow--;
        } else if (grid.getValueAtRowCol(currentRow, currentCol-1) < currentValue &&
                   grid.getValueAtRowCol(currentRow, currentCol-1) != 0) {
            moves[currentValue-2] = GSMoveRight;
            currentCol--;
        }
    }
    
    return moves;
}

#pragma mark - Debug

void GridSolver::logValues() {
    int upperBoundCol = grid.getNumberOfCols();
    int maxRow = grid.getNumberOfRows()-1;
    
    printf("\n");
    
    for (int row = maxRow; row>=0; row--) {
        for (int col=0; col < upperBoundCol; col++) {
            printf("%i\t", grid.getValueAtRowCol(row, col));
        }
        printf("\n");
    }
    
    printf("\n");
}