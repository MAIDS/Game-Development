//
//  WuXing.h
//  TestGame
//
//  Created by HW Lee on 7/8/15.
//
//

#ifndef __TestGame__WuXing__
#define __TestGame__WuXing__

#include <stdio.h>
#include "cocos2d.h"

class WuXing {
public:
    static const int NONE = 0;
    static const int METAL = 1;
    static const int WOOD = 2;
    static const int WATER = 3;
    static const int FIRE = 4;
    static const int YIN = 5;
    static const int YANG = 6;
    static const int NUM = 7;
    
    static bool isInitialized;
    static cocos2d::Texture2D* METAL_TEXTURE;
    static cocos2d::Texture2D* WOOD_TEXTURE;
    static cocos2d::Texture2D* WATER_TEXTURE;
    static cocos2d::Texture2D* FIRE_TEXTURE;
    static cocos2d::Texture2D* YIN_TEXTURE;
    static cocos2d::Texture2D* YANG_TEXTURE;
    
    static std::string PATH(int type);
    
    static void init();
    
    static cocos2d::Texture2D* Texture(int type);
};

#endif /* defined(__TestGame__WuXing__) */
