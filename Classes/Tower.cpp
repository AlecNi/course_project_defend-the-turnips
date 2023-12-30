/*
* ���ʶ� 2251334
*
* 2023/12/29 ver1.0
* 2023/12/30 ver1.1
*
* ����ʵ���ļ�
*/
#include <cmath>
#include "Tower.h"
#include "Bullet.h"
#include "Monster.h"
#include "DataMgr.h"

CGeneralTower::~CGeneralTower()
{
	while (!m_rgMyActiveBullet.empty()) {
		delete m_rgMyActiveBullet.back();

		m_rgMyActiveBullet.pop_back();
	}

	while (!m_rgMyInactiveBullet.empty()) {
		delete m_rgMyInactiveBullet.back();

		m_rgMyInactiveBullet.pop_back();
	}
}

void CGeneralTower::initByModel()
{
	m_fMyAttackPeriod = m_pMyModel->m_pMyBaseAttackPeriod[m_iMyLevel - 1];

	m_iMyAttack = m_pMyModel->m_pMyBaseAttack[m_iMyLevel - 1];

	m_fMyAttackRage = m_pMyModel->m_pMyAttackRage[m_iMyLevel - 1];

	m_fMyBarrelLen = m_pMyModel->m_fMyBarrelLen[m_iMyLevel - 1];
}

inline CGeneralTower* CGeneralTower::initData(SGeneralTowerModel* model, CTowerMgr* mgr, int level)
{
	m_pMyModel = model;
	m_pTowerMgr = mgr;
	m_iMyLevel = level;

	return this;
}

inline void CGeneralTower::attack(CMonster* target, float dt)
{
	std::vector<CBullet*>::iterator iter;

	for (iter = m_rgMyActiveBullet.begin(); iter != m_rgMyActiveBullet.end();) {
		/*�����ӵ�����*/
		(*iter)->attack();

		/*ֻ����Ŀ����߼�*/
		if ((*iter)->IsCollisionWith((*iter)->m_pAimedMonster)) { //����Ƿ���ײ
			(*iter)->MakeDamage((*iter)->m_pAimedMonster);	//�Թ�������˺�
			(*iter)->MakeDamageSpeedDown((*iter)->m_pAimedMonster);  //�Թ�������˺�������

			auto tmp_iter = iter;

			m_rgMyActiveBullet.erase(iter++);

			delete *iter;
		}
		else if ((*iter)->getPosition().length() > 128) {
			(*iter)->setInActive();	//����Ϊ�ǻ�Ծ

			m_rgMyInactiveBullet.push_back(*iter);

			m_rgMyActiveBullet.erase(iter++);
		}
		else
			++iter;
	}

	rotate(target, dt);
}

inline void CGeneralTower::rotate(CMonster* target, float dt)
{
	/*��ø��ֽǶȣ�mon_ang��my_ang��0~360��delta_ang��0~180*/
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
		/*��ת*/
		setRotation(mon_ang);

		if (m_fMyChargeTime > m_fMyAttackPeriod) {
			auto bullet = CBullet::createWithData(m_pMyModel->m_pMyBullet + m_iMyLevel - 1, this);

			bullet->setAimedMonster(target);  //���ù���Ŀ��

			bullet->setFatherTower(this);  //���÷�����ӵ�����

			bullet->initWithData(m_pMyModel->m_pMyBullet);  //��ʼ��

			bullet->setRotation(getRotation());  //�ӵ�����

			bullet->setBulletDamage(m_iMyAttack);  //�����ӵ��˺�

			m_fMyChargeTime = 0;
		}
	}
	else
		setRotation((mon_ang - my_ang == delta_ang) || (mon_ang - my_ang == delta_ang - 360.0) ?
			my_ang + dt * m_pMyModel->m_pMyBaseAngularV : my_ang - dt * m_pMyModel->m_pMyBaseAngularV);
}

cocos2d::Vec2 CGeneralTower::getBarrelPos()
{
	/*����*/
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
	++m_iMyLevel;

	float m_fMyAngular = getRotation();
	
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
