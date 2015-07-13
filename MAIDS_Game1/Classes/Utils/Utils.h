//
//  Utils.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__Utils__
#define __MAIDS_Game1__Utils__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class Utils {
public:
    /*
     *
     *
     *
     *  Computational Utils
     *
     *
     *
     */
    static Point calPositionWithPoint(float x, float y, float ptsMargin, float phi);
    static Point calPointWithPosition(float x_pos, float y_pos, Point origin, float ptsMargin, float phi);
    static Vec2 rotate(Vec2 vec, float phi);
    static Vec2 round(Vec2 vec, float thresh);
    static Vec2 round(Vec2 vec);
    static int calManhattanDistHexaGrid(Point p1, Point p2);
    static int calManhattanDistHexaGrid(Vec2 vec);
    static int getRandomInt(int min, int max);
    
    /*
     *
     *
     *
     *  String Utils
     *
     *
     *
     */
    static std::string generateNameByPoint(Point pt);
    static std::string appendString(int n_args, ...);
    
    /*
     *
     *
     *
     *  Graphic Utils
     *
     *
     *
     */
    static void drawSolidHexagon(cocos2d::DrawNode* node, cocos2d::Point center, float r,
                                 float phi, cocos2d::Color4F colorFilled, cocos2d::Color4F lineColor);
    static void drawSolidHexagon(cocos2d::DrawNode* node, cocos2d::Point center, float r,
                                 cocos2d::Color4F colorFilled, cocos2d::Color4F lineColor);
};

#endif /* defined(__MAIDS_Game1__Utils__) */
