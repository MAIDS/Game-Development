//
//  MAIDSLog.cpp
//  TestGame
//
//  Created by HW Lee on 7/8/15.
//
//

#include "MAIDSLog.h"
#include "cocos2d.h"
USING_NS_CC;

bool MAIDSLog::isDebug = true;

void MAIDSLog::d(std::string tag, std::string name) { log("debug", tag, name); }
void MAIDSLog::i(std::string tag, std::string name) { log("info", tag, name); }
void MAIDSLog::e(std::string tag, std::string name) { log("error", tag, name); }

void MAIDSLog::log(std::string type, std::string tag, std::string name) {
    if (isDebug) CCLOG("(%s) [%s]: %s", type.c_str(), tag.c_str(), name.c_str());
}
