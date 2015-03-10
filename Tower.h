//
//  Tower.h
//  PupPatrol
//
//  Created by Invocial on 3/6/15.
//
//

#ifndef __PupPatrol__Tower__
#define __PupPatrol__Tower__

#include <stdio.h>
#include "cocos2d.h"

class GameGrid;
class GridSpace;

class Tower : public cocos2d::Node
{
public:
    Tower(GameGrid *gameGrid, GridSpace *buildSpace);
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    GridSpace *space;   //The Location of the tower in the grid
    
};

#endif /* defined(__PupPatrol__Tower__) */
