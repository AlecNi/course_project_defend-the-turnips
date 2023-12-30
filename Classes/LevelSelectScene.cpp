// LevelSelectScene.cpp

#include "LevelSelectScene.h"
#include "StartScene.h" // ������ʼ������ͷ�ļ�

USING_NS_CC;



Scene* LevelSelectScene::createScene()
{
    return LevelSelectScene::create();
}

int LevelSelectScene::getLastSelectedLevel() {
    return lastSelectedLevel;
}


bool LevelSelectScene::init() {
    if (!Scene::init()) {
        return false;
    }

    createBackground();
    createLabel();
    positionUIElements();

    return true;
}

void LevelSelectScene::createBackground() {
    // ���������ñ���ͼƬ
    auto background = Sprite::create("background.jpg"); // �滻 "background.jpg" Ϊ��ı���ͼƬ�ļ�·��
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    addChild(background);
}

void LevelSelectScene::createLabel() {
    // ���������ñ�ǩ
    auto label = Label::createWithTTF("Level Select", "fonts/arial.ttf", 36); // �滻 "fonts/arial.ttf" Ϊ��������ļ�·��
    label->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height - 50));
    addChild(label);
}

void LevelSelectScene::positionUIElements() {
    // ���ð�ťλ��

    // Level 1 Button
    auto level1Button = MenuItemImage::create("level1_button_normal.png", "level1_button_selected.png", CC_CALLBACK_1(LevelSelectScene::level1Callback, this));
    level1Button->setPosition(Vec2(200, 300));

    // Level 2 Button
    auto level2Button = MenuItemImage::create("level2_button_normal.png", "level2_button_selected.png", CC_CALLBACK_1(LevelSelectScene::level2Callback, this));
    level2Button->setPosition(Vec2(600, 300));

    // Level 3 Button
    auto level3Button = MenuItemImage::create("level3_button_normal.png", "level3_button_selected.png", CC_CALLBACK_1(LevelSelectScene::level3Callback, this));
    level3Button->setPosition(Vec2(1000, 300));

    // Return to Main Menu Button
    auto returnButton = MenuItemImage::create("return_button_normal.png", "return_button_selected.png", CC_CALLBACK_1(LevelSelectScene::returnToMainMenuCallback, this));
    returnButton->setPosition(Vec2(500, 100));

    // �����˵�
    auto menu = Menu::create(level1Button, level2Button, level3Button, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
}

void LevelSelectScene::level1Callback(cocos2d::Ref* pSender) {

    //��¼״̬
    LevelSelectScene::lastSelectedLevel = 1;

    // ������ Level 1 ��ť���߼�
    Director::getInstance()->replaceScene(LevelOneScene::createScene());
}

void LevelSelectScene::level2Callback(cocos2d::Ref* pSender) {

    //��¼״̬
    LevelSelectScene::lastSelectedLevel = 2;
    
    // ������ Level 2 ��ť���߼�
    Director::getInstance()->replaceScene(LevelTwoScene::createScene());
}

void LevelSelectScene::level3Callback(cocos2d::Ref* pSender) {

    //��¼״̬
    LevelSelectScene::lastSelectedLevel = 3;

    // ������ Level 3 ��ť���߼�
    Director::getInstance()->replaceScene(LevelThreeScene::createScene());
}

void LevelSelectScene::returnToMainMenuCallback(cocos2d::Ref* pSender) {
    // ���������ذ�ť���߼�
    Director::getInstance()->replaceScene(StartScene::create());
}
