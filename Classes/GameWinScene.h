//2023 12 26 �����ҵ�θ 2253230 ������
// ��Ϸʧ�ܳ���ͷ�ļ�

#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "LevelSelectScene.h"
#include "cocos2d.h"

class GameWinScene : public cocos2d::Scene {
public:
    virtual bool init();

    CREATE_FUNC(GameWinScene);

    // ����ͼ����
    void addBackground();

    // ����ѡ��ؿ���ť����
    void addBackButton();

    // ��ť����¼�������
    void backButtonCallback(cocos2d::Ref* pSender);

};

#endif // __GAME_OVER_SCENE_H__
