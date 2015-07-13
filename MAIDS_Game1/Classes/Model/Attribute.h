//
//  Attribute.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__Attribute__
#define __MAIDS_Game1__Attribute__

#include <stdio.h>
#include "cocos2d.h"

class Attribute {
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

#endif /* defined(__MAIDS_Game1__Attribute__) */
