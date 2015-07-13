//
//  UnitListener.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__UnitListener__
#define __MAIDS_Game1__UnitListener__

#include <iostream>
#include "cocos2d.h"

class UnitListener {
public:
    virtual void onAttrChanged(int attr_code) = 0;
};

#endif /* defined(__MAIDS_Game1__UnitListener__) */
