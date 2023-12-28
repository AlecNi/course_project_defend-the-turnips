//2023 12 26 红焖我的胃 2253230 张正阳
//开始场景的头文件

#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class StartScene : public cocos2d::Scene
{
public:
    StartScene();
    virtual ~StartScene();

    virtual bool init();

    CREATE_FUNC(StartScene);

    // 按钮回调函数
    void startGameCallback(cocos2d::Ref* pSender);
    void quitGameCallback(cocos2d::Ref* pSender);

private:
private:
    void createBackground(); // 创建背景
    void createLabel(); // 创建标签
    void positionUIElements(); // 设置UI元素的位置
};

#endif // __START_SCENE_H__
