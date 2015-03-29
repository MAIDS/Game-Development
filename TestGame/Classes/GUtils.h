//
//  GUtils.h
//  TestGame
//
//  Created by HW Lee on 3/27/15.
//
//

#ifndef __TestGame__GUtils__
#define __TestGame__GUtils__

#include <stdio.h>
#include "cocos2d.h"

class GUtils {
public:
    static void drawSolidHexagon(cocos2d::DrawNode* node, cocos2d::Point center, float r,
                                 float phi, cocos2d::Color4F colorFilled, cocos2d::Color4F lineColor);
    static void drawSolidHexagon(cocos2d::DrawNode* node, cocos2d::Point center, float r,
                                 cocos2d::Color4F colorFilled, cocos2d::Color4F lineColor);
};

#endif /* defined(__TestGame__GUtils__) */
