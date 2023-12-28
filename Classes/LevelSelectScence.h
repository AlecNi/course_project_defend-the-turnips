//2023 12 26 �����ҵ�θ 2253230 ������
// �ؿ�ѡ�񳡾���ͷ�ļ�

#ifndef __LEVEL_SELECT_SCENE_H__
#define __LEVEL_SELECT_SCENE_H__

#include "cocos2d.h"

class LevelSelectScene : public cocos2d::Scene
{
public:
    LevelSelectScene();
    virtual ~LevelSelectScene();

    virtual bool init();


    CREATE_FUNC(LevelSelectScene);

    // ��ť�ص�����
    void level1Callback(cocos2d::Ref* pSender);
    void level2Callback(cocos2d::Ref* pSender);
    void level3Callback(cocos2d::Ref* pSender);
    void level4Callback(cocos2d::Ref* pSender);
    void level5Callback(cocos2d::Ref* pSender);
    void returnToMainMenuCallback(cocos2d::Ref* pSender);

private:
    void createBackground(); // ��������
    void createLabel(); // ������ǩ
    void positionUIElements(); // ����UIԪ�ص�λ��
};

#endif // __LEVEL_SELECT_SCENE_H__

