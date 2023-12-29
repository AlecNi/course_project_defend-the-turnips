/*
* ���ʶ�
*
* 2023/12/25
* 2023/12/29
*
* �ܲ���ʵ���ļ�
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

    // ����һ�� Text ����
    m_pMyHpUI = cocos2d::ui::Text::create();
    m_pMyHpUI->setPosition(cocos2d::Vec2(240, 160));
    m_pMyHpUI->setFontSize(24);

    m_pMyHpUI->setString("Hp: " + std::to_string(m_iMyHp));

    /* ģ�����Ѫ��
    this->schedule([this](float dt) {
    if(�˴���������жϾ����Ƿ�Զ)
    trumble();
        }, 1.0f, "trumbling");
        */

    return true;
}


inline bool CCarrot::damage(int iDamageHealth)
{
	m_iMyHp -= iDamageHealth;


    if (m_iMyHp <= 0) {
        m_pMyHpUI->setString("Hp: 0");
        return false;
    }
    else {
        m_pMyHpUI->setString("Hp: " + std::to_string(m_iMyHp));
        return true;
    }
}