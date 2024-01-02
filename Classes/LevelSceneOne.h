// LevelSceneOne.h
#ifndef __LEVEL_SCENE_ONE_H__
#define __LEVEL_SCENE_ONE_H__

#include "cocos2d.h"

#define TOWER_AVAILBLE 0
#define ROAD 1
#define NONE 2
#define CARROT 5 
#define START 6

USING_NS_CC;


struct SLevelData;
class CMonsterMgr;
class CTowerMgr;
class CGold;
class CCarrot;

class LevelSceneOne : public cocos2d::Scene {
public:
    LevelSceneOne();
    ~LevelSceneOne();
    static LevelSceneOne* createWithData(SLevelData* pSInitData);

    
    bool initWithData(SLevelData* pSInitData);  // ������ʼ������

    // ��������ϵ
    void setBackground();       //���ñ���ͼ
    void setInitButton();       //���ü��١���ͣ��ť
    void accelerateGame(Ref* sender);  // ������Ϸ
    void setTopBackground();         
    void setCarrotPosition();
    void pauseGame(Ref* sender);  // ��ͣ��Ϸ
    void resumeGame(Ref* sender);  // �ָ���Ϸ
    void quitGame(Ref* sender);  // �˳���Ϸ
    void restartGame(Ref* sender);//������Ϸ
    //void saveAndCreateNewImage(Ref* sender);  // ���沢������ͼ��
    bool listenerStart();       //����������
    void setStartPosition();       //���ֿ�ͼƬ
    void onMouseDown(Event* event);;       //��ȡ������¼�����
    void Start();
    void createLabel();
    void showCountdown();

protected:   
    MenuItemImage* accelerateButton;    //���ٰ�ťͼƬ
    MenuItemImage* pauseButton;
    Sprite* pauseImage;
    CMonsterMgr* m_pMonsterMgr;
    CGold* m_pGold;
    CTowerMgr* m_pTowerMgr;
    CCarrot* m_pCarrot;
    SLevelData* m_pLevelData;

    char gameMap[7][12] = {         
    {0,0,0,2,2,2,2,2,2,0,0,0},
    {0,6,0,2,2,2,2,2,2,0,5,0},
    {0,1,0,2,2,2,2,2,2,0,1,0},
    {0,1,0,0,0,0,0,0,0,0,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2}
    };                          //��Ϸ��ͼ��ϵ




};






#endif // __LEVEL_SCENE_ONE_H__
