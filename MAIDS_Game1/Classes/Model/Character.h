//
//  Character.h
//  MAIDS_Game1
//
//  Created by HW Lee on 7/13/15.
//
//

#ifndef __MAIDS_Game1__Character__
#define __MAIDS_Game1__Character__

#include <iostream>
#include "cocos2d.h"
#include "Unit.h"
#include "UnitListener.h"
#include "Constants.h"

#define Character_key_NO "no"
#define Character_key_NAME "name"
#define Character_key_RARE "rare"
#define Character_key_OCCUPATION "occupation"
#define Character_key_ATTRIBUTE "attr"
#define Character_key_TRIBE "tribe"
#define Character_key_SERIES "series"
#define Character_key_ATK "atk"
#define Character_key_HP "hp"
#define Character_key_RCV "rcv"
#define Character_key_SPD "spd"
#define Character_key_ACTIVE_SKILL_NO "act_skill_no"
#define Character_key_PASSIVE_SKILL_NO "pas_skill_no"
#define Character_key_CURRENT_STATUS "cur_status"
#define Character_key_EXPERIENCE "exp"
#define Character_key_LEVEL "lv"
#define Character_key_SKILL_LEVEL "slv"
#define Character_key_COMMON_INFO "common_info"
#define Character_key_MAX_EXPERIENCE "max_exp"
#define Character_key_EXPERIENCE_CURVE "exp_curve"
#define Character_key_MAX_LEVEL "max_level"
#define Character_key_MAX_SKILL_LEVEL "max_slv"
#define Character_key_ATK_CURVE "atk_curve"
#define Character_key_HP_CURVE "hp_curve"
#define Character_key_RCV_CURVE "rcv_curve"
#define Character_key_SPD_CURVE "spd_curve"

USING_NS_CC;
using namespace std;

class CharacterListener;

class Character : public Node, public Unit {
public:
    Character(string jsonStr);
    
    void setNo(int no);
    void setName(string name);
    void setRare(int rare);
    void setOccupation(int occup);
    void setTribe(int tribe);
    void setSeries(string series);
    void setAtk(int atk);
    void setHp(int hp);
    void setRcv(int rcv);
    void setSpd(int spd);
    void setListener(CharacterListener* l);
    
    int getNo();
    string getName();
    int getRare();
    int getOccupation();
    int getTribe();
    string getSeries();
    int getAtk();
    int getHp();
    int getRcv();
    int getSpd();
    CharacterListener* getListener();
    
private:
    int mNo;
    string mName;
    int mRare;
    int mOccup;
    int mTribe;
    string mSeries;
    int mAtk;
    int mHp;
    int mRcv;
    int mSpd;
    
    CharacterListener* mListener;
};

class CharacterListener : public UnitListener {
public:
    virtual void onCreated() = 0;
    virtual void onAttacked() = 0;
    virtual void onDie() = 0;
    virtual void onMoved(Point p) = 0;
};

#endif /* defined(__MAIDS_Game1__Character__) */
