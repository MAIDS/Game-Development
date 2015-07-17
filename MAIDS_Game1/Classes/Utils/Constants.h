//
//  Constants.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef MAIDS_Game1_Constants_h
#define MAIDS_Game1_Constants_h

#include <iostream>

class GameAction {
public:
    static const int NONE = 0;
    static const int ATTACK = 1;
    static const int MOVE = 2;
};

class TribeCode {
public:
    static const int NONE = 0;
    
    static std::string toString(int code) {
        switch (code) {
            case NONE: return "";
            default: return "";
        }
    }
};

class CharacterCurve {
public:
    static const int LINEAR = 0;
    static const int EXPONENTIAL = 1;
    
    static std::string toString(int code) {
        switch (code) {
            case LINEAR: return "Linear";
            case EXPONENTIAL: return "Exponential";
            default: return "";
        }
    }
};

#endif
