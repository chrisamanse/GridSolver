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
public:
    Grid();
    Grid(int,int);
    int numberOfRows;
    int numberOfCols;
    int valueAtRowCol(int,int);
    boolean setRowColToValue(int,int,int);
};