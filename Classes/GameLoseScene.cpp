// 2023 12 27 �����ҵ�θ 2253230 ������
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
    // ��������ͼƬ
    auto background = Sprite::create("your_failed_background_image.png");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(background);
}

void GameLoseScene::positionUIElements() {
    // ��Ӱ�ť
    auto retryButton = MenuItemImage::create("retry_button_normal.png", "retry_button_selected.png", CC_CALLBACK_1(GameLoseScene::retryLevelCallback, this));
    retryButton->setPosition(Vec2(200, 100));

    auto returnButton = MenuItemImage::create("return_button_normal.png", "return_button_selected.png", CC_CALLBACK_1(GameLoseScene::returnToLevelSelectCallback, this));
    returnButton->setPosition(Vec2(400, 100));

    auto menu = Menu::create(retryButton, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
}

void GameLoseScene::retryLevelCallback(Ref* pSender) {
    // ��ȡ��ǰ�ؿ�����Ȼ���������
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
    // �л����ؿ�ѡ�����
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSelectScene::create()));
}


