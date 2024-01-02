// 2023 12 27 �����ҵ�θ 2253230 ������
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
    // ��������ͼƬ
    auto background = Sprite::create("GLS_1.jpg");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(background);
    background->setContentSize(Size(960, 640));
}

void GameLoseScene::positionUIElements() {
    // ��Ӱ�ť
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
    //��ȡ��ǰ�ؿ�����Ȼ���������
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
    // �л����ؿ�ѡ�����
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSelectScene::create()));
}


