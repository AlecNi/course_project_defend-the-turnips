//2023 12 26 �����ҵ�θ 2253230 ������
//��ʼ������ͷ�ļ�

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

    // ��ť�ص�����
    void startGameCallback(cocos2d::Ref* pSender);
    void quitGameCallback(cocos2d::Ref* pSender);

private:
private:
    void createBackground(); // ��������
    void createLabel(); // ������ǩ
    void positionUIElements(); // ����UIԪ�ص�λ��
};

#endif // __START_SCENE_H__
