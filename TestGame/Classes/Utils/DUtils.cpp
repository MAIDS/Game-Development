//
//  DUtils.cpp
//  TestGame
//
//  Created by HW Lee on 3/27/15.
//
//

#include "DUtils.h"
#include "cocos2d.h"
#include <math.h>
#include <iostream>
USING_NS_CC;

Point DUtils::calPositionWithPoint(float x, float y, float ptsMargin, float phi) {
    return DUtils::rotate(Point(x+0.5*y, sqrtf(0.75)*y), phi)*ptsMargin;
}

Point DUtils::calPointWithPosition(float x_pos, float y_pos, Point origin, float ptsMargin, float phi) {
    float x = x_pos - origin.x;
    float y = y_pos - origin.y;
    auto pts = DUtils::rotate(Vec2(x, y), -phi);
    x = pts.x;
    y = pts.y;
    return Point(x-y/sqrtf(3), 2*y/sqrtf(3))/ptsMargin;
}

Vec2 DUtils::rotate(cocos2d::Vec2 vec, float phi) {
    float cos_phi = cosf(phi), sin_phi = sinf(phi);
    return Vec2(vec.x*cos_phi - vec.y*sin_phi, vec.x*sin_phi + vec.y*cos_phi);
}

std::string DUtils::generateNameByPoint(Point pt) {
    std::ostringstream strStream;
    strStream << pt.x << "," << pt.y;
    return strStream.str();
}

Vec2 DUtils::round(cocos2d::Vec2 vec, float thresh) {
    Vec2 roundedVec = Vec2(0, 0);
    float x_abs = (vec.x > 0) ? vec.x:-vec.x;
    float y_abs = (vec.y > 0) ? vec.y:-vec.y;
    if (x_abs - (int)x_abs < thresh) {
        roundedVec.x = (float)(int)x_abs;
    } else if (x_abs - (int)x_abs >= 1-thresh) {
        roundedVec.x = (float)(int)x_abs+1;
    } else {
        return Vec2(.5, .5);
    }
    if (y_abs - (int)y_abs < thresh) {
        roundedVec.y = (float)(int)y_abs;
    } else if (y_abs - (int)y_abs >= 1-thresh) {
        roundedVec.y = (float)(int)y_abs+1;
    } else {
        return Vec2(.5, .5);
    }
    roundedVec.x = (vec.x > 0 || (int)roundedVec.x == 0) ? roundedVec.x:-roundedVec.x;
    roundedVec.y = (vec.y > 0 || (int)roundedVec.y == 0) ? roundedVec.y:-roundedVec.y;
    return Vec2(roundedVec);
}

Vec2 DUtils::round(cocos2d::Vec2 vec) {
    return DUtils::round(vec, .5);
}

int DUtils::calManhattanDistHexaGrid(Point p1, Point p2) {
    return DUtils::calManhattanDistHexaGrid(p2-p1);
}

int DUtils::calManhattanDistHexaGrid(cocos2d::Vec2 vec) {
    int x_abs = (int)((vec.x >= 0) ? vec.x:-vec.x);
    int y_abs = (int)((vec.y >= 0) ? vec.y:-vec.y);
    if (vec.x*vec.y > 0) return x_abs+y_abs;
    else return (x_abs > y_abs) ? x_abs:y_abs;
}

int DUtils::getRandomInt(int min, int max) {
    return min + (rand() % (int)(max - min + 1));
}
