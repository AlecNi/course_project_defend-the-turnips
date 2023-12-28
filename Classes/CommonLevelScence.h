//2023 12 26 红焖我的胃 2253230 张正阳
#ifndef __COMMON_LEVEL_H__
#define __COMMON_LEVEL_H__

#include "cocos2d.h"

class CommonLevel : public cocos2d::Scene {
public:
    CommonLevel();
    virtual ~CommonLevel();

    virtual bool init();

    // 公用的关卡逻辑和方法
    void commonMethod();

    // 公用的成员变量
    cocos2d::Sprite* background;
    cocos2d::Sprite* map;
    cocos2d::Vec2 radishPosition;
    cocos2d::Vec2 spawnPoint;
    // 其他公用的成员变量

    CREATE_FUNC(CommonLevel);

};

#endif // __COMMON_LEVEL_H__
#pragma once
