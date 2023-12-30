// 2023 12 29 红焖我的胃 2253230 张正阳
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
    // 创建背景图片
    auto background = Sprite::create("your_failed_background_image.png");
    background->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(background);
}

void GameWinScene::positionUIElements() {
    // 添加按钮
    auto nextButton = MenuItemImage::create("next_button_normal.png", "next_button_selected.png", CC_CALLBACK_1(GameWinScene::TurnToNextLevelCallback, this));
    nextButton->setPosition(Vec2(200, 100));

    auto returnButton = MenuItemImage::create("return_button_normal.png", "return_button_selected.png", CC_CALLBACK_1(GameWinScene::returnToLevelSelectCallback, this));
    returnButton->setPosition(Vec2(400, 100));

    auto menu = Menu::create(nextButton, returnButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
}

void GameWinScene::showAndDismissImage(float dt) {
    // 移除小图片
    if (winImage) {
        winImage->removeFromParent();
        winImage = nullptr;
    }
}


void GameWinScene::TurnToNextLevelCallback(cocos2d::Ref* pSender) {
    // 获取当前关卡数，然后进入下一关卡
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

            // 使用定时器在两秒后调用函数移除小图片
            this->scheduleOnce(CC_SCHEDULE_SELECTOR(GameWinScene::showAndDismissImage), 2.0f);
            break;
    }
}

void GameWinScene::returnToLevelSelectCallback(Ref* pSender) {
    // 切换到关卡选择界面
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, LevelSelectScene::create()));
}


