//2023 12 26 红焖我的胃 2253230 张正阳
// 关卡选择场景的头文件

#ifndef __LEVEL_SELECT_SCENE_H__
#define __LEVEL_SELECT_SCENE_H__

//#include "LevelSceneTwo.h"   
#include "cocos2d.h"
USING_NS_CC;

class LevelSelectScene : public cocos2d::Scene
{
public:
    LevelSelectScene();
    ~LevelSelectScene();
    static int getLastSelectedLevel();

    void setLastSelectedLevel(int a);

    static cocos2d::Scene* createScene();

    virtual bool init();


    CREATE_FUNC(LevelSelectScene);

    // 按钮回调函数
    void level1Callback(cocos2d::Ref* pSender);
    void level2Callback(cocos2d::Ref* pSender);
    void returnToMainMenuCallback(cocos2d::Ref* pSender);

private:
    void createBackground(); // 创建背景
    void positionUIElements(); // 设置UI元素的位置

    static int lastSelectedLevel;
};
#endif // __LEVEL_SELECT_SCENE_H__

