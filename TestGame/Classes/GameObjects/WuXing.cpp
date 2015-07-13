//
//  WuXing.cpp
//  TestGame
//
//  Created by HW Lee on 7/8/15.
//
//

#include "WuXing.h"
#include "MAIDSLog.h"

bool Attribute::isInitialized = false;
cocos2d::Texture2D* Attribute::METAL_TEXTURE = nullptr;
cocos2d::Texture2D* Attribute::WOOD_TEXTURE = nullptr;
cocos2d::Texture2D* Attribute::WATER_TEXTURE = nullptr;
cocos2d::Texture2D* Attribute::FIRE_TEXTURE = nullptr;
cocos2d::Texture2D* Attribute::YIN_TEXTURE = nullptr;
cocos2d::Texture2D* Attribute::YANG_TEXTURE = nullptr;

std::string Attribute::PATH(int type) {
    switch (type) {
        case NONE:
            return "";
        case METAL:
            return "metal.png";
        case WOOD:
            return "wood.png";
        case WATER:
            return "water.png";
        case FIRE:
            return "fire.png";
        case YIN:
            return "yin.png";
        case YANG:
            return "yang.png";
            
        default:
            return "";
    }
}

cocos2d::Texture2D* Attribute::Texture(int type) {
    if (!isInitialized) { init(); isInitialized = true; }
    switch (type) {
        case NONE:
            return nullptr;
        case METAL:
            return METAL_TEXTURE;
        case WOOD:
            return WOOD_TEXTURE;
        case WATER:
            return WATER_TEXTURE;
        case FIRE:
            return FIRE_TEXTURE;
        case YIN:
            return YIN_TEXTURE;
        case YANG:
            return YANG_TEXTURE;
            
        default:
            return nullptr;
    }
}

void Attribute::init() {
    MAIDSLog::i("WuXing", "initTexture");
    METAL_TEXTURE = cocos2d::Sprite::create(PATH(METAL))->getTexture();
    WOOD_TEXTURE = cocos2d::Sprite::create(PATH(WOOD))->getTexture();
    WATER_TEXTURE = cocos2d::Sprite::create(PATH(WATER))->getTexture();
    FIRE_TEXTURE = cocos2d::Sprite::create(PATH(FIRE))->getTexture();
    YIN_TEXTURE = cocos2d::Sprite::create(PATH(YIN))->getTexture();
    YANG_TEXTURE = cocos2d::Sprite::create(PATH(YANG))->getTexture();
}
