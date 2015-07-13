//
//  HexaGridMap.cpp
//  TestGame
//
//  Created by HW Lee on 3/27/15.
//
//

#include "HexaGridMap.h"
#include "cocos2d.h"
#include "DUtils.h"
#include "GUtils.h"
#include "MapActionListener.h"
#include "HexaGridUnit.h"
#include "WuXing.h"
#include <math.h>
#include <iostream>
USING_NS_CC;

#define TOUCH_DOWN 0
#define TOUCH_MOVE 1

/*
HexaGridMap::HexaGridMap(int* bounds, int count, Size size) {
    this->boundsType = this->VECTOR_INT_;
    this->mBoundCount = count;
    this->mBound = new int[count];
    for (int i = 0; i < count; i++)
        this->mBound[i] = bounds[i];
    this->setContentSize(size);
    this->ptsMargin = size.width/10;
}

HexaGridMap::HexaGridMap(Point* bounds, int count, Size size) {
    this->boundsType = this->VECTOR_PTS_;
    this->mBoundCount = count;
    this->mBound = new int[2*count];
    for (int i = 0; i < count; i++) {
        this->mBound[2*i] = bounds[i].x;
        this->mBound[2*i+1] = bounds[i].y;
    }
    this->setContentSize(size);
    this->ptsMargin = size.width/10;
}
*/

HexaGridMap::HexaGridMap(int bound, Size size, std::string mapBgPath) {
    std::cout << DUtils::generateNameByPoint(size) << endl;
    this->boundsType = this->CONSTANT;
    this->mBoundCount = 1;
    this->mBound = new int[1];
    this->mBound[0] = bound;
    this->setContentSize(size);
    this->ptsMargin = size.width/8;
    std::cout << "this->ptsMargin = " << this->ptsMargin << endl;
    this->mapOrigin = Point(this->ptsMargin, this->ptsMargin);
    this->setPosition(this->mapOrigin);
    for (int i = 0; i < bound; i++) {
        for (int j = 0; j < (int)(1.5*bound); j++) {
            auto unit = new HexaGridUnit(this->ptsMargin*0.9);
            
//            auto nodesWuXing = new Sprite*[WuXing::NUM];
//            for (int i = 0; i < WuXing::NUM; i++) nodesWuXing[i] = NULL;
//            nodesWuXing[WuXing::WATER] = Sprite::create("water.png");
//            nodesWuXing[WuXing::FIRE] = Sprite::create("fire.png");
//            nodesWuXing[WuXing::METAL] = Sprite::create("metal.png");
//            nodesWuXing[WuXing::WOOD] = Sprite::create("wood.png");
//            nodesWuXing[WuXing::YIN] = Sprite::create("yin.png");
//            nodesWuXing[WuXing::YANG] = Sprite::create("yang.png");
//            for (int i = 0; i < WuXing::NUM; i++) {
//                auto nodeWuXing = nodesWuXing[i];
//                if (i != WuXing::NONE && i != WuXing::EARTH) {
//                    nodeWuXing->setScale(unit->getContentSize().width/nodeWuXing->getContentSize().width*1.1);
//                    nodeWuXing->setPosition(Vec2(unit->getContentSize().width, unit->getContentSize().width)/2);
//                    unit->setNodeWuXing(nodeWuXing, i);
//                }
//            }

            auto nodeSelected = DrawNode::create();
            GUtils::drawSolidHexagon(nodeSelected,
                                     Point(unit->getContentSize().width, unit->getContentSize().width)/2,
                                     unit->getContentSize().width/sqrtf(3), Color4F(), Color4F(0, 1, 0, .5));
            
            unit->setSelectedMask(nodeSelected);
            unit->setPosition(DUtils::calPositionWithPoint(i, j-i/2, this->ptsMargin, 0)
                              - Vec2(unit->getContentSize().width, unit->getContentSize().width)/2);
            
            this->addChild(unit, 1, DUtils::generateNameByPoint(Point(i, j-i/2)));
        }
    }
    
    auto bgNode = Sprite::create(mapBgPath);
    bgNode->setContentSize(size);
    this->addChild(bgNode, 0);
    
    this->trajectoryCanvas = DrawNode::create();
    this->addChild(this->trajectoryCanvas, 2);
    this->setupListener();
}

void HexaGridMap::setMapActionListener(MapActionListener *lisener) {
    this->mListner = lisener;
}

