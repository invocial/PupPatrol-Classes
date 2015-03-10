//
//  GameGrid.cpp
//  PupPatrol
//
//  Created by Invocial on 3/6/15.
//
//

#include "GameGrid.h"
#include "Definitions.h"
#include "Creep.h"
#include "GridSpace.h"
#include "Tower.h"

USING_NS_CC;

GameGrid::GameGrid( cocos2d::Layer *layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );

    gridSprite = Sprite::create( "GameGrid.png");
    gridSprite->setPosition( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y );
    
    cellHeight = gridSprite->getContentSize().height / GRID_ROWS;
    cellWidth = gridSprite->getContentSize().width / GRID_COLS;
    
    setupGrid();
    
    layer->addChild(this, 100);
    layer->addChild(gridSprite, 1);
    
    auto touchListener = EventListenerTouchOneByOne::create( );
    touchListener->setSwallowTouches( true );
    touchListener->onTouchBegan = CC_CALLBACK_2( GameGrid::onTouchBegan, this );
    Director::getInstance( )->getEventDispatcher( )->addEventListenerWithSceneGraphPriority( touchListener, this );
    
}

void GameGrid::setupGrid()
{
    int heightGap = (visibleSize.height - gridSprite->getContentSize().height) / 2;
    int widthGap = (visibleSize.width - gridSprite->getContentSize().width) / 2;
    
    for(int i = 0; i<GRID_ROWS; i++)
    {
        for (int j = 0; j<GRID_COLS; j++)
        {
            gridArray[i][j] = new GridSpace(this, i, j);
            gridArray[i][j]->setAnchorPoint(Vec2(0.5,0.5));
            gridArray[i][j]->setPosition(Vec2(widthGap + i * cellWidth + cellWidth/2, heightGap + j * cellHeight + cellHeight/2));
        }
    }
    
    spawnSpace = gridArray[GRID_ROWS-1][GRID_COLS-1];
    goalSpace = gridArray[0][0];
}

bool GameGrid::onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event )
{
    touch->getLocation();
    
    GridSpace *space = gridSpaceForTouchPosition(touch->getLocation());
    
    if(space)
    {
        if (validSpaceForTower(space))
        {
            //TODO ADD TOWER HERE
            Tower * tower = new Tower(this, space);
            int i = 3;
        }
    }
    
    return true;
}

bool GameGrid::validSpaceForTower( GridSpace *space )
{
    if(space->towerHere || !(canConstructValidPathWithout(space)))
    {
        return false;
    }
    return true;
}

bool GameGrid::canConstructValidPathWithout( GridSpace *space )
{
    //TODO ADD CODE TO CHECK IF VALID PATH EXISTS
    
    return true;
}

GridSpace* GameGrid::gridSpaceForTouchPosition(cocos2d::Vec2 touchPosition)
{
    int heightGap = (visibleSize.height - gridSprite->getContentSize().height) / 2;
    int widthGap = (visibleSize.width - gridSprite->getContentSize().width) / 2;
    int row = (touchPosition.y - heightGap)/ cellWidth;
    int col = (touchPosition.x - widthGap) / cellHeight;
    
    
    if(row >= 0 && col >= 0 && row < GRID_ROWS && col < GRID_COLS)
    {
        CCLOG("gridarray[%d][%d]", row, col);
        return gridArray[row][col];
    }
    return nullptr;
}
