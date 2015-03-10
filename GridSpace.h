//
//  GridSpace.h
//  PupPatrol
//
//  Created by Invocial on 3/6/15.
//
//

#ifndef __PupPatrol__GridSpace__
#define __PupPatrol__GridSpace__

#include <stdio.h>
#include "cocos2d.h"

class GameGrid;
class Tower;

class GridSpace : public cocos2d::Node
{
public:
    GridSpace( GameGrid *gameGrid, int x, int y);
    
    Tower *towerHere; //The tower that is located at this poisition.
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    GameGrid *grid;
    
    int xIndex; // X Index that this space occupies in the gridspace array
    int yIndex; // Y Index that this space occupies in the gridspace array
    
    double gScore; // Pathfinding score, how far the creep must move to get here
    double hScore; // Pathfinding score, estimated distance from here to the goal
    
};

#endif /* defined(__PupPatrol__GridSpace__) */
