//
//  HexaGridMapUnit.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__HexaGridMapUnit__
#define __MAIDS_Game1__HexaGridMapUnit__

#include <iostream>
#include "cocos2d.h"
#include "Unit.h"
#include "UnitListener.h"
USING_NS_CC;
using namespace std;

class HexaGridMapUnitListener;

class HexaGridMapUnit : public Node, public Unit {
public:
    HexaGridMapUnit(float w, int attr_code);
    HexaGridMapUnit(float w);
    void setSelectedMask(Node* selectedMask);
    void selected();
    void unselected();
    bool isSelected();
    void notifyChanged();
    void setListener(HexaGridMapUnitListener* l);
    
    void changeAttr(int attr_code) override;
    void changeAttr() override;
    
private:
    static const string TAG;
    bool mIsSelected;
    HexaGridMapUnitListener* mListener = nullptr;
    Node* attrNode = nullptr;
    Node* selectedNode = nullptr;
    
    void initAttrNode(int attr_code);
    
};

class HexaGridMapUnitListener : public UnitListener {
public:
    virtual void onAttrChangeStarted(HexaGridMapUnit* unit) = 0;
    virtual void onAttrChangeEnded(HexaGridMapUnit* unit) = 0;
    
};

#endif /* defined(__MAIDS_Game1__HexaGridMapUnit__) */
