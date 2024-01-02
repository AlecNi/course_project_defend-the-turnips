// 2023 12 17 红焖我的胃 2253230 张正阳
// 开始场景的实现

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
    // 用你实际的背景图片文件名替换 "SS_start_background.png"
    auto background = Sprite::create("SS_start_background.png");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    addChild(background);
    background->setContentSize(Size(960, 640));

    auto overlayLayer = Layer::create();
    addChild(overlayLayer);
    // 添加图片 (a)
    auto SS_MainTitle = Sprite::create("SS_MainTitle.png");  
    SS_MainTitle->setPosition(Vec2(500, 300));  // 设置图片 (a) 的位置
    SS_MainTitle->setScale(0.7);
    overlayLayer->addChild(SS_MainTitle);

    // 添加按钮 (b)
    auto startButton = MenuItemImage::create("SS_1.png", "SS_2.png", CC_CALLBACK_1(StartScene::startGameCallback, this));
    startButton->setPosition(Vec2(580,120));
    startButton->setScale(0.9);

    // 添加按钮 (c)
    auto quitButton = MenuItemImage::create("SS_3.png", "SS_4.png", CC_CALLBACK_1(StartScene::quitGameCallback, this));
    quitButton->setPosition(Vec2(320,120));
    quitButton->setScale(1.2);


    // 创建菜单，并将按钮添加到菜单中
    auto menu = Menu::create(startButton, quitButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    overlayLayer->addChild(menu);
}

void StartScene::startGameCallback(Ref* pSender) {
    //跳转到关卡选择界面
   Director::getInstance()->replaceScene(LevelSelectScene::create());
}

void StartScene::quitGameCallback(Ref* pSender) {
    // 结束游戏
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
