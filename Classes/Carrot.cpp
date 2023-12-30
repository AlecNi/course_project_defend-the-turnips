/*
* ���ʶ�
*
* 2023/12/25
* * 2023/12/29
*
* �ܲ���ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
*
* �ܲ�������ͬ���ӽ��ڹ�������ֳ���
*/
#include "Carrot.h"
#include "CarrotMgr.h"

inline bool CCarrotMgr::init()
{
    if (!Scene::init()){
        return false;
    }

    // ����һ�� Text ����
    auto label = cocos2d::ui::Text::create();
    label->setString("Hp: " + std::to_string(m_CMyCarrot->getMyHp()));
    label->setPosition(cocos2d::Vec2(240, 160));
    label->setFontSize(24);
    this->addChild(label);

    // ģ����·���
    int Hp = m_CMyCarrot->getMyHp();
    this->schedule([label, &Hp, this] (float dt) {
        // ģ����·�����ÿ��һ������10��
        Hp = m_CMyCarrot->getMyHp();
    label->setString("Hp: " + std::to_string(Hp));
        }, 1.0f, "update_score");

    return true;
}