//
//  GridSpace.cpp
//  PupPatrol
//
//  Created by Invocial on 3/6/15.
//
//

#include "GridSpace.h"
#include "Definitions.h"
#include "GameGrid.h"
#include "Tower.h"

USING_NS_CC;

GridSpace::GridSpace( GameGrid *gameGrid, int x, int y)
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    grid = gameGrid;
    
    xIndex = x;
    yIndex = y;
}
