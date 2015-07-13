//
//  Character.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__Character__
#define __MAIDS_Game1__Character__

#include <iostream>
#include "cocos2d.h"
#include "Unit.h"
#include "UnitListener.h"
USING_NS_CC;
using namespace std;

class CharacterListener;

class Character : public Node, public Unit {
public:
    
private:
    
};

class CharacterListener : public UnitListener {
public:
    virtual void onCreated() = 0;
    virtual void onAttacked() = 0;
    virtual void onDie() = 0;
    virtual void onMoved(Point p) = 0;
};

#endif /* defined(__MAIDS_Game1__Character__) */
