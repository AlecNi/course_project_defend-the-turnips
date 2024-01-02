//2023 12 26 �����ҵ�θ 2253230 ������
// ��Ϸʧ�ܳ���ͷ�ļ�

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

    // ��ť�ص�����
    void retryLevelCallback(cocos2d::Ref* pSender);
    void returnToLevelSelectCallback(cocos2d::Ref* pSender);

private:
    void createBackground(); // ��������
    void positionUIElements(); // ����UIԪ�ص�λ��
};

#endif // __GAME_LOSE_SCENE_H__
