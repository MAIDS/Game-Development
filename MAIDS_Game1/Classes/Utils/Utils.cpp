//
//  Utils.cpp
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#include "Utils.h"
#include "cocos2d.h"
#include <math.h>
#include <iostream>
#include <stdarg.h>
#include <sstream>
USING_NS_CC;

/*
 *
 *  Computational
 *
 */
Point Utils::calPositionWithPoint(float x, float y, float ptsMargin, float phi) {
    return Utils::rotate(Point(x+0.5*y, sqrtf(0.75)*y), phi + M_PI/6)*ptsMargin;
}

Point Utils::calPointWithPosition(float x_pos, float y_pos, Point origin, float ptsMargin, float phi) {
    float x = x_pos - origin.x;
    float y = y_pos - origin.y;
    auto pts = Utils::rotate(Vec2(x, y), -(phi + M_PI/6));
    x = pts.x;
    y = pts.y;
    return Point(x-y/sqrtf(3), 2*y/sqrtf(3))/ptsMargin;
}

Vec2 Utils::rotate(cocos2d::Vec2 vec, float phi) {
    float cos_phi = cosf(phi), sin_phi = sinf(phi);
    return Vec2(vec.x*cos_phi - vec.y*sin_phi, vec.x*sin_phi + vec.y*cos_phi);
}

Vec2 Utils::round(cocos2d::Vec2 vec, float thresh) {
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

Vec2 Utils::round(cocos2d::Vec2 vec) {
    return Utils::round(vec, .5);
}

int Utils::calManhattanDistHexaGrid(Point p1, Point p2) {
    return Utils::calManhattanDistHexaGrid(p2-p1);
}

int Utils::calManhattanDistHexaGrid(cocos2d::Vec2 vec) {
    int x_abs = (int)((vec.x >= 0) ? vec.x:-vec.x);
    int y_abs = (int)((vec.y >= 0) ? vec.y:-vec.y);
    if (vec.x*vec.y > 0) return x_abs+y_abs;
    else return (x_abs > y_abs) ? x_abs:y_abs;
}

int Utils::getRandomInt(int min, int max) {
    return min + (rand() % (int)(max - min + 1));
}


/*
 *
 *  String
 *
 */
std::string Utils::generateNameByPoint(Point pt) {
    std::ostringstream strStream;
    strStream << pt.x << "," << pt.y;
    return strStream.str();
}

std::string Utils::appendString(int n_args, ...) {
    va_list ap;
    std::string str = "";
    va_start(ap, n_args);
    for (int i = 0; i < n_args; i++) {
        str.append(va_arg(ap, char*));
    }
    return str;
}


/*
 *
 *  Graphic
 *
 */
void Utils::drawSolidHexagon(cocos2d::DrawNode* node, Point center,
                              float r, float phi, cocos2d::Color4F colorFilled, cocos2d::Color4F lineColor) {
    Point* vertices = new Point[6];
    for (int i = 0; i < 6; i++) {
        vertices[i].x = center.x + r*cosf(i*M_PI/3+phi);
        vertices[i].y = center.y + r*sinf(i*M_PI/3+phi);
    }
    node->drawPolygon(vertices, 6, colorFilled, 3, lineColor);
}

void Utils::drawSolidHexagon(cocos2d::DrawNode* node, Point center,
                              float r, cocos2d::Color4F colorFilled, cocos2d::Color4F lineColor) {
    drawSolidHexagon(node, center, r, 0, colorFilled, lineColor);
}