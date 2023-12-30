// 2023 12 17 �����ҵ�θ 2253230 ������
// ��ʼ������ʵ��

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
    // ����ʵ�ʵı���ͼƬ�ļ����滻 "SS_start_background.png"
    auto background = Sprite::create("SS_start_background.png");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    addChild(background);
}


void StartScene::positionUIElements() {
    // ��������ʼ��Ϸ����ť
    auto startButton = MenuItemImage::create("start_button_normal.png", "start_button_selected.png", CC_CALLBACK_1(StartScene::startGameCallback, this));
    startButton->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 2));

    // �������˳���Ϸ����ť
    auto quitButton = MenuItemImage::create("quit_button_normal.png", "quit_button_selected.png", CC_CALLBACK_1(StartScene::quitGameCallback, this));
    quitButton->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 3));

    // �����˵�������������ť
    auto menu = Menu::create(startButton, quitButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
}

void StartScene::startGameCallback(Ref* pSender) {
    // ��ת���ؿ�ѡ�����
    Director::getInstance()->replaceScene(LevelSelectScene::create());
}

void StartScene::quitGameCallback(Ref* pSender) {
    // ������Ϸ
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
