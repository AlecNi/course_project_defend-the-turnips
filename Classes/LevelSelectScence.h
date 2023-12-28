//2023 12 26 红焖我的胃 2253230 张正阳
// 关卡选择场景的头文件

#ifndef __LEVEL_SELECT_SCENE_H__
#define __LEVEL_SELECT_SCENE_H__

#include "cocos2d.h"

class LevelSelectScene : public cocos2d::Scene
{
public:
    LevelSelectScene();
    virtual ~LevelSelectScene();

    virtual bool init();


    CREATE_FUNC(LevelSelectScene);

    // 按钮回调函数
    void level1Callback(cocos2d::Ref* pSender);
    void level2Callback(cocos2d::Ref* pSender);
    void level3Callback(cocos2d::Ref* pSender);
    void level4Callback(cocos2d::Ref* pSender);
    void level5Callback(cocos2d::Ref* pSender);
    void returnToMainMenuCallback(cocos2d::Ref* pSender);

private:
    void createBackground(); // 创建背景
    void createLabel(); // 创建标签
    void positionUIElements(); // 设置UI元素的位置
};

#endif // __LEVEL_SELECT_SCENE_H__

