/*
�����ҵ�θ 

2253230 ������

2023 12 26
*/

/*
��ʼ����
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

     //��ť�ص�����
    void startGameCallback(cocos2d::Ref* pSender);
    void quitGameCallback(cocos2d::Ref* pSender);

private:
    void createALL(); // ����һ��
};

#endif // __START_SCENE_H__
