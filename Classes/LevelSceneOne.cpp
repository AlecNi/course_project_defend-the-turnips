// LevelSceneOne.cpp
#include "LevelSceneOne.h"
#include "LevelSelectScene.h"
#include "DataMgr.h"
#include "carrot.h"
#include "MonsterMgr.h"
#include "TowerMgr.h"

#include "gold.h"

USING_NS_CC;

inline std::vector<int> trans_xy_to_ij(Vec2 vec) {
    return { static_cast<int>((vec.x) / 80) ,6 - static_cast<int>((vec.y) / 80) };
}

inline cocos2d::Vec2 trans_ij_to_xy(int ix, int iy) {
    cocos2d::Vec2 vec;
    vec.x = 40 + iy * 80;
    vec.y = 40 + (6 - ix) * 80;
    return vec;
}

LevelSceneOne::~LevelSceneOne() {
    delete  m_pMonsterMgr;
    m_pMonsterMgr = nullptr;
    delete  m_pGold;
    m_pGold = nullptr;
    delete  m_pTowerMgr;
    m_pTowerMgr = nullptr;
    delete  m_pCarrot;
    m_pCarrot = nullptr;
    delete  m_pLevelData;
    m_pLevelData = nullptr;
}

LevelSceneOne* LevelSceneOne::createWithData(SLevelData* pSInitData)
{
    LevelSceneOne* pLevelSceneOne = new LevelSceneOne();
    if (nullptr != pLevelSceneOne && pLevelSceneOne->initWithData(pSInitData))
    {
        pLevelSceneOne->autorelease();
        return pLevelSceneOne;
    }
    CC_SAFE_DELETE(pLevelSceneOne);
    return nullptr;
}

bool LevelSceneOne::initWithData(SLevelData* pSInitData) {

    if (!Scene::init()) {
        return false;
    }
    pSInitData = m_pLevelData;
    m_pMonsterMgr = CMonsterMgr::createWithData(m_pLevelData->m_pMonsterMgr);
    m_pGold = new CGold();
    m_pTowerMgr = CTowerMgr::createWithData(m_pLevelData->m_pTowerMgr, m_pMonsterMgr, m_pGold);
    m_pCarrot = CCarrot::createWithData(Vec2(840,440),m_pMonsterMgr);
    schedule([=](float flDelta)
        {
            if (m_pCarrot->update())
            {
                return;
            }
        }, "Failure");
    
    //萝卜数据初始化
    //塔数据初始化

    // 设置背景图
    setBackground();
    setTopBackground();
    setStartPosition();


    //设置加速按钮、暂停按钮
    setInitButton();

    //金币标签
    createLabel();

    //开启倒计时
    showCountdown();


    return true;
}

    // 设置背景图
void LevelSceneOne::setBackground() {

    auto background = Sprite::create("LSO_1.png");
    background->setPosition(Director::getInstance()->getVisibleOrigin() + Director::getInstance()->getVisibleSize() / 2);
    background->setContentSize(Size(960, 640));
    this->addChild(background);
}

void LevelSceneOne::setTopBackground() {
    auto topBackground = Sprite::create("LSO_14.png");
    // 获取屏幕可见区域的原点和大小
    auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // 获取图片的大小
    auto imageSize = topBackground->getContentSize();

    // 设置图片位置为界面最上方中心位置
    topBackground->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height - imageSize.height / 2));

    // 将图片添加到场景中
    this->addChild(topBackground);

}

    // 设置出怪口图片
void LevelSceneOne::setStartPosition() {
    auto startPosition = Sprite::create("LSO_11.PNG");
    startPosition->setPosition(Vec2(120, 440));
    this->addChild(startPosition);
}

// 840 440 .. Level 1
void LevelSceneOne::setCarrotPosition() {
    auto carrotPosition = Sprite::create("LSO_11.PNG");
    carrotPosition->setPosition(Vec2(200, 120));
    this->addChild(carrotPosition);
}



    // 设置加速按钮和暂停按钮
void LevelSceneOne::setInitButton() {
    // 设置加速按钮
    accelerateButton = MenuItemImage::create("LSO_2.PNG", "LSO_2.PNG", CC_CALLBACK_1(LevelSceneOne::accelerateGame, this));
    accelerateButton->setPosition(Vec2(560,600));
    auto menu1 = Menu::create(accelerateButton, nullptr);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1);

    // 设置暂停按钮
    pauseButton = MenuItemImage::create("LSO_4.PNG", "LSO_4.PNG", CC_CALLBACK_1(LevelSceneOne::pauseGame, this));
    pauseButton->setPosition(Vec2(750, 600));
    auto menu2 = Menu::create(pauseButton, nullptr);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2);
}

    //开启鼠标监听
