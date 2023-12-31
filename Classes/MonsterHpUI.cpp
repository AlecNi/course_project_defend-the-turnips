/*
2251918����ΰ 2023 12 29 ver1.0
*/



#include "MonsterHpUI.h"
#include "DataMgr.h"

USING_NS_CC;

CMonsterHpUI::CMonsterHpUI() : m_flMyRate(1.0f) 
{

}

bool CMonsterHpUI::init() {
    if (!Node::init()) {
        return false;
    }

    // �����ײ�����
    background = Sprite::create("background_image.png"); 
    addChild(background);

    // ����Ѫ��
    bar = Sprite::create("bar_image.png"); 
    addChild(bar);

    updateCMonsterHpUI();

    return true;
}

void CMonsterHpUI::setHealth(float flPercentage) 
{
    m_flMyRate = clampf(flPercentage, 0.0f, 1.0f);
    updateCMonsterHpUI();
}

void CMonsterHpUI::updateCMonsterHpUI() {
    if (bar) {
        bar->setScaleX(m_flMyRate);
    }
}