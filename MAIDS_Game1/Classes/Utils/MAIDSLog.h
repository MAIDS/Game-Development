//
//  MAIDSLog.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__MAIDSLog__
#define __MAIDS_Game1__MAIDSLog__

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

#endif /* defined(__MAIDS_Game1__MAIDSLog__) */
