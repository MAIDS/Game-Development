//
//  HexaGridUnit.cpp
//  TestGame
//
//  Created by HW Lee on 3/28/15.
//
//

#include "HexaGridUnit.h"
#include "DUtils.h"
#include "cocos2d.h"
USING_NS_CC;

#define WUXING_SIZE_SCALE 1.2

HexaGridUnit::HexaGridUnit(float w, int type_wuxing) {
    this->setContentSize(Size(w, w));
    this->type_wuxing = type_wuxing;
    this->nodeWuXing = Sprite::create(WuXing::PATH(this->type_wuxing));
    this->nodeWuXing->setScale(this->getContentSize().width/this->nodeWuXing->getContentSize().width*WUXING_SIZE_SCALE);
    this->nodeWuXing->setPosition(Vec2(.5, .5)*this->getContentSize().width);
    this->addChild(this->nodeWuXing, 0);
    this->state = this->UNSELECTED;
    this->notifyChanged();
}

HexaGridUnit::HexaGridUnit(float w) {
    int type = DUtils::getRandomInt(1, WuXing::NUM-2);
    if (type >= WuXing::EARTH) type++;
    this->setContentSize(Size(w, w));
    this->type_wuxing = type;
    this->nodeWuXing = Sprite::create(WuXing::PATH(this->type_wuxing));
    this->nodeWuXing->setScale(this->getContentSize().width/this->nodeWuXing->getContentSize().width*WUXING_SIZE_SCALE);
    this->nodeWuXing->setPosition(Vec2(.5, .5)*this->getContentSize().width);
    this->addChild(this->nodeWuXing, 0);
    this->state = this->UNSELECTED;
    this->notifyChanged();
}

void HexaGridUnit::notifyChanged() {
//    this->nodeWuXing = Sprite::create(WuXing::PATH(this->type_wuxing));
//    this->nodeWuXing->setScale(this->getContentSize().width/this->nodeWuXing->getContentSize().width*1.1);
//    this->nodeWuXing->setPosition(Vec2(.5, .5)*this->getContentSize().width);
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
