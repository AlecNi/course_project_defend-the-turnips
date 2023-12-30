// 2023 12 17 红焖我的胃 2253230 张正阳
// 开始场景的实现

#include "StartScene.h"
#include "LevelSelectScene.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    return StartScene::create();
}


bool StartScene::init() {
    if (!Scene::init()) {
        return false;
    }

    createBackground();
    positionUIElements();

    return true;
}

void StartScene::createBackground() {
    // 用你实际的背景图片文件名替换 "SS_start_background.png"
    auto background = Sprite::create("SS_start_background.png");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    addChild(background);
}


void StartScene::positionUIElements() {
    // 创建“开始游戏”按钮
    auto startButton = MenuItemImage::create("start_button_normal.png", "start_button_selected.png", CC_CALLBACK_1(StartScene::startGameCallback, this));
    startButton->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 2));

    // 创建“退出游戏”按钮
    auto quitButton = MenuItemImage::create("quit_button_normal.png", "quit_button_selected.png", CC_CALLBACK_1(StartScene::quitGameCallback, this));
    quitButton->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 3));

    // 创建菜单，包含两个按钮
    auto menu = Menu::create(startButton, quitButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
}

void StartScene::startGameCallback(Ref* pSender) {
    // 跳转到关卡选择界面
    Director::getInstance()->replaceScene(LevelSelectScene::create());
}

void StartScene::quitGameCallback(Ref* pSender) {
    // 结束游戏
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
