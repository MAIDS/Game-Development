#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "HexaGridMap.h"
#include <iostream>
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

class TestMapListener : public HexaGridMapListener {
public:
    TestMapListener(HexaGridMap* map) { this->mMap = map; }
    virtual void onTrajectoryStart(int action_code, Point p) override {}
    virtual void onTrajectoryAdded(int action_code, Point p) override {}
    virtual void onTrajectoryEnded(int action_code, std::vector<Point> traj) override;
    
private:
    HexaGridMap* mMap;
    
};

#endif // __HELLOWORLD_SCENE_H__
