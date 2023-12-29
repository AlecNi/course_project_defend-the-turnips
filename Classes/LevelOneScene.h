//2023 12 26 红焖我的胃 2253230 张正阳
//关卡通用生成头文件

// LevelOneScene.h

#ifndef LEVEL_ONE_SCENE
#define LEVEL_ONE_SCENE

#include "Monster.h"
#include "MonsterHpUI.h"
#include "MonsterMgr.h"
#include "cocos2d.h"

class LevelOneScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createSceneOne();

    virtual bool init();
    CREATE_FUNC(LevelOneScene);

    // 按钮点击事件处理函数
    void onTowerButtonClicked(cocos2d::Ref* sender);
    void onPauseButtonClicked(cocos2d::Ref* sender);
    void onResumeButtonClicked(cocos2d::Ref* sender);
    void onExitButtonClicked(cocos2d::Ref* sender);

    // 地图初始化函数
    void initMap();

    // 游戏结束处理函数
    void gameEnd(bool win);

    // 更新金币数量显示
    void updateGoldLabel();

    // 添加怪物
    void addMonster();

    // 更新怪物移动
    void updateMonsterMovement(float dt);

    // 更新怪物血条
    void updateMonsterHpBar(float hpPercentage);

    // 添加炮塔
    void addTower(float x, float y);

    // 炮塔发射子弹
    void towerShootBullet(CTower* tower, CMonster* target);

    // 设置金币标签显示金币数量
    void setGoldNum(int goldNum);

    // 创造地图块
    void createMapBlock(float x, float y);

    // 设置贴纸，萝卜的显示
    void setStickerAndRadish(float x, float y);

private:
    // 声明其他游戏元素，如地图、怪物、炮塔、萝卜、金币等
    cocos2d::Label* goldLabel; // 金币数量标签
    cocos2d::Vector<CMonster*> monsters;
    cocos2d::Vector<CTower*> towers;
    cocos2d::Sprite* radish; // 萝卜
    int goldNum; // 金币数量
};

#endif // LEVEL_ONE_SCENE

