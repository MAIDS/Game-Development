//
//  HexaGridMapUnit.cpp
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#include "HexaGridMapUnit.h"
#include "Utils.h"
#include "Attribute.h"
#include "MAIDSLog.h"
#include "cocos2d.h"
USING_NS_CC;

#define ATTR_SIZE_SCALE 1.2

const std::string HexaGridMapUnit::TAG = "HexaGridMapUnit";

HexaGridMapUnit::HexaGridMapUnit(float w, int attr_code) {
    this->setContentSize(Size(w, w));
    this->initAttrNode(attr_code);
    this->mIsSelected = false;
    this->notifyChanged();
}

HexaGridMapUnit::HexaGridMapUnit(float w) {
    int attr_code = Utils::getRandomInt(Attribute::METAL, Attribute::YANG);
//    HexaGridMapUnit(w, attr_code);
    this->setContentSize(Size(w, w));
    this->initAttrNode(attr_code);
    this->mIsSelected = false;
    this->notifyChanged();
}

void HexaGridMapUnit::initAttrNode(int attr_code) {
    this->mAttribute = attr_code;
    
    this->attrNode = Sprite::createWithTexture(Attribute::Texture(attr_code));
    this->attrNode->setScale(this->getContentSize().width/this->attrNode->getContentSize().width*ATTR_SIZE_SCALE);
    this->attrNode->setPosition(Vec2(.5, .5)*this->getContentSize().width);
    this->addChild(this->attrNode, 0);
}

void HexaGridMapUnit::setListener(HexaGridMapUnitListener *l) { this->mListener = l; }

void HexaGridMapUnit::changeAttr(int attr_code) {
    MAIDSLog::d(TAG,
                Utils::appendString(3, "HexaGridMapUnit::changeAttr(", Attribute::PATH(attr_code).c_str(), ")"));
    Unit::changeAttr(attr_code);
    this->attrNode->removeFromParent();
    this->initAttrNode(this->mAttribute);
}

void HexaGridMapUnit::changeAttr() {
    MAIDSLog::d(TAG, "HexaGridMapUnit::changeAttr()");
    Unit::changeAttr();
    this->changeAttr(this->mAttribute);
}

void HexaGridMapUnit::notifyChanged() {
    if (this->selectedNode != nullptr) { this->selectedNode->setVisible(this->mIsSelected); }
}

void HexaGridMapUnit::setSelectedMask(cocos2d::Node *selectedMask) {
    this->selectedNode = selectedMask;
    this->addChild(this->selectedNode, 1);
    this->notifyChanged();
}

void HexaGridMapUnit::selected() {
    if (!this->mIsSelected) { this->mIsSelected = true; this->notifyChanged(); }
}

void HexaGridMapUnit::unselected() {
    if (this->mIsSelected) { this->mIsSelected = false; this->notifyChanged(); }
}

bool HexaGridMapUnit::isSelected() { return this->mIsSelected; }
