// LevelSelectScene.cpp

#include "LevelSelectScene.h"
//#include "DataTransTool.h"
#include "LevelSceneOne.h"
//#include "LevelSceneTwo.h"
#include "StartScene.h" // ������ʼ������ͷ�ļ�

USING_NS_CC;

int LevelSelectScene::lastSelectedLevel = 0;


void LevelSelectScene::setLastSelectedLevel(int a) {
    lastSelectedLevel = a;
}

Scene* LevelSelectScene::createScene()
{
    return LevelSelectScene::create();
}

int LevelSelectScene::getLastSelectedLevel() {

    return 0;
  // return lastSelectedLevel;
}


bool LevelSelectScene::init() {
    if (!Scene::init()) {
        return false;
    }
    createBackground();
    positionUIElements();

    return true;
}

void LevelSelectScene::createBackground() {
    // ���������ñ���ͼƬ
    auto background = Sprite::create("LSS_1.PNG"); // �滻 "background.jpg" Ϊ��ı���ͼƬ�ļ�·��
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    addChild(background);
    background->setContentSize(Size(960, 640));
}

void LevelSelectScene::positionUIElements() {
    // ���ð�ťλ��

    // Level 1 Button
    auto level1Button = MenuItemImage::create("LSS_2.PNG", "LSS_2.PNG", CC_CALLBACK_1(LevelSelectScene::level1Callback, this));
    level1Button->setPosition(Vec2(260, 300));
    level1Button->setScale(0.7);

    // Level 2 Button
    auto level2Button = MenuItemImage::create("LSS_3.PNG", "LSS_3.PNG", CC_CALLBACK_1(LevelSelectScene::level2Callback, this));
    level2Button->setPosition(Vec2(700, 300));
    level2Button->setScale(0.7);

    // Return to Main Menu Button
    auto returnButton = MenuItemImage::create("LSS_5.PNG", "LSS_6.PNG", CC_CALLBACK_1(LevelSelectScene::returnToMainMenuCallback, this));
    returnButton->setPosition(Vec2(480, 100));

    // �����˵�
    auto menu = Menu::create(level1Button, level2Button, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
}

void LevelSelectScene::level1Callback(cocos2d::Ref* pSender) {

     //��¼״̬
        setLastSelectedLevel(1);

    // ������ Level 1 ��ť���߼�
    Director::getInstance()->replaceScene(LevelSceneOne::createWithData(NULL));
}

void LevelSelectScene::level2Callback(cocos2d::Ref* pSender) {

   //��¼״̬
    setLastSelectedLevel(2);
   
    //������ Level 2 ��ť���߼�
   //Director::getInstance()->replaceScene(LevelSceneTwo::createWithData(NULL));
}


void LevelSelectScene::returnToMainMenuCallback(cocos2d::Ref* pSender) {
    // ���������ذ�ť���߼�
    Director::getInstance()->replaceScene(StartScene::create());
}
