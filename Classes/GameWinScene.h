//2023 12 26 红焖我的胃 2253230 张正阳
// 游戏失败场景头文件

#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "LevelSelectScene.h"
#include "cocos2d.h"

class GameWinScene : public cocos2d::Scene {
public:
    virtual bool init();

    CREATE_FUNC(GameWinScene);

    // 背景图设置
    void addBackground();

    // 返回选择关卡按钮设置
    void addBackButton();

    // 按钮点击事件处理函数
    void backButtonCallback(cocos2d::Ref* pSender);

};

#endif // __GAME_OVER_SCENE_H__
