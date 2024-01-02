// 2023 12 29 �����ҵ�θ 2253230 ������
// GameWinScene.cpp

#include "GameWinScene.h"
#include "LevelSelectScene.h" 

USING_NS_CC;

GameWinScene::GameWinScene()
{

}

GameWinScene::~GameWinScene()
{

}

Scene* GameWinScene::createScene()
{
    return GameWinScene::create();
}

bool GameWinScene::init() {
    if (!Scene::init()) {
        return false;
    }

    createBackground();
    positionUIElements();

    return true;
}

void GameWinScene::createBackground() {
    // ��������ͼƬ
    auto background = Sprite::create("GWS_1.jpg");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(background);
    background->setContentSize(Size(960, 640));
}

void GameWinScene::positionUIElements() {
    // ��Ӱ�ť
    auto nextButton = MenuItemImage::create("GWS_2.PNG", "GWS_3.PNG", CC_CALLBACK_1(GameWinScene::TurnToNextLevelCallback, this));
    nextButton->setPosition(Vec2(200, 100));

    auto returnButton = MenuItemImage::create("GWS_4.PNG", "GWS_5.PNG", CC_CALLBACK_1(GameWinScene::returnToLevelSelectCallback, this));
    returnButton->setPosition(Vec2(700, 100));

    auto menu = Menu::create(nextButton, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
}

void GameWinScene::showAndDismissImage(float dt) {
    // �Ƴ�СͼƬ
    if (winImage) {
        winImage->removeFromParent();
        winImage = nullptr;
    }
}


void GameWinScene::TurnToNextLevelCallback(cocos2d::Ref* pSender) {
    //��ȡ��ǰ�ؿ�����Ȼ�������һ�ؿ�
    switch (LevelSelectScene::getLastSelectedLevel()) {
        case 1:
            //Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSceneTwo::createWithData(NULL)));
            break;
        case 2:
            auto winImage = Sprite::create("SmallImage.png"); 
            winImage->setPosition(Vec2(300, 100));
            this->addChild(winImage);
   
            // ʹ�ö�ʱ�����������ú����Ƴ�СͼƬ
            this->scheduleOnce(CC_SCHEDULE_SELECTOR(GameWinScene::showAndDismissImage), 2.0f);
            break;
    }
}

void GameWinScene::returnToLevelSelectCallback(Ref* pSender) {
    // �л����ؿ�ѡ�����
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSelectScene::create()));
}


