//2023 12 26 �����ҵ�θ 2253230 ������
// �ؿ�ѡ�񳡾���ͷ�ļ�

#ifndef __LEVEL_SELECT_SCENE_H__
#define __LEVEL_SELECT_SCENE_H__

//#include "LevelSceneTwo.h"   
#include "cocos2d.h"
USING_NS_CC;

class LevelSelectScene : public cocos2d::Scene
{
public:
    LevelSelectScene();
    ~LevelSelectScene();
    static int getLastSelectedLevel();

    void setLastSelectedLevel(int a);

    static cocos2d::Scene* createScene();

    virtual bool init();


    CREATE_FUNC(LevelSelectScene);

    // ��ť�ص�����
    void level1Callback(cocos2d::Ref* pSender);
    void level2Callback(cocos2d::Ref* pSender);
    void returnToMainMenuCallback(cocos2d::Ref* pSender);

private:
    void createBackground(); // ��������
    void positionUIElements(); // ����UIԪ�ص�λ��

    static int lastSelectedLevel;
};
#endif // __LEVEL_SELECT_SCENE_H__

