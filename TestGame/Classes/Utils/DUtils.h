//
//  DUtils.h
//  TestGame
//
//  Created by HW Lee on 3/27/15.
//
//

#ifndef __TestGame__DUtils__
#define __TestGame__DUtils__

#include <stdio.h>
#include "cocos2d.h"
#include <iostream>
USING_NS_CC;

class DUtils {
public:
    static Point calPositionWithPoint(float x, float y, float ptsMargin, float phi);
    static Point calPointWithPosition(float x_pos, float y_pos, Point origin, float ptsMargin, float phi);
    static Vec2 rotate(Vec2 vec, float phi);
    static std::string generateNameByPoint(Point pt);
    static Vec2 round(Vec2 vec, float thresh);
    static Vec2 round(Vec2 vec);
    static int calManhattanDistHexaGrid(Point p1, Point p2);
    static int calManhattanDistHexaGrid(Vec2 vec);
    static int getRandomInt(int min, int max);
    static std::string appendString(int n_args, ...);
};

#endif /* defined(__TestGame__DUtils__) */
