//
//  Creep.cpp
//  PupPatrol
//
//  Created by Invocial on 3/6/15.
//
//

#include "Creep.h"
#include "Definitions.h"
#include "GameGrid.h"
#include "GridSpace.h"
#include "Tower.h"

USING_NS_CC;

Creep::Creep(cocos2d::Layer *layer, GameGrid *grid, GridSpace *spawnSpace)
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    creepSprite = Sprite::create( "cat_forward_1.png");
    creepSprite->setPosition(spawnSpace->getPosition());
    
    layer->addChild(creepSprite, 2);
}