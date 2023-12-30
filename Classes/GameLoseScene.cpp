// 2023 12 27 红焖我的胃 2253230 张正阳
// GameLoseScene.cpp

#include "GameLoseScene.h"
#include "LevelSelectScene.h"

USING_NS_CC;

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
    auto background = Sprite::create("your_failed_background_image.png");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(background);
}

void GameLoseScene::positionUIElements() {
    // 添加按钮
    auto retryButton = MenuItemImage::create("retry_button_normal.png", "retry_button_selected.png", CC_CALLBACK_1(GameLoseScene::retryLevelCallback, this));
    retryButton->setPosition(Vec2(200, 100));

    auto returnButton = MenuItemImage::create("return_button_normal.png", "return_button_selected.png", CC_CALLBACK_1(GameLoseScene::returnToLevelSelectCallback, this));
    returnButton->setPosition(Vec2(400, 100));

    auto menu = Menu::create(retryButton, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
}

void GameLoseScene::retryLevelCallback(Ref* pSender) {
    // 获取当前关卡数，然后进行重玩
    switch (LevelSelectScene::getLastSelectedLevel()) {
        case 1:
            Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelOneScene::createScene()));
            break;
        case 2:
            Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelTwoScene::createScene()));
            break;
        case 3:
            Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelThreeScene::createScene()));
            break;
        default:
            break;
    }
}

void GameLoseScene::returnToLevelSelectCallback(Ref* pSender) {
    // 切换到关卡选择界面
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSelectScene::create()));
}


