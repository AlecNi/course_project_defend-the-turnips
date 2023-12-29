//2023 12 26 �����ҵ�θ 2253230 ������
// ��Ϸʧ�ܳ���ͷ�ļ�

#ifndef __GAME_WIN_SCENE_H__
#define __GAME_WIN_SCENE_H__

#include "cocos2d.h"
#include "LevelSelectScene.h"  

class GameWinScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(GameWinScene);

    // ��ť�ص�����
    void TurnToNextLevelCallback(cocos2d::Ref* pSender);
    void returnToLevelSelectCallback(cocos2d::Ref* pSender);

    //�Ƴ�СͼƬ
    void GameWinScene::showAndDismissImage(float dt);
 
private:
    void createBackground(); // ��������
    void positionUIElements(); // ����UIԪ�ص�λ��

    cocos2d::Sprite* winImage;

};

#endif // __GAME_Win_SCENE_H__

