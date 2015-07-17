//
//  Unit.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__Unit__
#define __MAIDS_Game1__Unit__

#include <stdio.h>
#include "cocos2d.h"
#include "Attribute.h"
USING_NS_CC;

class Unit : public Ref {
public:
    Unit(int attr_code);
    Unit();
    virtual void changeAttr(int attr_code);
    virtual void changeAttr();
    int getAttribute();
    
protected:
    int mAttribute;
};

#endif /* defined(__MAIDS_Game1__Unit__) */
