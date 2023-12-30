/*
* 倪朗恩 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
*
* 萝卜的实现文件
*/
#include "Carrot.h"

CCarrot::~CCarrot()
{
    delete m_pMyHpUI;
}

inline bool CCarrot::init()
{
    if (!cocos2d::Sprite::init()) {
        return false;
    }

    /* 模拟更新血量
this->schedule([this](float dt) {
if(此处遍历怪物，判断距离是否够远)
trumble();
    }, 1.0f, "trumbling");
    */

    // 创建一个 Text 对象
    m_pMyHpUI = cocos2d::ui::Text::create();
    m_pMyHpUI->setPosition(cocos2d::Vec2(240, 160));
    m_pMyHpUI->setFontSize(24);

    m_pMyHpUI->setString("Hp: " + std::to_string(m_iMyHp));

    return true;
}

inline bool CCarrot::damage(int iDamageHealth)
{
	m_iMyHp -= iDamageHealth;

    if (m_iMyHp <= 0) {
        m_pMyHpUI->setString("Hp: 0");
        return true;
    }
    else {
        m_pMyHpUI->setString("Hp: " + std::to_string(m_iMyHp));
        return false;
    }
}