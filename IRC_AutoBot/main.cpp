//
//  main.cpp
//  IRC_AutoBot
//
//  Created by Chris Amanse on 7/30/14.
//  Copyright (c) 2014 Joe Christopher Paul Amanse. All rights reserved.
//

#include <iostream>

#include "Grid.h"
#include "GridSolver.h"

int main(int argc, const char * argv[])
{
    // Creating a Grid
    Grid myGrid = Grid(4,4);
    
    // Getting properties of grid
    printf("Rows: %i\nCols: %i\n", myGrid.getNumberOfRows(), myGrid.getNumberOfCols());
    
    printf("Value at 2,2: %i\n", myGrid.getValueAtRowCol(2, 2));
    
    // Solve grid by using created Grid (By creating a GridSolver object)
    GridSolver myGridSolver = GridSolver(myGrid);
    
    // Set properties of grid solver
    myGridSolver.setStartingPoint(0, 0);
    myGridSolver.setTargetPoint(2, 2);
    
    // Nodes are invalid points
    myGridSolver.setNodeAtPoint(2, 1);
    myGridSolver.setNodeAtPoint(1, 2);
    myGridSolver.setNodeAtPoint(2, 3);
    
    myGridSolver.drawWaveform();
    
    myGridSolver.logValues();
    
    return 0;
}