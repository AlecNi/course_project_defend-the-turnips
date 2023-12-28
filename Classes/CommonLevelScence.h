//2023 12 26 �����ҵ�θ 2253230 ������
#ifndef __COMMON_LEVEL_H__
#define __COMMON_LEVEL_H__

#include "cocos2d.h"

class CommonLevel : public cocos2d::Scene {
public:
    CommonLevel();
    virtual ~CommonLevel();

    virtual bool init();

    // ���õĹؿ��߼��ͷ���
    void commonMethod();

    // ���õĳ�Ա����
    cocos2d::Sprite* background;
    cocos2d::Sprite* map;
    cocos2d::Vec2 radishPosition;
    cocos2d::Vec2 spawnPoint;
    // �������õĳ�Ա����

    CREATE_FUNC(CommonLevel);

};

#endif // __COMMON_LEVEL_H__
#pragma once
