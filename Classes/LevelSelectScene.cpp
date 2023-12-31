// LevelSelectScene.cpp

#include "LevelSelectScene.h"
//#include "DataTransTool.h"
#include "LevelSceneOne.h"
//#include "LevelSceneTwo.h"
#include "StartScene.h" // 包含开始场景的头文件

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
    // 创建并设置背景图片
    auto background = Sprite::create("LSS_1.PNG"); // 替换 "background.jpg" 为你的背景图片文件路径
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    addChild(background);
    background->setContentSize(Size(960, 640));
}

void LevelSelectScene::positionUIElements() {
    // 设置按钮位置

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

    // 创建菜单
    auto menu = Menu::create(level1Button, level2Button, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
}

void LevelSelectScene::level1Callback(cocos2d::Ref* pSender) {

     //记录状态
        setLastSelectedLevel(1);

    // 处理点击 Level 1 按钮的逻辑
    Director::getInstance()->replaceScene(LevelSceneOne::createWithData(NULL));
}

void LevelSelectScene::level2Callback(cocos2d::Ref* pSender) {

   //记录状态
    setLastSelectedLevel(2);
   
    //处理点击 Level 2 按钮的逻辑
   //Director::getInstance()->replaceScene(LevelSceneTwo::createWithData(NULL));
}


void LevelSelectScene::returnToMainMenuCallback(cocos2d::Ref* pSender) {
    // 处理点击返回按钮的逻辑
    Director::getInstance()->replaceScene(StartScene::create());
}
