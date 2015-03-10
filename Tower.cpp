//
//  Tower.cpp
//  PupPatrol
//
//  Created by Invocial on 3/6/15.
//
//

#include "Tower.h"
#include "Definitions.h"
#include "GameGrid.h"
#include "GridSpace.h"

USING_NS_CC;

Tower::Tower(GameGrid *gameGrid, GridSpace *buildSpace)
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
}
