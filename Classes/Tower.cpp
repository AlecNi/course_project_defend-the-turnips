/*
* 倪朗恩 2251334
*
* 2023/12/29 ver1.0
* 2023/12/30 ver1.1
*
* 塔的实现文件
*/
#include <cmath>
#include "Tower.h"
#include "Bullet.h"
#include "Monster.h"
#include "DataMgr.h"

CGeneralTower::~CGeneralTower()
{
	while (!m_rgMyActiveBullet.empty()) {
		removeChild(m_rgMyActiveBullet.back(), true);

		m_rgMyActiveBullet.pop_back();
	}
}

void CGeneralTower::initByModel()
{
	m_fMyAttackPeriod = m_pMyModel->m_pMyBaseAttackPeriod[m_iMyLevel - 1];

	m_iMyAttack = m_pMyModel->m_pMyBaseAttack[m_iMyLevel - 1];

	m_fMyAttackRage = m_pMyModel->m_pMyAttackRage[m_iMyLevel - 1];

	m_fMyBarrelLen = m_pMyModel->m_fMyBarrelLen[m_iMyLevel - 1];
}

inline CGeneralTower* CGeneralTower::createWithData(SGeneralTowerModel* model, CTowerMgr* mgr, int level)
{
	auto tower = CGeneralTower::create();

	if (tower != nullptr) {
		tower->m_pMyModel = model;
		tower->m_pTowerMgr = mgr;
		tower->m_iMyLevel = level;

		return tower;
	}

	return nullptr;
}

inline CBullet* CGeneralTower::attack(CMonster* target, float dt)
{
	auto iter = m_rgMyActiveBullet.begin();

	for (; iter != m_rgMyActiveBullet.end();) {

		/*只攻击目标的逻辑*/
		if ((*iter)->getIsActive() == false) {
			auto tmp_iter = iter;

			m_rgMyActiveBullet.erase(iter++);

			removeChild(*tmp_iter, true);
		}
		else
			++iter;
	}

	return rotate(target, dt);
}

inline CBullet* CGeneralTower::rotate(CMonster* target, float dt)
{
	/*获得各种角度，mon_ang，my_ang在0~360，delta_ang在0~180*/
	float mon_ang = CC_RADIANS_TO_DEGREES((target->getPosition() - getPosition()).getAngle());
	float my_ang = getRotation();
	mon_ang -= 360.0 * static_cast<int>(mon_ang / 360.0);
	my_ang -= 360.0 * static_cast<int>(my_ang / 360.0);
	mon_ang += 360.0;
	my_ang += 360.0;
	mon_ang -= 360.0 * static_cast<int>(mon_ang / 360.0);
	my_ang -= 360.0 * static_cast<int>(my_ang / 360.0);

	float delta_ang = std::fabs(mon_ang - my_ang);
	delta_ang -= static_cast<float>(delta_ang / 180.0) * 360.0;

	if (std::fabs(delta_ang)
		< dt * m_pMyModel->m_pMyBaseAngularV) {
		/*旋转*/
		setRotation(mon_ang);

		if (m_fMyChargeTime > m_fMyAttackPeriod) {
			auto bullet = CBullet::createWithData(m_pMyModel->m_pMyBullet + m_iMyLevel - 1, this);

			if (bullet == nullptr)
				return nullptr;

			bullet->setAimedMonster(target);  //设置攻击目标

			bullet->setFatherTower(this);  //设置发射该子弹的塔

			bullet->initWithData(m_pMyModel->m_pMyBullet);  //初始化

			bullet->setRotation(getRotation());  //子弹朝向

			bullet->setBulletDamage(m_iMyAttack);  //设置子弹伤害

			addChild(bullet);

			m_fMyChargeTime = 0;

			return bullet;
		}
	}
	else
		setRotation((mon_ang - my_ang == delta_ang) || (mon_ang - my_ang == delta_ang - 360.0) ?
			my_ang + dt * m_pMyModel->m_pMyBaseAngularV : my_ang - dt * m_pMyModel->m_pMyBaseAngularV);

	return nullptr;
}

inline cocos2d::Vec2 CGeneralTower::getBarrelPos()
{
	/*弧度*/
	double angleInRadians = CC_DEGREES_TO_RADIANS(getRotation());
	cocos2d::Vec2 currentPosition = getPosition();

	return currentPosition + cocos2d::Vec2(m_fMyBarrelLen * std::cos(angleInRadians), m_fMyBarrelLen * std::sin(angleInRadians));
}

inline SGeneralTowerModel* CGeneralTower::getModel()
{
	return m_pMyModel;
}

bool CGeneralTower::upgrades()
{
	if (m_iMyLevel == m_pMyModel->m_iMyMaxLevel)
		return false;

	++m_iMyLevel;

	float m_fMyAngular = getRotation();
	
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

	return true;
}
