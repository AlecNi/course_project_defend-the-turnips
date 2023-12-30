// LevelSelectScene.cpp

#include "LevelSelectScene.h"
#include "StartScene.h" // 包含开始场景的头文件

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
    // 创建并设置背景图片
    auto background = Sprite::create("background.jpg"); // 替换 "background.jpg" 为你的背景图片文件路径
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    addChild(background);
}

void LevelSelectScene::createLabel() {
    // 创建并设置标签
    auto label = Label::createWithTTF("Level Select", "fonts/arial.ttf", 36); // 替换 "fonts/arial.ttf" 为你的字体文件路径
    label->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height - 50));
    addChild(label);
}

void LevelSelectScene::positionUIElements() {
    // 设置按钮位置

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

    // 创建菜单
    auto menu = Menu::create(level1Button, level2Button, level3Button, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
}

void LevelSelectScene::level1Callback(cocos2d::Ref* pSender) {

    //记录状态
    LevelSelectScene::lastSelectedLevel = 1;

    // 处理点击 Level 1 按钮的逻辑
    Director::getInstance()->replaceScene(LevelOneScene::createScene());
}

void LevelSelectScene::level2Callback(cocos2d::Ref* pSender) {

    //记录状态
    LevelSelectScene::lastSelectedLevel = 2;
    
    // 处理点击 Level 2 按钮的逻辑
    Director::getInstance()->replaceScene(LevelTwoScene::createScene());
}

void LevelSelectScene::level3Callback(cocos2d::Ref* pSender) {

    //记录状态
    LevelSelectScene::lastSelectedLevel = 3;

    // 处理点击 Level 3 按钮的逻辑
    Director::getInstance()->replaceScene(LevelThreeScene::createScene());
}

void LevelSelectScene::returnToMainMenuCallback(cocos2d::Ref* pSender) {
    // 处理点击返回按钮的逻辑
    Director::getInstance()->replaceScene(StartScene::create());
}
