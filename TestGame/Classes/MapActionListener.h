//
//  MapActionListener.h
//  TestGame
//
//  Created by HW Lee on 3/27/15.
//
//

#ifndef __TestGame__MapActionListener__
#define __TestGame__MapActionListener__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class MapActionListener {
public:
    virtual void onActionStart() {};
    virtual void onTrajectoryUpdate() {};
    virtual void onActionEnd(int action_code, Point* pts) {};
};

class Action {
public:
    /*
    static const int ACTION_NONE = 0;
    static const int ACTION_ATTACK = 1;
    static const int ACTION_MOVE = 2;
    */
    static const int NONE = 0;
    static const int ATTACK = 1;
    static const int MOVE = 2;
};

#endif /* defined(__TestGame__MapActionListener__) */
