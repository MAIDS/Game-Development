//
//  MAIDSLog.h
//  TestGame
//
//  Created by HW Lee on 7/8/15.
//
//

#ifndef __TestGame__MAIDSLog__
#define __TestGame__MAIDSLog__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class MAIDSLog {
public:
    static bool isDebug;
    
    static void d(std::string tag, std::string name);
    static void i(std::string tag, std::string name);
    static void e(std::string tag, std::string name);
    
private:
    static void log(std::string type, std::string tag, std::string name);
    
};

#endif /* defined(__TestGame__MAIDSLog__) */
