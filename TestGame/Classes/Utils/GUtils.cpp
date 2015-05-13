//
//  GUtils.cpp
//  TestGame
//
//  Created by HW Lee on 3/27/15.
//
//

#include "GUtils.h"
#include <math.h>
USING_NS_CC;

void GUtils::drawSolidHexagon(cocos2d::DrawNode* node, Point center,
                              float r, float phi, cocos2d::Color4F colorFilled, cocos2d::Color4F lineColor) {
    Point* vertices = new Point[6];
    for (int i = 0; i < 6; i++) {
        vertices[i].x = center.x + r*cosf(i*M_PI/3+phi);
        vertices[i].y = center.y + r*sinf(i*M_PI/3+phi);
    }
    node->drawPolygon(vertices, 6, colorFilled, 3, lineColor);
}

void GUtils::drawSolidHexagon(cocos2d::DrawNode* node, Point center,
                              float r, cocos2d::Color4F colorFilled, cocos2d::Color4F lineColor) {
    drawSolidHexagon(node, center, r, 0, colorFilled, lineColor);
}