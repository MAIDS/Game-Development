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
    void notifyChanged();
    void setNodesWuXing(cocos2d::Node** nodesWuXing);
    void setNodeWuXing(cocos2d::Node* nodeWuXing, int type);
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
    cocos2d::Node** nodesWuXing = NULL;
    cocos2d::Node* selectedNode = NULL;
    static const int TYPE_NUM = 8;
    
};

class WuXing {
public:
    /*
    static const int WU_XING_NONE = 0;
    static const int WU_XING_METAL = 1;
    static const int WU_XING_WOOD = 2;
    static const int WU_XING_WATER = 3;
    static const int WU_XING_FIRE = 4;
    static const int WU_XING_EARTH = 5;
    static const int WU_XING_YIN = 6;
    static const int WU_XING_YANG = 7;
    */
    static const int NONE = 0;
    static const int METAL = 1;
    static const int WOOD = 2;
    static const int WATER = 3;
    static const int FIRE = 4;
    static const int EARTH = 5;
    static const int YIN = 6;
    static const int YANG = 7;
};

#endif /* defined(__TestGame__HexaGridUnit__) */
