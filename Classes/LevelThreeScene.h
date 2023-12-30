//2023 12 27 �����ҵ�θ 2253230 ������
//�ؿ�ͨ������ͷ�ļ�

// LevelThreeScene.h

#ifndef __LEVEL_THREE_SCENE__
#define __LEVEL_THREE_SCENE__

#include "cocos2d.h"

class LevelThreeScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(LevelThreeScene);

    // ��ť����¼�������
    void onTowerButtonClicked(cocos2d::Ref* sender);
    void onPauseButtonClicked(cocos2d::Ref* sender);
    void onResumeButtonClicked(cocos2d::Ref* sender);
    void onExitButtonClicked(cocos2d::Ref* sender);

    // ��ͼ��ʼ������
    void initMap();


    // ��Ϸ����������
    void gameEnd(bool win);

    // ���½��������ʾ
    void updateGoldLabel();

private:
    // ����������ϷԪ�أ����ͼ������������ܲ�����ҵ�

    cocos2d::Label* goldLabel; // ���������ǩ
};

#endif // __LEVEL_THREE_SCENE__


