/*
2251918 ����ΰ 2023 12 25 ver1.0
*/
/*
ver1.0 ����Ѫ����
ver1.1 �޸���create�ӿں�init�ӿڵĲ���������
	   �޸��˱�������
ver1.2 �޸���create�ӿں�init�ӿڵĲ�������ʹ��Ĭ��ֵ
*/

#ifndef __CMONSTER_HP_UI_H__
#define __CMONSTER_HP_UI_H__

#include "cocos2d.h"
USING_NS_CC;

class CMonsterHpUI : public cocos2d::Node {
public:
    CMonsterHpUI();
    ~CMonsterHpUI();

    virtual bool init() override;

    // ����Ѫ���ٷֱȣ�0.0��1.0��
    void setHealth(float flPercentage);

    CREATE_FUNC(CMonsterHpUI);

private:
    // ����Ѫ����ʾ
    void updateCMonsterHpUI();

private:
    cocos2d::Sprite* background; // ����
    cocos2d::Sprite* bar;        // Ѫ��
    CC_SYNTHESIZE(float, m_flMyRate, MyRate);             // Ѫ���ٷֱ�
};

#endif // __CMONSTER_HP_UI_H__
