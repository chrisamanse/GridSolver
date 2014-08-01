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

class GridSolver {
    Grid grid;
    
    int startingRow;
    int startingCol;
    
    int targetRow;
    int targetCol;
    
    void replaceValueAtPointWithValue(int,int,int);
    void drawWaveValue(int);
public:
    GridSolver();
    GridSolver(Grid);
    
    Grid getGrid();
    
    boolean setStartingPoint(int,int);
    boolean setTargetPoint(int,int);
    boolean setNodeAtPoint(int,int);
    
    void drawWaveform();
    
    // Debug
    void logValues();
};


#endif