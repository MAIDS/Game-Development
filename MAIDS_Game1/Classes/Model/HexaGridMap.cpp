//
//  HexaGridMap.cpp
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#include "HexaGridMap.h"
#include "cocos2d.h"
#include "Utils.h"
#include "HexaGridMapUnit.h"
#include "Attribute.h"
#include "Constants.h"
#include <math.h>
#include <iostream>
USING_NS_CC;

#define TOUCH_DOWN 0
#define TOUCH_MOVE 1

HexaGridMap::HexaGridMap(int bound, cocos2d::Size size, std::string mapBgPath) {
    this->setContentSize(size);
    this->ptsMargin = size.width/8;
    this->mapOrigin = Point(this->ptsMargin, this->ptsMargin);
    this->setPosition(this->mapOrigin);
    
    for (int i = 0; i < bound; i++) {
        for (int j = 0; j < (int)(1.5*bound); j++) {
            auto unit = new HexaGridMapUnit(this->ptsMargin*0.9);
            auto nodeSelected = DrawNode::create();
            Utils::drawSolidHexagon(nodeSelected,
                                     Point(unit->getContentSize().width, unit->getContentSize().width)/2,
                                     unit->getContentSize().width/sqrtf(3), Color4F(), Color4F(0, 1, 0, .5));
            
            unit->setSelectedMask(nodeSelected);
            unit->setPosition(Utils::calPositionWithPoint(i, j-i/2, this->ptsMargin, 0)
                              - Vec2(unit->getContentSize().width, unit->getContentSize().width)/2);
            
            this->addChild(unit, 1, Utils::generateNameByPoint(Point(i, j-i/2)));
        }
    }
    
    auto bgNode = Sprite::create(mapBgPath);
    bgNode->setContentSize(size);
    this->addChild(bgNode, 0);
    
    this->trajectoryCanvas = DrawNode::create();
    this->addChild(this->trajectoryCanvas, 2);
    this->setupListener();
}

void HexaGridMap::setMapListener(HexaGridMapListener *l) { this->mListener = l; }
HexaGridMapListener* HexaGridMap::getListener() { return this->mListener; }
HexaGridMapUnit* HexaGridMap::getUnitWithPos(cocos2d::Vec2 p) {
    return this->getChildByName<HexaGridMapUnit*>(Utils::generateNameByPoint(p));
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
        auto name = Utils::generateNameByPoint(this->trajectory.at(i));
        auto box = this->getChildByName<HexaGridMapUnit*>(name)->getBoundingBox();
        ptsToDraw[i] = Point(box.getMinX()+box.getMaxX(), box.getMinY()+box.getMaxY())/2;
    }
    for (int i = 1; i < this->trajectory.size(); i++) {
        ((DrawNode*)this->trajectoryCanvas)->drawSegment(ptsToDraw[i-1], ptsToDraw[i], 4, Color4F(.5, .25, .25, 1));
    }
}

//手指放上螢幕
bool HexaGridMap::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    this->onTouch(touch, event, TOUCH_DOWN);
    return true;
}

//移動手指
void HexaGridMap::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    this->onTouch(touch, event, TOUCH_MOVE);
}

void HexaGridMap::onTouch(cocos2d::Touch *touch, cocos2d::Event *event, int DownOrMove) {
    //把螢幕的觸控點轉成六角座標
    auto pts = Utils::calPointWithPosition(touch->getLocation().x,
                                           touch->getLocation().y,
                                           this->mapOrigin,
                                           this->ptsMargin,
                                           this->rotateRad);
    //校正用,為了解ＢＵＧ
    int inRegionCnt = 0;
    Point inRegionPt;
    for (int i = 0; i < 4; i++) {
        Point testPt((int)pts.x + (i%2) - (pts.x < 0), (int)pts.y + ((i/2)%2) - (pts.y < 0));
        if (this->getChildByName(Utils::generateNameByPoint(testPt))) {
            auto testUnit = this->getUnitWithPos(testPt);
            auto touchVec = Utils::rotate(touch->getLocation()-this->mapOrigin, -this->rotateRad);
            if (testUnit->getBoundingBox().containsPoint(touchVec)) {
                inRegionCnt++;
                inRegionPt = testPt;
            }
            if (inRegionCnt == 2)
                break;
        }
    }
    
    //找到方塊了,抓到trajactory上面
    if (inRegionCnt == 1 && this->getChildByName(Utils::generateNameByPoint(inRegionPt))) {
        if (DownOrMove == TOUCH_DOWN && this->trajectory.size() == 0) {
            this->getUnitWithPos(inRegionPt)->selected();
            this->trajectory.push_back(inRegionPt);
        } else if ( (DownOrMove == TOUCH_DOWN || DownOrMove == TOUCH_MOVE) && this->trajectory.size() > 0) {
            if (isTrajPointLegal(inRegionPt)) {
                //偵測有沒有畫回來
                if (this->trajectory.size() > 1 && this->trajectory[this->trajectory.size()-2] == inRegionPt) {
                    auto name = Utils::generateNameByPoint(this->trajectory.back());
                    this->getChildByName<HexaGridMapUnit*>(name)->unselected();
                    this->trajectory.pop_back();
                } else {
                    auto name = Utils::generateNameByPoint(inRegionPt);
                    //can replaced by getUnitWithPos()
                    if (!this->getChildByName<HexaGridMapUnit*>(name)->isSelected()) {
                        this->getChildByName<HexaGridMapUnit*>(name)->selected();
                        this->trajectory.push_back(inRegionPt);
                    }
                }
                this->updateTrajectory();
            }
        }
    }
}

//放開手指
void HexaGridMap::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {
    if (this->trajectory.size() == 1 || !isOnEdges(touch)) {
        for (auto unitPt : this->trajectory) {
            this->getUnitWithPos(unitPt)->unselected();
            if (this->mListener != nullptr)
                this->mListener->onTrajectoryEnded(GameAction::MOVE, this->trajectory);
        }
        this->trajectory.clear();
        this->updateTrajectory();
    } else if (this->trajectory.size() > 1 && isOnEdges(touch)) {
        
    }
}

//邊界移動，待寫
bool HexaGridMap::isOnEdges(cocos2d::Touch *touch) {
    return false;
}

bool HexaGridMap::isTrajPointLegal(Point p) {
    return (Utils::calManhattanDistHexaGrid(p, this->trajectory.back()) == 1);
}
