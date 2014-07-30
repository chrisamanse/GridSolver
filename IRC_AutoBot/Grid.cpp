//
//  Grid.cpp
//  IRC_AutoBot
//
//  Created by Chris Amanse on 7/30/14.
//  Copyright (c) 2014 Joe Christopher Paul Amanse. All rights reserved.
//

#include <stdio.h>
#include "Grid.h"

Grid::Grid() {
    init(3, 3);
}

Grid::Grid(int rows,int cols) {
    init(rows, cols);
}

void Grid::init(int rows, int cols) {
    numberOfRows = rows;
    numberOfCols = cols;
    
    grid = 0;
    
    grid = new int*[rows];
    
    for (int i = 0; i < rows; i++) {
        grid[i] = new int[cols];
    }
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            grid[row][cols] = 0;
        }
    }
}

int Grid::getNumberOfRows() {
    return numberOfRows;
}

int Grid::getNumberOfCols() {
    return numberOfCols;
}

boolean Grid::isValidRowCol(int row, int col) {
    return (row>0 && col>0) && (row<numberOfRows && col<numberOfCols);
}

int Grid::valueAtRowCol(int row, int col) {
    if (isValidRowCol(row, col)) {
        return grid[row][col];
    }
    return 0;
}

boolean Grid::setRowColToValue(int row, int col, int value) {
    if (isValidRowCol(row, col)) {
        grid[row][col] = value;
        return true;
    }
    return false;
}