/*
2251918刘骏伟 2023 12 29 ver1.0
*/
/*
ver1.0 实现了子弹的碰撞，但还没实现激光和直线
*/

#include "Bullet.h"
#include "DataMgr.h"
#include "Monster.h"
#include "Tower.h"

CBullet::CBullet()
{

}

CBullet::~CBullet()
{
	
}

CBullet* CBullet::createWithData(SBulletData* pInitData, CGeneralTower* pTower)
{
	if (nullptr == pTower)
	{
		return nullptr;
	}
	CBullet* pBullet = new CBullet();
	if (nullptr != pBullet && pBullet->initWithData(pInitData))
	{
		pBullet->setFatherTower(pTower);
		pBullet->autorelease();
		return pBullet;
	}
	CC_SAFE_DELETE(pBullet);
	return nullptr;
}

 void CBullet::setFatherTower(CGeneralTower* pT)
{
	m_pTowerFrom = pT;
	pT->addChild(this);
	setPosition(pT->getPosition());
}

 void CBullet::setAimedMonster(CMonster* pAimedMonster)
{
	m_pAimedMonster = pAimedMonster;
}

 void CBullet::setBulletDamage(int iDamage)
{
	setMyDamage(iDamage);
}

bool CBullet::initWithData(SBulletData* pInitData)
{
	if (!Sprite::initWithFile(pInitData->m_strBulletFrame))
	{
		return false;
	}
	setMyAttackType(pInitData->m_iAttackType);
	setMyDamage(pInitData->m_iBulletDamage);
	setMySpeed(pInitData->m_flBulletSpeed);
	setBulletSlowDownRate(0.6);
	setBulletSlowDownTime(5);
	m_pAimedMonster = nullptr;

	return true;
}

void CBullet::attack()
{
	switch (m_iMyAttackType)
	{
	case 0:
	{
		schedule(CC_SCHEDULE_SELECTOR(CBullet::CollisionAttack));
		break;
	}
	case 1:
	{
		schedule(CC_SCHEDULE_SELECTOR(CBullet::ContinueAttack));
		break;
	}
	case 2:
	{
		schedule(CC_SCHEDULE_SELECTOR(CBullet::DirectAttack));
		break;
	}
	default:
	{
		break;
	}
	}
}

 const bool CBullet::IsCollisionWith(CMonster* pMonster)
{
	Rect MonsterSize = pMonster->getBoundingBox();
	Rect BulletSize = this->getBoundingBox();

	return BulletSize.intersectsRect(MonsterSize);
}

void CBullet::MakeDamage(CMonster* pMonster)
{
	pMonster->damage(m_iMyDamage);
}

void CBullet::CollisionAttack(float flDeltaTime)
{
	if (!m_pAimedMonster->MyIsActive())
	{
		m_fIsActive = false;
	}

	if (!m_fIsActive)
	{
		return;
	}
	if (IsCollisionWith(m_pAimedMonster))
	{
		if (m_iMyAttackType == 1) {
			MakeDamageSpeedDown(m_pAimedMonster);
		}
		else {
			MakeDamage(m_pAimedMonster);
		}
		setInActive();
		return;
	}
	Vec2 dstPosition= getPosition()-m_pAimedMonster->getPosition();
	float flMoveLenth = flDeltaTime * m_flMySpeed;
	//若位移长度大于目标距离则直接攻击成功
	if (flMoveLenth >= dstPosition.length())
	{
		MakeDamage(m_pAimedMonster);
		setInActive();
		return;
	}
	dstPosition.normalize();
	this->setPosition(getPosition() + m_flMySpeed * dstPosition);
	return;
}

void CBullet::ContinueAttack(float flDeltaTime)
{

}

void CBullet::DirectAttack(float flDeltaTime)
{

}

void CBullet::setInActive()
{
	setIsActive(false);
	setVisible(false);
}

 void CBullet::MakeDamageSpeedDown(CMonster* pMonster)
{
	pMonster->damage(m_iMyDamage);
	pMonster->SlowDown(m_flBulletSlowDownRate, m_flBulletSlowDownTime);
}