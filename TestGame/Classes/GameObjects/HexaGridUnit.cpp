//
//  HexaGridUnit.cpp
//  TestGame
//
//  Created by HW Lee on 3/28/15.
//
//

#include "HexaGridUnit.h"
#include "DUtils.h"
#include "WuXing.h"
#include "cocos2d.h"
USING_NS_CC;

#define WUXING_SIZE_SCALE 1.2

const std::string HexaGridUnit::TAG = "HexaGridUnit";

HexaGridUnit::HexaGridUnit(float w, int type_wuxing) {
    this->setContentSize(Size(w, w));
    this->initNodeWuXing(type_wuxing);
    this->state = this->UNSELECTED;
    this->notifyChanged();
}

HexaGridUnit::HexaGridUnit(float w) {
    int type = DUtils::getRandomInt(1, Attribute::NUM-1);
    this->setContentSize(Size(w, w));
    this->initNodeWuXing(type);
    this->state = this->UNSELECTED;
    this->notifyChanged();
}

void HexaGridUnit::initNodeWuXing(int type_wuxing) {
    this->type_wuxing = type_wuxing;
    
    this->nodeWuXing = Sprite::createWithTexture(Attribute::Texture(type_wuxing));
//    MAIDSLog::d(TAG, DUtils::appendString(2, "create ", WuXing::PATH(type_wuxing).c_str()));
    this->nodeWuXing->setScale(this->getContentSize().width/this->nodeWuXing->getContentSize().width*WUXING_SIZE_SCALE);
//    cout << this->getContentSize().width << endl;
    this->nodeWuXing->setPosition(Vec2(.5, .5)*this->getContentSize().width);
    this->addChild(this->nodeWuXing, 0);
}

void HexaGridUnit::changeWuXing() { this->changeWuXing(DUtils::getRandomInt(1, Attribute::NUM-1)); }

void HexaGridUnit::changeWuXing(int type_wuxing) {
    this->nodeWuXing->removeFromParent();
    this->initNodeWuXing(type_wuxing);
    this->notifyChanged();
}

void HexaGridUnit::notifyChanged() {
    if (this->selectedNode != NULL) {
        this->selectedNode->setVisible(this->state == this->SELECTED);
    }
}

void HexaGridUnit::setSelectedMask(cocos2d::Node *selectedMask) {
    this->selectedNode = selectedMask;
    this->addChild(this->selectedNode, 1);
    this->notifyChanged();
}

void HexaGridUnit::selected() {
    if (this->state != this->SELECTED) {
        this->state = this->SELECTED;
        this->notifyChanged();
    }
}

void HexaGridUnit::unselected() {
    if (this->state != this->UNSELECTED) {
        this->state = this->UNSELECTED;
        this->notifyChanged();
    }
}

bool HexaGridUnit::isSelected() {
    return (this->state == this->SELECTED) ? true:false;
}

