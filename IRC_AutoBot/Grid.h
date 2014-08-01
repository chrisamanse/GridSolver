//
//  Grid.h
//  IRC_AutoBot
//
//  Created by Chris Amanse on 7/30/14.
//  Copyright (c) 2014 Joe Christopher Paul Amanse. All rights reserved.
//

#ifndef GRID_H
#define GRID_H

typedef bool boolean;

class Grid {
    void init(int,int);
    int **grid;
    int numberOfRows;
    int numberOfCols;
public:
    Grid();
    Grid(int,int);
    
    int getNumberOfRows();
    int getNumberOfCols();
    int getArea();
    
    boolean isValidRowCol(int,int);
    int getValueAtRowCol(int,int);
    boolean setRowColToValue(int,int,int);
};

#endif