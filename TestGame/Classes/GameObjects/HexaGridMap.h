//
//  HexaGridMap.h
//  TestGame
//
//  Created by HW Lee on 3/27/15.
//
//

#ifndef __TestGame__HexaGridMap__
#define __TestGame__HexaGridMap__

#include <iostream>
#include "cocos2d.h"
#include "HexaGridUnit.h"
#include "MapActionListener.h"

class HexaGridMap : public cocos2d::Node {
public:
    /*
    HexaGridMap(int* bounds, int count, cocos2d::Size size);
    HexaGridMap(Point* bounds, int count, cocos2d::Size size);
    */
    HexaGridMap(int bound, cocos2d::Size size);
    void setMapActionListener(MapActionListener* lisener);
    void setRotate(float rad);
    MapActionListener* getMapActionListenter();
    
    
private:
    MapActionListener* mListner = NULL;
    HexaGridUnit** units = NULL;
    cocos2d::Node* trajectoryCanvas;
    float rotateRad = 0;
    float ptsMargin;
    cocos2d::Point mapOrigin;
    int* mBound;
    std::vector<Point> trajectory;
    int mBoundCount = -1;
    int boundsType = -1;
    enum {
        VECTOR_INT_,
        VECTOR_PTS_,
        CONSTANT
    };
    void setupListener();
    void updateTrajectory();
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouch(cocos2d::Touch *touch, cocos2d::Event *event, int DownOrMove);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    bool isOnEdges(cocos2d::Touch* touch);
};

#endif /* defined(__TestGame__HexaGridMap__) */
