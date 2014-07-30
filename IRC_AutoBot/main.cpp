//
//  main.cpp
//  IRC_AutoBot
//
//  Created by Chris Amanse on 7/30/14.
//  Copyright (c) 2014 Joe Christopher Paul Amanse. All rights reserved.
//

#include <iostream>
#include "Grid.h"

int main(int argc, const char * argv[])
{
    Grid myGrid = Grid(3,3);
    
    printf("Rows: %i\nCols: %i\n", myGrid.numberOfRows, myGrid.numberOfCols);
    
    myGrid.setRowColToValue(2, 2, 5);
    printf("Value at 2,2: %i\n", myGrid.valueAtRowCol(2, 2));
    return 0;
}

