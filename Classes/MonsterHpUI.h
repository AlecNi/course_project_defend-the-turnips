/*
2251918 刘骏伟 2023 12 25 ver1.0
*/
/*
ver1.0 怪物血条类
ver1.1 修改了create接口和init接口的参数及命名
	   修改了变量命名
ver1.2 修改了create接口和init接口的参数，先使用默认值
*/

#ifndef __CMONSTER_HP_UI_H__
#define __CMONSTER_HP_UI_H__

#include "cocos2d.h"
USING_NS_CC;

class CMonsterHpUI : public cocos2d::Node {
public:
    CMonsterHpUI();
    ~CMonsterHpUI();

    virtual bool init() override;

    // 设置血条百分比（0.0到1.0）
    void setHealth(float flPercentage);

    CREATE_FUNC(CMonsterHpUI);

private:
    // 更新血条显示
    void updateCMonsterHpUI();

private:
    cocos2d::Sprite* background; // 背景
    cocos2d::Sprite* bar;        // 血条
    CC_SYNTHESIZE(float, m_flMyRate, MyRate);             // 血条百分比
};

#endif // __CMONSTER_HP_UI_H__