bool LevelSceneOne::listenerStart() {

    // 启用鼠标点击事件监听
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(LevelSceneOne::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // 调度每一帧的更新函数
    this->scheduleUpdate();

    return true;
}


void LevelSceneOne::onMouseDown(Event* event) {
    EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
    if (mouseEvent) {
        // 获取鼠标点击事件的坐标
        Vec2 mousePos = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
        std::vector<int> position=trans_xy_to_ij(mousePos);
        if (gameMap[position[0]][position[1]] == 0)
        {
            m_pTowerMgr->Memu(trans_ij_to_xy(position[0], position[1]));
        }
    }
    return;
}




        //倒计时
void LevelSceneOne::showCountdown() {
    // 创建三张图片
    auto image1 = cocos2d::Sprite::create("LSO_8.PNG");

    // 设置初始位置
    image1->setPosition(Director::getInstance()->getVisibleOrigin() + Director::getInstance()->getVisibleSize() / 2);

    // 将图片添加到背景图层上
    this->addChild(image1);
    //// 使用定时器在3秒内执行倒计时
    //this->scheduleOnce([this, image1, image2, image3](float dt) {
    //    // 第0秒，放置第一张图片
    //    
    //    }, 0.0f, "countdown_key");

    this->scheduleOnce([this, image1](float dt) {
        // 第1秒，放置第二张图片，并撤下第一张图片
        image1->setTexture("LSO_9.PNG");
        }, 1.0f, "countdown_key_1");

    this->scheduleOnce([this, image1](float dt) {
        // 第2秒，放置第三张图片，并撤下第二张图片
        image1->setTexture("LSO_10.PNG");
        }, 2.0f, "countdown_key_2");

    this->scheduleOnce([this, image1](float dt) {
        // 第3秒，撤下第三张图片
        image1->setVisible(false);

    // 在这里添加倒计时结束后的逻辑，比如返回1
    //this->Start();
        }, 3.0f, "countdown_key_3");
}

    //游戏开始
//void LevelSceneOne::Start() {
//
//    listenerStart();
//}

        //倍速按钮响应
void LevelSceneOne::accelerateGame(Ref* sender) {

    float currentScale = Director::getInstance()->getScheduler()->getTimeScale();
   
    // 根据按钮状态设置不同的图片
    if ((int)currentScale % 2) {
        
        accelerateButton->setNormalImage(Sprite::create("LSO_3.PNG"));
    }
    else {
        accelerateButton->setNormalImage(Sprite::create("LSO_2.PNG"));
    }

    // 切换到另一倍速
    float newScale = (currentScale == 1.0f) ? 2.0f : 1.0f;

    // 设置新的时间缩放因子
    Director::getInstance()->getScheduler()->setTimeScale(newScale);

}

        //暂停按钮响应
void LevelSceneOne::pauseGame(Ref* sender) {

    // 处理按钮2点击事件，暂停游戏，并显示暂停图片
    Director::getInstance()->pause();

    pauseButton->setEnabled(false);

    // 设置暂停图片
    pauseImage = Sprite::create("LSO_5.png");
    pauseImage->setPosition(Director::getInstance()->getVisibleOrigin() + Director::getInstance()->getVisibleSize() / 2);
    this->addChild(pauseImage, 2);

    // 设置返回游戏按钮
    auto resumeButton = MenuItemImage::create("LSO_6.PNG", "LSO_7.PNG", CC_CALLBACK_1(LevelSceneOne::resumeGame, this));
    resumeButton->setPosition(Vec2(210, 90));
    auto menu3 = Menu::create(resumeButton, nullptr);
    menu3->setPosition(Vec2::ZERO);
    pauseImage->addChild(menu3);

    // 设置退出游戏按钮
    auto quitButton = MenuItemImage::create("LSO_12.PNG", "LSO_13.PNG", CC_CALLBACK_1(LevelSceneOne::quitGame, this));
    quitButton->setPosition(Vec2(210, 280));
    auto menu4 = Menu::create(quitButton, nullptr);
    menu4->setPosition(Vec2::ZERO);
    pauseImage->addChild(menu4);

    //设置重玩按钮
    auto restartButton = MenuItemImage::create("LSO_15.PNG", "LSO_16.PNG", CC_CALLBACK_1(LevelSceneOne::restartGame, this));
    restartButton->setPosition(Vec2(210, 185));
    auto menu5 = Menu::create(restartButton, nullptr);
    menu5->setPosition(Vec2::ZERO);
    pauseImage->addChild(menu5);
}

    //设置金币标签
void LevelSceneOne::createLabel() {

   // std::string str = std::to_string(CGold::getGolds());
    // 创建级金币标签
    std::string str = "100";
    auto label = Label::createWithTTF(str, "Marker Felt.ttf", 32);

    // 设置标签的位置
    label->setPosition(Vec2(115, 605));

    // 将标签添加到场景中
    this->addChild(label, 2);
}

    // 处理恢复游戏按钮点击事件，返回游戏场景，游戏继续
void LevelSceneOne::resumeGame(Ref* sender) {

    Director::getInstance()->resume();
    this->removeChild(pauseImage);
    pauseButton->setEnabled(true);
}

        // 处理退出按钮点击事件，退出当前场景，返回LevelSelectScene
void LevelSceneOne::quitGame(Ref* sender) {

    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(LevelSelectScene::createScene());
    pauseButton->setEnabled(true);
}

        //处理重玩按钮，返回游戏场景，重新初始化本场景
void LevelSceneOne::restartGame(Ref* sender)
{
    pauseButton->setEnabled(true);
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(createWithData(NULL));//修改
}