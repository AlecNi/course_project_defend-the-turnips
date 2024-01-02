// 2023 12 27 红焖我的胃 2253230 张正阳
// GameLoseScene.cpp

#include "GameLoseScene.h"
#include "LevelSelectScene.h"
#include "LevelSceneOne.h"
#include "DataTransTool.h"

USING_NS_CC;

GameLoseScene::GameLoseScene()
{

};
GameLoseScene::~GameLoseScene()
{

};

Scene* GameLoseScene::createScene()
{
    return GameLoseScene::create();
}

bool GameLoseScene::init() {
    if (!Scene::init()) {
        return false;
    }

    createBackground();
    positionUIElements();

    return true;
}

void GameLoseScene::createBackground() {
    // 创建背景图片
    auto background = Sprite::create("GLS_1.jpg");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(background);
    background->setContentSize(Size(960, 640));
}

void GameLoseScene::positionUIElements() {
    // 添加按钮
    auto retryButton = MenuItemImage::create("GLS_2.png", "GLS_2.PNG", CC_CALLBACK_1(GameLoseScene::retryLevelCallback, this));
    retryButton->setPosition(Vec2(200, 100));
    retryButton->setScale(0.5);

    auto returnButton = MenuItemImage::create("GLS_3.PNG", "GLS_4.PNG", CC_CALLBACK_1(GameLoseScene::returnToLevelSelectCallback, this));
    returnButton->setPosition(Vec2(700, 100));

    auto menu = Menu::create(retryButton, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
}

void GameLoseScene::retryLevelCallback(Ref* pSender) {
    //获取当前关卡数，然后进行重玩
    switch (LevelSelectScene::getLastSelectedLevel()) {
        case 1:
            Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSceneOne::createWithData(openFile("LevelOne.txt"))));
            break;
        case 2:
            //Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSceneTwo::createWithData(NULL)));
            break;
        default:
            break;
    }
}

void GameLoseScene::returnToLevelSelectCallback(Ref* pSender) {
    // 切换到关卡选择界面
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSelectScene::create()));
}


