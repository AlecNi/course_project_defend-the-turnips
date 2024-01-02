/*
* ���ʶ� 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/31 ver1.2
*
* �ܲ���ʵ���ļ�
*/
#include <string>
#include "carrot.h"
#include "MonsterMgr.h"

CCarrot::CCarrot()
{

}

CCarrot::~CCarrot()
{
    removeChild(m_pMyHpUI, true);
}

CCarrot* CCarrot::create()
{
    CCarrot* new_carrot = new CCarrot;

    if (new_carrot != nullptr)
        if (new_carrot->init())
            return new_carrot;
        else
            delete new_carrot;

    return nullptr;
}

bool CCarrot::init()
{
    if (!cocos2d::Sprite::init()) {
        return false;
    }

    
    /* ģ�����Ѫ��
this->schedule([this](float dt) {
if(�˴���������жϾ����Ƿ�Զ)
trumble();
    }, 1.0f, "trumbling");
    */

    
    setTexture("HP_MAX.PNG");

    auto sprite = cocos2d::Sprite::create("Hp.PNG");
    if (sprite) {
        sprite->setPosition(cocos2d::Vec2(25, -20));
        addChild(sprite);
    }
    else
        return false;

    m_iMyHp = 10;

    m_pMyHpUI = cocos2d::Label::createWithTTF(std::to_string(m_iMyHp), "fonts//arial.ttf", 24);
    if (m_pMyHpUI != nullptr) {
        m_pMyHpUI->setPosition(cocos2d::Vec2(40, -20));

        m_pMyHpUI->setString(std::to_string(m_iMyHp));
        addChild(m_pMyHpUI);

        return true;
    }
    return false;
}

CCarrot* CCarrot::createWithData(cocos2d::Vec2 pos, CMonsterMgr* mgr)
{
    auto carrot = CCarrot::create();

    if (carrot != nullptr) {
        carrot->setPosition(pos);
        carrot->m_pMyMonsterMgr = mgr;

        return carrot;
    }
    return nullptr;
}

bool CCarrot::updateDamage()
{
    return false;
    std::vector<CMonster*> vec_mon;
    m_pMyMonsterMgr->getActiveMonsterList(vec_mon);
    for (int i = 0; i < vec_mon.size(); ++i)
    {
        if (vec_mon[i]->getDistanceToCarrot() <= 10)
            if (damage(vec_mon[i]))
                return true;
    }
    return false;
}

bool CCarrot::damage(CMonster* monster)
{
    m_iMyHp -= monster->getMyDeHealth();
    monster->deathBehavior();

    if (m_iMyHp <= 0) {
        m_pMyHpUI->setString("Hp: 0");
        return true;
    }
    else {
        m_pMyHpUI->setString(std::to_string(m_iMyHp));

        if (m_iMyHp == 5 || m_iMyHp == 6) {
            auto newTexture = cocos2d::Director::getInstance()->getTextureCache()->addImage("HP_5-6.PNG");

            if (newTexture != nullptr)
            setTexture(newTexture);
        }
        else if (m_iMyHp == 7 || m_iMyHp == 8) {
            auto newTexture = cocos2d::Director::getInstance()->getTextureCache()->addImage("HP_7-8.PNG");

            if (newTexture != nullptr)
            setTexture(newTexture);
        }
        else {
            auto newTexture = cocos2d::Director::getInstance()->getTextureCache()->addImage("HP_"+ std::to_string(m_iMyHp) +".PNG");

            if (newTexture != nullptr)
                setTexture(newTexture);
        }

        return false;
    }
}