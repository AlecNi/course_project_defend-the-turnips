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
    
    //�ܲ����ݳ�ʼ��
    //�����ݳ�ʼ��

    // ���ñ���ͼ
    setBackground();
    setTopBackground();
    setStartPosition();


    //���ü��ٰ�ť����ͣ��ť
    setInitButton();

    //��ұ�ǩ
    createLabel();

    //��������ʱ
    showCountdown();


    return true;
}

    // ���ñ���ͼ
void LevelSceneOne::setBackground() {

    auto background = Sprite::create("LSO_1.png");
    background->setPosition(Director::getInstance()->getVisibleOrigin() + Director::getInstance()->getVisibleSize() / 2);
    background->setContentSize(Size(960, 640));
    this->addChild(background);
}

void LevelSceneOne::setTopBackground() {
    auto topBackground = Sprite::create("LSO_14.png");
    // ��ȡ��Ļ�ɼ������ԭ��ʹ�С
    auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // ��ȡͼƬ�Ĵ�С
    auto imageSize = topBackground->getContentSize();

    // ����ͼƬλ��Ϊ�������Ϸ�����λ��
    topBackground->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height - imageSize.height / 2));

    // ��ͼƬ��ӵ�������
    this->addChild(topBackground);

}

    // ���ó��ֿ�ͼƬ
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



    // ���ü��ٰ�ť����ͣ��ť
void LevelSceneOne::setInitButton() {
    // ���ü��ٰ�ť
    accelerateButton = MenuItemImage::create("LSO_2.PNG", "LSO_2.PNG", CC_CALLBACK_1(LevelSceneOne::accelerateGame, this));
    accelerateButton->setPosition(Vec2(560,600));
    auto menu1 = Menu::create(accelerateButton, nullptr);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1);

    // ������ͣ��ť
    pauseButton = MenuItemImage::create("LSO_4.PNG", "LSO_4.PNG", CC_CALLBACK_1(LevelSceneOne::pauseGame, this));
    pauseButton->setPosition(Vec2(750, 600));
    auto menu2 = Menu::create(pauseButton, nullptr);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2);
}

    //����������
