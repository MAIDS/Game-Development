//
//  Unit.cpp
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#include "Unit.h"
#include "cocos2d.h"
#include "Attribute.h"
#include "Utils.h"
USING_NS_CC;

Unit::Unit(int attr_code) { this->mAttribute = attr_code; }
Unit::Unit() { Unit((int)Attribute::NONE); }

void Unit::changeAttr(int attr_code) { this->mAttribute = attr_code; }
void Unit::changeAttr() { changeAttr(Utils::getRandomInt(Attribute::METAL, Attribute::YANG)); }
int Unit::getAttribute() { return this->mAttribute; }
