/*
红焖我的胃 

2253230 张正阳

2023 12 26
*/

/*
开始场景
*/

#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"


class StartScene : public cocos2d::Scene
{
public:

    StartScene();
    ~StartScene();
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(StartScene);

     //按钮回调函数
    void startGameCallback(cocos2d::Ref* pSender);
    void quitGameCallback(cocos2d::Ref* pSender);

private:
    void createALL(); // 创建一切
};

#endif // __START_SCENE_H__
