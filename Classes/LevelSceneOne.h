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

    
    bool initWithData(SLevelData* pSInitData);  // 场景初始化函数

    // 创建坐标系
    void setBackground();       //设置背景图
    void setInitButton();       //设置加速、暂停按钮
    void accelerateGame(Ref* sender);  // 加速游戏
    void setTopBackground();         
    void setCarrotPosition();
    void pauseGame(Ref* sender);  // 暂停游戏
    void resumeGame(Ref* sender);  // 恢复游戏
    void quitGame(Ref* sender);  // 退出游戏
    void restartGame(Ref* sender);//重玩游戏
    //void saveAndCreateNewImage(Ref* sender);  // 保存并创建新图像
    bool listenerStart();       //开启鼠标监听
    void setStartPosition();       //出怪口图片
    void onMouseDown(Event* event);;       //获取鼠标点击事件坐标
    void Start();
    void createLabel();
    void showCountdown();

protected:   
    MenuItemImage* accelerateButton;    //加速按钮图片
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
    };                          //游戏地图建系




};






#endif // __LEVEL_SCENE_ONE_H__
