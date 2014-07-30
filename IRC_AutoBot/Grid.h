//
//  Grid.h
//  IRC_AutoBot
//
//  Created by Chris Amanse on 7/30/14.
//  Copyright (c) 2014 Joe Christopher Paul Amanse. All rights reserved.
//

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
    
    boolean isValidRowCol(int,int);
    int valueAtRowCol(int,int);
    boolean setRowColToValue(int,int,int);
};