bool LevelSceneOne::listenerStart() {

    // ����������¼�����
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(LevelSceneOne::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // ����ÿһ֡�ĸ��º���
    this->scheduleUpdate();

    return true;
}


void LevelSceneOne::onMouseDown(Event* event) {
    EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
    if (mouseEvent) {
        // ��ȡ������¼�������
        Vec2 mousePos = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
        std::vector<int> position=trans_xy_to_ij(mousePos);
        if (gameMap[position[0]][position[1]] == 0)
        {
            m_pTowerMgr->Memu(trans_ij_to_xy(position[0], position[1]));
        }
    }
    return;
}




        //����ʱ
void LevelSceneOne::showCountdown() {
    // ��������ͼƬ
    auto image1 = cocos2d::Sprite::create("LSO_8.PNG");

    // ���ó�ʼλ��
    image1->setPosition(Director::getInstance()->getVisibleOrigin() + Director::getInstance()->getVisibleSize() / 2);

    // ��ͼƬ��ӵ�����ͼ����
    this->addChild(image1);
    //// ʹ�ö�ʱ����3����ִ�е���ʱ
    //this->scheduleOnce([this, image1, image2, image3](float dt) {
    //    // ��0�룬���õ�һ��ͼƬ
    //    
    //    }, 0.0f, "countdown_key");

    this->scheduleOnce([this, image1](float dt) {
        // ��1�룬���õڶ���ͼƬ�������µ�һ��ͼƬ
        image1->setTexture("LSO_9.PNG");
        }, 1.0f, "countdown_key_1");

    this->scheduleOnce([this, image1](float dt) {
        // ��2�룬���õ�����ͼƬ�������µڶ���ͼƬ
        image1->setTexture("LSO_10.PNG");
        }, 2.0f, "countdown_key_2");

    this->scheduleOnce([this, image1](float dt) {
        // ��3�룬���µ�����ͼƬ
        image1->setVisible(false);

    // ��������ӵ���ʱ��������߼������緵��1
    //this->Start();
        }, 3.0f, "countdown_key_3");
}

    //��Ϸ��ʼ
//void LevelSceneOne::Start() {
//
//    listenerStart();
//}

        //���ٰ�ť��Ӧ
void LevelSceneOne::accelerateGame(Ref* sender) {

    float currentScale = Director::getInstance()->getScheduler()->getTimeScale();
   
    // ���ݰ�ť״̬���ò�ͬ��ͼƬ
    if ((int)currentScale % 2) {
        
        accelerateButton->setNormalImage(Sprite::create("LSO_3.PNG"));
    }
    else {
        accelerateButton->setNormalImage(Sprite::create("LSO_2.PNG"));
    }

    // �л�����һ����
    float newScale = (currentScale == 1.0f) ? 2.0f : 1.0f;

    // �����µ�ʱ����������
    Director::getInstance()->getScheduler()->setTimeScale(newScale);

}

        //��ͣ��ť��Ӧ
void LevelSceneOne::pauseGame(Ref* sender) {

    // ����ť2����¼�����ͣ��Ϸ������ʾ��ͣͼƬ
    Director::getInstance()->pause();

    pauseButton->setEnabled(false);

    // ������ͣͼƬ
    pauseImage = Sprite::create("LSO_5.png");
    pauseImage->setPosition(Director::getInstance()->getVisibleOrigin() + Director::getInstance()->getVisibleSize() / 2);
    this->addChild(pauseImage, 2);

    // ���÷�����Ϸ��ť
    auto resumeButton = MenuItemImage::create("LSO_6.PNG", "LSO_7.PNG", CC_CALLBACK_1(LevelSceneOne::resumeGame, this));
    resumeButton->setPosition(Vec2(210, 90));
    auto menu3 = Menu::create(resumeButton, nullptr);
    menu3->setPosition(Vec2::ZERO);
    pauseImage->addChild(menu3);

    // �����˳���Ϸ��ť
    auto quitButton = MenuItemImage::create("LSO_12.PNG", "LSO_13.PNG", CC_CALLBACK_1(LevelSceneOne::quitGame, this));
    quitButton->setPosition(Vec2(210, 280));
    auto menu4 = Menu::create(quitButton, nullptr);
    menu4->setPosition(Vec2::ZERO);
    pauseImage->addChild(menu4);

    //�������水ť
    auto restartButton = MenuItemImage::create("LSO_15.PNG", "LSO_16.PNG", CC_CALLBACK_1(LevelSceneOne::restartGame, this));
    restartButton->setPosition(Vec2(210, 185));
    auto menu5 = Menu::create(restartButton, nullptr);
    menu5->setPosition(Vec2::ZERO);
    pauseImage->addChild(menu5);
}

    //���ý�ұ�ǩ
void LevelSceneOne::createLabel() {

   // std::string str = std::to_string(CGold::getGolds());
    // ��������ұ�ǩ
    std::string str = "100";
    auto label = Label::createWithTTF(str, "Marker Felt.ttf", 32);

    // ���ñ�ǩ��λ��
    label->setPosition(Vec2(115, 605));

    // ����ǩ��ӵ�������
    this->addChild(label, 2);
}

    // ����ָ���Ϸ��ť����¼���������Ϸ��������Ϸ����
void LevelSceneOne::resumeGame(Ref* sender) {

    Director::getInstance()->resume();
    this->removeChild(pauseImage);
    pauseButton->setEnabled(true);
}

        // �����˳���ť����¼����˳���ǰ����������LevelSelectScene
void LevelSceneOne::quitGame(Ref* sender) {

    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(LevelSelectScene::createScene());
    pauseButton->setEnabled(true);
}

        //�������水ť��������Ϸ���������³�ʼ��������
void LevelSceneOne::restartGame(Ref* sender)
{
    pauseButton->setEnabled(true);
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(createWithData(NULL));//�޸�
}