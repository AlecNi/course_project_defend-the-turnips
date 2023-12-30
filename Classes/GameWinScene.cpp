// 2023 12 29 �����ҵ�θ 2253230 ������
// GameWinScene.cpp

#include "GameWinScene.h"
#include "LevelSelectScene.h" 

USING_NS_CC;

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
    auto background = Sprite::create("your_failed_background_image.png");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(background);
}

void GameWinScene::positionUIElements() {
    // ��Ӱ�ť
    auto nextButton = MenuItemImage::create("next_button_normal.png", "next_button_selected.png", CC_CALLBACK_1(GameWinScene::TurnToNextLevelCallback, this));
    nextButton->setPosition(Vec2(200, 100));

    auto returnButton = MenuItemImage::create("return_button_normal.png", "return_button_selected.png", CC_CALLBACK_1(GameWinScene::returnToLevelSelectCallback, this));
    returnButton->setPosition(Vec2(400, 100));

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
    // ��ȡ��ǰ�ؿ�����Ȼ�������һ�ؿ�
    switch (LevelSelectScene::getLastSelectedLevel()) {
        case 1:
            Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelTwoScene::createScene()));
            break;
        case 2:
            Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelThreeScene::createScene()));
            break;
        case 3:
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


