//2023 12 27 �����ҵ�θ 2253230 ������
//�ؿ�ͨ������ͷ�ļ�

// LevelTwoScene.h

#ifndef __LEVEL_TWO_SCENE__
#define __LEVEL_TWO_SCENE__

#include "cocos2d.h"

class LevelTwoScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(LevelTwoScene);

    // ��ť����¼�������
    void onTowerButtonClicked(cocos2d::Ref* sender);  //���İ�ť������
    void onPauseButtonClicked(cocos2d::Ref* sender);  //��ͣ��ť������
    void onResumeButtonClicked(cocos2d::Ref* sender);   //������Ϸ��ť������
    void onExitButtonClicked(cocos2d::Ref* sender);     //�˳���ť������

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

#endif // __LEVEL_TWO_SCENE__

