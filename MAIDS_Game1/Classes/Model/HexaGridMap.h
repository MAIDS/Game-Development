//
//  HexaGridMap.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__HexaGridMap__
#define __MAIDS_Game1__HexaGridMap__

#include <iostream>
#include "cocos2d.h"
#include "HexaGridMapUnit.h"
USING_NS_CC;
using namespace std;

class HexaGridMapListener;

class HexaGridMap : public Node {
public:
    HexaGridMap(int bound, cocos2d::Size size, std::string mapBgPath);
    void setRotate(float rad);
    void setMapListener(HexaGridMapListener* l);
    HexaGridMapListener* getListener();
    
private:
    void setupListener();
    void updateTrajectory();
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouch(cocos2d::Touch *touch, cocos2d::Event *event, int DownOrMove);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    bool isOnEdges(cocos2d::Touch* touch);
    bool isTrajPointLegal(Point p);
    
    HexaGridMapListener* mListener = nullptr;
    HexaGridMapUnit** units = nullptr;
    Node* trajectoryCanvas;
    float rotateRad = 0;
    float ptsMargin;
    cocos2d::Point mapOrigin;
    std::vector<Point> trajectory;
    
};

class HexaGridMapListener {
public:
    virtual void onTrajectoryStart(int action_code, Point p) = 0;
    virtual void onTrajectoryAdded(int action_code, Point p) = 0;
    virtual void onTrajectoryEnded(int action_code, vector<Point> traj) = 0;
};

#endif /* defined(__MAIDS_Game1__HexaGridMap__) */
