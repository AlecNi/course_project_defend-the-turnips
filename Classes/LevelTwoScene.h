//2023 12 27 红焖我的胃 2253230 张正阳
//关卡通用生成头文件

// LevelTwoScene.h

#ifndef __LEVEL_TWO_SCENE__
#define __LEVEL_TWO_SCENE__

#include "cocos2d.h"

class LevelTwoScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(LevelTwoScene);

    // 按钮点击事件处理函数
    void onTowerButtonClicked(cocos2d::Ref* sender);  //塔的按钮及后续
    void onPauseButtonClicked(cocos2d::Ref* sender);  //暂停按钮及后续
    void onResumeButtonClicked(cocos2d::Ref* sender);   //返回游戏按钮及后续
    void onExitButtonClicked(cocos2d::Ref* sender);     //退出按钮及后续

    // 地图初始化函数
    void initMap();


    // 游戏结束处理函数
    void gameEnd(bool win);

    // 更新金币数量显示
    void updateGoldLabel();

private:
    // 声明其他游戏元素，如地图、怪物、炮塔、萝卜、金币等

    cocos2d::Label* goldLabel; // 金币数量标签
};

#endif // __LEVEL_TWO_SCENE__

