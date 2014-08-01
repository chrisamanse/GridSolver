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

void GridSolver::replaceValueAtPointWithValue(int row, int col, int value) {
    if (grid.isValidRowCol(row, col)) {
        int valueAtPoint = grid.getValueAtRowCol(row, col);
        
        if (valueAtPoint == 0 ||
            (valueAtPoint > value &&
             valueAtPoint != grid.getArea()+1
             )
            ) {
            grid.setRowColToValue(row, col, value);
        }
    }
}

void GridSolver::drawWaveValue(int number) {
    int numberOfRows = grid.getNumberOfRows();
    int numberOfCols = grid.getNumberOfCols();
    
    int previousNumber = number-1;
    
    for (int row = 0; row < numberOfRows; row++) {
        for (int col = 0; col < numberOfCols; col++) {
            int pointValue = grid.getValueAtRowCol(row, col);
            if (pointValue == previousNumber) {
                // Replace Values at adjacent
                replaceValueAtPointWithValue(row+1, col, number);
                replaceValueAtPointWithValue(row, col+1, number);
                replaceValueAtPointWithValue(row-1, col, number);
                replaceValueAtPointWithValue(row, col-1, number);
            }
        }
    }
}

void GridSolver::drawWaveform() {
    for (int i = 2; i <= grid.getArea(); i++) {
        drawWaveValue(i);
    }
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