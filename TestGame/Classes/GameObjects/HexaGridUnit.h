//
//  HexaGridUnit.h
//  TestGame
//
//  Created by HW Lee on 3/28/15.
//
//

#ifndef __TestGame__HexaGridUnit__
#define __TestGame__HexaGridUnit__

#include <iostream>
#include "cocos2d.h"

class HexaGridUnit : public cocos2d::Node {
public:
    HexaGridUnit(float w, int type_wuxing);
    HexaGridUnit(float w);
    void notifyChanged();
    void setSelectedMask(cocos2d::Node* selectedMask);
    void selected();
    void unselected();
    bool isSelected();
    
private:
    int type_wuxing = -1;
    int state;
    enum {
        UNSELECTED,
        SELECTED
    };
    cocos2d::Node* nodeWuXing = NULL;
    cocos2d::Node* selectedNode = NULL;
    
};

class WuXing {
public:
    static const int NONE = 0;
    static const int METAL = 1;
    static const int WOOD = 2;
    static const int WATER = 3;
    static const int FIRE = 4;
    static const int EARTH = 5;
    static const int YIN = 6;
    static const int YANG = 7;
    static const int NUM = 8;
    
    static std::string PATH(int type) {
        switch (type) {
            case NONE:
                return "";
            case METAL:
                return "metal.png";
            case WOOD:
                return "wood.png";
            case WATER:
                return "water.png";
            case FIRE:
                return "fire.png";
            case YIN:
                return "yin.png";
            case YANG:
                return "yang.png";
                
            default:
                return "";
        }
    }
};

#endif /* defined(__TestGame__HexaGridUnit__) */
