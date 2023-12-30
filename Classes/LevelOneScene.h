//2023 12 26 �����ҵ�θ 2253230 ������
//�ؿ�ͨ������ͷ�ļ�

// LevelOneScene.h

#ifndef LEVEL_ONE_SCENE
#define LEVEL_ONE_SCENE

#include "Monster.h"
#include "MonsterHpUI.h"
#include "MonsterMgr.h"
#include "cocos2d.h"

class LevelOneScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(LevelOneScene);

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



    // ���ý�ұ�ǩ��ʾ�������
    void setGoldNum(int goldNum);

    // �����ͼ��
    void createMapBlock(float x, float y);

    // ������ֽ���ܲ�����ʾ
    void setStickerAndRadish(float x, float y);

private:
    // ����������ϷԪ�أ����ͼ������������ܲ�����ҵ�
    cocos2d::Label* goldLabel; // ���������ǩ
    cocos2d::Vector<CMonster*> monsters;
    //cocos2d::Vector<CTower*> towers;
    cocos2d::Sprite* radish; // �ܲ�
    int goldNum; // �������
};

#endif // LEVEL_ONE_SCENE

