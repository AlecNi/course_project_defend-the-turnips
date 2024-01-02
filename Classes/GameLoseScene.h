//2023 12 26 红焖我的胃 2253230 张正阳
// 游戏失败场景头文件

#ifndef __GAME_LOSE_SCENE_H__
#define __GAME_LOSE_SCENE_H__

#include "cocos2d.h"
#include "LevelSelectScene.h"  

class GameLoseScene : public cocos2d::Scene
{
public:
    GameLoseScene();
    ~GameLoseScene();
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(GameLoseScene);

    // 按钮回调函数
    void retryLevelCallback(cocos2d::Ref* pSender);
    void returnToLevelSelectCallback(cocos2d::Ref* pSender);

private:
    void createBackground(); // 创建背景
    void positionUIElements(); // 设置UI元素的位置
};

#endif // __GAME_LOSE_SCENE_H__
