/*
* ���ʶ�
*
* 2023/12/29
*
* ����ʵ���ļ�
*/
#include <cmath>
#include "Tower.h"
#include "Bullet.h"
#include "DataMgr.h"

void CGeneralTower::initByModel()
{
	m_fMyAttackPeriod = m_pMyModel->m_pMyBaseAttackPeriod[m_iMyLevel - 1];

	m_iMyAttack = m_pMyModel->m_pMyBaseAttack[m_iMyLevel - 1];

	m_fMyAttackRage = m_pMyModel->m_pMyAttackRage[m_iMyLevel - 1];

	m_fMyBarrelLen = m_pMyModel->m_fMyBarrelLen[m_iMyLevel - 1];
}

CGeneralTower* CGeneralTower::initModel(SGeneralTowerModel* model)
{
	m_pMyModel = model;

	return this;
}

CBullet* CGeneralTower::shoot(CMonster* target)
{
	if (m_fMyChargeTime > m_fMyAttackPeriod) {
		auto bullet = CBullet::createWithData(m_pMyModel->m_pMyBullet + m_iMyLevel - 1);;

		bullet->setAimedMonster(target);	//���ù���Ŀ��

		m_fMyChargeTime = 0;

		return bullet;
	}
	else
		return NULL;
}

cocos2d::Vec2 CGeneralTower::getBarrelPos()
{
	/*����*/
	double angleInRadians = getRotation() * M_PI / 180.0;
	cocos2d::Vec2 currentPosition = getPosition();

	return currentPosition + cocos2d::Vec2(m_fMyBarrelLen * std::cos(angleInRadians), m_fMyBarrelLen * std::sin(angleInRadians));
}

inline SGeneralTowerModel* CGeneralTower::getModel()
{
	return m_pMyModel;
}

bool CGeneralTower::upgrades()
{
	++m_iMyLevel;
	
	// ��ȡԭʼͼƬ�Ĵ�С
	cocos2d::Size originalSize = getContentSize();

	// ����Ҫ��ʾ������������ʾͼƬ�����Ͻ��ķ�֮һ,ʵ��Ӧ������level�йصı��ʽ
	cocos2d::Rect textureRect = cocos2d::Rect(0, 0, originalSize.width / 2, originalSize.height / 2);

	// ͨ��setTextureRect����ָ��������ʾ���������
	setTextureRect(textureRect);

	// ��תΪԭ�Ƕ�
	setRotation(m_fMyAngular);

	initByModel();

	/*
	* initWithConditoin();
	*/
}
