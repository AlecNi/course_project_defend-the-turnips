//2023 12 26 红焖我的胃 2253230 张正阳
// 游戏失败场景头文件

#ifndef __GAME_WIN_SCENE_H__
#define __GAME_WIN_SCENE_H__

#include "cocos2d.h"
#include "LevelSelectScene.h"  

class GameWinScene : public cocos2d::Scene
{
public:
    GameWinScene();
    ~GameWinScene();
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(GameWinScene);

    // 按钮回调函数
    void TurnToNextLevelCallback(cocos2d::Ref* pSender);
    void returnToLevelSelectCallback(cocos2d::Ref* pSender);

    //移除小图片
    void showAndDismissImage(float dt);
 
private:
    void createBackground(); // 创建背景
    void positionUIElements(); // 设置UI元素的位置

    cocos2d::Sprite* winImage;

};

#endif // __GAME_Win_SCENE_H__

