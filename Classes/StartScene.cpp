// 2023 12 17 �����ҵ�θ 2253230 ������
// ��ʼ������ʵ��

#include "StartScene.h"
#include "LevelSelectScene.h"



USING_NS_CC;

StartScene::StartScene()
{

}

StartScene::~StartScene()
{

}

Scene* StartScene::createScene()
{
    return StartScene::create();
}


bool StartScene::init() {
    if (!Scene::init()) {
        return false;
    }

    createALL();

    return true;
}

void StartScene::createALL() {
    // ����ʵ�ʵı���ͼƬ�ļ����滻 "SS_start_background.png"
    auto background = Sprite::create("SS_start_background.png");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    addChild(background);
    background->setContentSize(Size(960, 640));

    auto overlayLayer = Layer::create();
    addChild(overlayLayer);
    // ���ͼƬ (a)
    auto SS_MainTitle = Sprite::create("SS_MainTitle.png");  
    SS_MainTitle->setPosition(Vec2(500, 300));  // ����ͼƬ (a) ��λ��
    SS_MainTitle->setScale(0.7);
    overlayLayer->addChild(SS_MainTitle);

    // ��Ӱ�ť (b)
    auto startButton = MenuItemImage::create("SS_1.png", "SS_2.png", CC_CALLBACK_1(StartScene::startGameCallback, this));
    startButton->setPosition(Vec2(580,120));
    startButton->setScale(0.9);

    // ��Ӱ�ť (c)
    auto quitButton = MenuItemImage::create("SS_3.png", "SS_4.png", CC_CALLBACK_1(StartScene::quitGameCallback, this));
    quitButton->setPosition(Vec2(320,120));
    quitButton->setScale(1.2);


    // �����˵���������ť��ӵ��˵���
    auto menu = Menu::create(startButton, quitButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    overlayLayer->addChild(menu);
}

void StartScene::startGameCallback(Ref* pSender) {
    //��ת���ؿ�ѡ�����
   Director::getInstance()->replaceScene(LevelSelectScene::create());
}

void StartScene::quitGameCallback(Ref* pSender) {
    // ������Ϸ
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