void HexaGridMap::setRotate(float rad) {
    auto selfSize = this->getContentSize();
    this->rotateRad = rad;
    auto anchor = Vec2(this->mapOrigin.x/selfSize.width, this->mapOrigin.y/selfSize.height);
    this->setRotation(-rad*180/M_PI);
}

void HexaGridMap::setupListener() {
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(HexaGridMap::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HexaGridMap::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(HexaGridMap::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HexaGridMap::updateTrajectory() {
    ((DrawNode*)this->trajectoryCanvas)->clear();
    Point* ptsToDraw = new Point[this->trajectory.size()];
    for (int i = 0; i < this->trajectory.size(); i++) {
        auto name = DUtils::generateNameByPoint(this->trajectory.at(i));
        auto box = this->getChildByName<HexaGridUnit*>(name)->getBoundingBox();
        ptsToDraw[i] = Point(box.getMinX()+box.getMaxX(), box.getMinY()+box.getMaxY())/2;
    }
    for (int i = 1; i < this->trajectory.size(); i++) {
        ((DrawNode*)this->trajectoryCanvas)->drawSegment(ptsToDraw[i-1], ptsToDraw[i], 4, Color4F(.5, .25, .25, 1));
    }
}

bool HexaGridMap::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    this->onTouch(touch, event, TOUCH_DOWN);
    return true;
}

void HexaGridMap::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    this->onTouch(touch, event, TOUCH_MOVE);
}

void HexaGridMap::onTouch(cocos2d::Touch *touch, cocos2d::Event *event, int DownOrMove) {
    auto pts = DUtils::calPointWithPosition(touch->getLocation().x,
                                            touch->getLocation().y,
                                            this->mapOrigin,
                                            this->ptsMargin,
                                            this->rotateRad);
    int inRegionCnt = 0;
    Point inRegionPt;
    for (int i = 0; i < 4; i++) {
        Point testPt((int)pts.x + (i%2) - (pts.x < 0), (int)pts.y + ((i/2)%2) - (pts.y < 0));
        if (this->getChildByName(DUtils::generateNameByPoint(testPt))) {
            auto testUnit = this->getChildByName<HexaGridUnit*>(DUtils::generateNameByPoint(testPt));
            auto touchVec = DUtils::rotate(touch->getLocation()-this->mapOrigin, -this->rotateRad);
            if (testUnit->getBoundingBox().containsPoint(touchVec)) {
                inRegionCnt++;
                inRegionPt = testPt;
            }
            if (inRegionCnt == 2)
                break;
        }
    }
    if (inRegionCnt == 1 && this->getChildByName(DUtils::generateNameByPoint(inRegionPt))) {
        if (DownOrMove == TOUCH_DOWN && this->trajectory.size() == 0) {
            this->getChildByName<HexaGridUnit*>(DUtils::generateNameByPoint(inRegionPt))->selected();
            this->trajectory.push_back(inRegionPt);
        } else if ( (DownOrMove == TOUCH_DOWN || DownOrMove == TOUCH_MOVE) && this->trajectory.size() > 0) {
            if (DUtils::calManhattanDistHexaGrid(inRegionPt, this->trajectory.back()) == 1) {
                if (this->trajectory.size() > 1 && this->trajectory[this->trajectory.size()-2] == inRegionPt) {
                    auto name = DUtils::generateNameByPoint(this->trajectory.back());
                    this->getChildByName<HexaGridUnit*>(name)->unselected();
                    this->trajectory.pop_back();
                } else {
                    auto name = DUtils::generateNameByPoint(inRegionPt);
                    if (!this->getChildByName<HexaGridUnit*>(name)->isSelected()) {
                        this->getChildByName<HexaGridUnit*>(name)->selected();
                        this->trajectory.push_back(inRegionPt);
                    }
                }
                this->updateTrajectory();
            }
        }
    }
}

void HexaGridMap::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {
    if (this->trajectory.size() == 1 || !isOnEdges(touch)) {
        for (auto unitPt : this->trajectory) {
            this->getChildByName<HexaGridUnit*>(DUtils::generateNameByPoint(unitPt))->unselected();
            this->getChildByName<HexaGridUnit*>(DUtils::generateNameByPoint(unitPt))->changeWuXing(Attribute::WATER);
        }
        this->trajectory.clear();
        this->updateTrajectory();
    } else if (this->trajectory.size() > 1 && isOnEdges(touch)) {
        
    }
}

bool HexaGridMap::isOnEdges(cocos2d::Touch *touch) {
    return false;
}
