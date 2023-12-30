/*
* ���ʶ� 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/31 ver1.2
*
* �ܲ���ʵ���ļ�
*/
#include "Carrot.h"

CCarrot::~CCarrot()
{
    removeChild(m_pMyHpUI);
}

inline bool CCarrot::init()
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

    m_iMyHp = 10;

    // ����һ�� Text ����
    m_pMyHpUI = cocos2d::ui::Text::create();
    m_pMyHpUI->setPosition(cocos2d::Vec2(240, 160));
    m_pMyHpUI->setFontSize(24);

    m_pMyHpUI->setString("Hp: " + std::to_string(m_iMyHp));
    addChild(m_pMyHpUI);

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