//
//  GridSolver.h
//  IRC_AutoBot
//
//  Created by Chris Amanse on 8/1/14.
//  Copyright (c) 2014 Joe Christopher Paul Amanse. All rights reserved.
//

#ifndef GRIDSOLVER_H
#define GRIDSOLVER_H

#include <iostream>
#include "Grid.h"


enum GSMove {
    GSMoveNone = 0,
    GSMoveUp = 1,
    GSMoveRight,
    GSMoveDown,
    GSMoveLeft
};

//typedef GSMovement GSMovement;

class GridSolver {
    Grid grid;
    
    int startingRow;
    int startingCol;
    
    int targetRow;
    int targetCol;
    
    boolean targetFound;
    
    boolean replaceValueAtPointWithValue(int row, int col, int value);
    void drawWaveValue(int number, int& count);
    void drawWaveform();
public:
    GridSolver();
    GridSolver(Grid aGrid);
    
    Grid getGrid();
    
    boolean setStartingPoint(int row, int col);
    boolean setTargetPoint(int row, int col);
    boolean setNodeAtPoint(int row, int col);
    
    GSMove *getMovesFromShortestPathAndGetMaxMoves(int& maxMoves);
    
    // Debug
    void logValues();
};


#endif