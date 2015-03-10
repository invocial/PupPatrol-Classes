//
//  Creep.h
//  PupPatrol
//
//  Created by Invocial on 3/6/15.
//
//

#ifndef __PupPatrol__Creep__
#define __PupPatrol__Creep__

#include <stdio.h>
#include "cocos2d.h"

class GameGrid;
class GridSpace;
class Tower;

class Creep : public cocos2d::Node
{
public:
    Creep(cocos2d::Layer *layer, GameGrid *gameGrid, GridSpace *spawnSpace);
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    GameGrid *grid;
    cocos2d::Sprite *creepSprite;
    
    int maxHp;
    int currentHp;
    int bounty;
    float moveSpeed;
    
    Tower *attackedBy;
    
    cocos2d::DrawNode *healthBar;
    
    
};

#endif /* defined(__PupPatrol__Creep__) */
