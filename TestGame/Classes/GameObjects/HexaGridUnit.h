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
#include "MAIDSLog.h"

class HexaGridUnit : public cocos2d::Node {
public:
    HexaGridUnit(float w, int type_wuxing);
    HexaGridUnit(float w);
    void changeWuXing(int type_wuxing);
    void changeWuXing();
    void notifyChanged();
    void setSelectedMask(cocos2d::Node* selectedMask);
    void selected();
    void unselected();
    bool isSelected();
    
private:
    static const std::string TAG;
    int type_wuxing = -1;
    int state;
    enum {
        UNSELECTED,
        SELECTED
    };
    cocos2d::Node* nodeWuXing = NULL;
    cocos2d::Node* selectedNode = NULL;
    
    void initNodeWuXing(int type_wuxing);
};

#endif /* defined(__TestGame__HexaGridUnit__) */
