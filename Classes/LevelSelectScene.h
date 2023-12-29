//2023 12 26 �����ҵ�θ 2253230 ������
// �ؿ�ѡ�񳡾���ͷ�ļ�

#ifndef __LEVEL_SELECT_SCENE_H__
#define __LEVEL_SELECT_SCENE_H__

#include "LevelOneScene.h"   
#include "LevelTwoScene.h"   
#include "LevelThreeScene.h" 
#include "cocos2d.h"


class LevelSelectScene : public cocos2d::Scene
{
public:

    static int getLastSelectedLevel();


    LevelSelectScene();
    virtual ~LevelSelectScene();

    virtual bool init();


    CREATE_FUNC(LevelSelectScene);

    // ��ť�ص�����
    void level1Callback(cocos2d::Ref* pSender);
    void level2Callback(cocos2d::Ref* pSender);
    void level3Callback(cocos2d::Ref* pSender);
    void returnToMainMenuCallback(cocos2d::Ref* pSender);

private:
    void createBackground(); // ��������
    void createLabel(); // ������ǩ
    void positionUIElements(); // ����UIԪ�ص�λ��

    static int lastSelectedLevel;
};

#endif // __LEVEL_SELECT_SCENE_H__

