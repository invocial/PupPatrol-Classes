//
//  GameGrid.h
//  PupPatrol
//
//  Created by Invocial on 3/6/15.
//
//

#ifndef __PupPatrol__GameGrid__
#define __PupPatrol__GameGrid__

#include <stdio.h>
#include "cocos2d.h"
#include "Definitions.h"

class Creep;
class GridSpace;
class Tower;


class GameGrid : public cocos2d::Sprite
{
public:
    GameGrid( cocos2d::Layer *layer );
    
private:
    
    GridSpace* gridSpaceForTouchPosition( cocos2d::Vec2 touchPosition );
    void setupGrid();
    bool onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event );
    bool validSpaceForTower( GridSpace *space );
    bool canConstructValidPathWithout( GridSpace *space );
    
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    cocos2d::Sprite *gridSprite;
    
    GridSpace *gridArray[GRID_ROWS][GRID_COLS]; //Grid Array storing all grid spaces
    
    GridSpace *openSteps[GRID_ROWS * GRID_COLS];       //Open Steps for Pathfinding
    GridSpace *closedSteps[GRID_ROWS * GRID_COLS];     //Closed Steps for Pathfinding
    GridSpace *shortestPath[GRID_ROWS * GRID_COLS];    //Shortest Path found through Pathfinding
    
    GridSpace *spawnSpace;  //Space where units spawn
    GridSpace *goalSpace;   //Space where units are trying to go
    
    Creep *creepVector[MAX_CREEPS];    //Enemy Units in the player's grid
    Tower *towerArray[GRID_ROWS * GRID_COLS];    //Constructed Towers in the player's grid
    
    float cellHeight;
    float cellWidth;
    
    int playerGold;
    int playerIncome;
    
};

#endif /* defined(__PupPatrol__GameGrid__) */
