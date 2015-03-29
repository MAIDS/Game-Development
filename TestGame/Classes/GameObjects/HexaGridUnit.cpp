//
//  HexaGridUnit.cpp
//  TestGame
//
//  Created by HW Lee on 3/28/15.
//
//

#include "HexaGridUnit.h"
#include "cocos2d.h"
USING_NS_CC;

HexaGridUnit::HexaGridUnit(float w, int type_wuxing) {
    this->setContentSize(Size(w, w));
    this->type_wuxing = type_wuxing;
    this->state = this->UNSELECTED;
    this->nodesWuXing = new Node*[this->TYPE_NUM];
    
    for (int i = 0; i < this->TYPE_NUM; i++)
        this->nodesWuXing[i] = NULL;
}

void HexaGridUnit::notifyChanged() {
    if (this->nodesWuXing[this->type_wuxing] != NULL && !this->nodesWuXing[this->type_wuxing]->isVisible()) {
        for (int i = 0; i < this->TYPE_NUM; i++) {
            if (this->nodesWuXing[i] != NULL)
                this->nodesWuXing[i]->setVisible(i == this->type_wuxing);
        }
    }
    if (this->selectedNode != NULL) {
        this->selectedNode->setVisible(this->state == this->SELECTED);
    }
}

void HexaGridUnit::setNodeWuXing(cocos2d::Node *nodeWuXing, int type) {
    this->nodesWuXing[type] = nodeWuXing;
    this->setPosition(0, 0);
    this->addChild(this->nodesWuXing[type], 0);
    this->notifyChanged();
}

void HexaGridUnit::setNodesWuXing(cocos2d::Node **nodesWuXing) {
    for (int i = 0; i < this->TYPE_NUM; i++)
        this->setNodeWuXing(nodesWuXing[i], i);
    this->notifyChanged();
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
