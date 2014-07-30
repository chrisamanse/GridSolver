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

int Grid::valueAtRowCol(int row, int col) {
    return grid[row][col];
}

boolean Grid::setRowColToValue(int row, int col, int value) {
    if (row < numberOfRows && col <numberOfCols) {
        grid[row][col] = value;
        return true;
    }
    return false;
}