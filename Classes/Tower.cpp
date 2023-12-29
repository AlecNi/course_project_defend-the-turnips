/*
* 倪朗恩
*
* 2023/12/29
*
* 塔的实现文件
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

		bullet->setAimedMonster(target);	//设置攻击目标

		m_fMyChargeTime = 0;

		return bullet;
	}
	else
		return NULL;
}

cocos2d::Vec2 CGeneralTower::getBarrelPos()
{
	/*弧度*/
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
	
	// 获取原始图片的大小
	cocos2d::Size originalSize = getContentSize();

	// 定义要显示的区域，例如显示图片的左上角四分之一,实际应该是与level有关的表达式
	cocos2d::Rect textureRect = cocos2d::Rect(0, 0, originalSize.width / 2, originalSize.height / 2);

	// 通过setTextureRect方法指定精灵显示纹理的区域
	setTextureRect(textureRect);

	// 旋转为原角度
	setRotation(m_fMyAngular);

	initByModel();

	/*
	* initWithConditoin();
	*/
}
