/*
2251918刘骏伟 ver1.0 实现1.1版本接口
*/


#include "Monster.h"
#include "MonsterHpUI.h"
#include "Bullet.h"

struct SMonsterData
{
	int m_iMyHealth;
	int m_iMyNowHealth;
	float m_flMySpeed;
	int m_iMyDeHealth;
	std::vector<Vec2> m_vecMyPath;
	int m_iMyGlodNum;
	//图片名字
	std::string m_strFrameName;
};


CMonster::CMonster() 
:m_flMyDeSpeedRate(0),m_flMySpeed(0),m_fMyIsActive(0),
m_iMyDeHealth(1),m_iMyGoldNum(14),m_iMyHealth(10),m_iMyNowHealth(10)
{

}

CMonster::~CMonster()
{
	m_pHpUI->release();
}

CMonster* CMonster::createWithData(const SMonsterData& SInitData)
{
	CMonster* pMonster = new CMonster();
	if (nullptr != pMonster && pMonster->initWithData(SInitData)) {
		pMonster->autorelease();
		return pMonster;
	}
	CC_SAFE_DELETE(pMonster);
	return nullptr;
}

bool CMonster::initWithData(const SMonsterData& SInitData) 
{
	//图片初始化
	if(!this->initWithFile(SInitData.m_strFrameName))
	{
		return false;
	}

	setMyDeHealth(SInitData.m_iMyDeHealth);
	setMyDeSpeedRate(0);
	setMyGoldNum(SInitData.m_iMyGlodNum);
	setMyHealth(SInitData.m_iMyHealth);
	setMyIsActive(0);
	setMyNowHealth(getMyHealth());
	setMySpeed(SInitData.m_flMySpeed);
	setMyPath(SInitData.m_vecMyPath);

	m_pHpUI = new CMonsterHpUI();
	if (!m_pHpUI->initWith())
	{
		return false;
	}
	this->addChild(m_pHpUI);
	m_pHpUI->setPosition(Vec2(0, 1));

	this->initAutoMove();
	this->setInActive();
	return true;
}

inline void CMonster::initAutoMove() {
	setPosition(m_vecMyPath[0]);
	this->schedule(CC_SCHEDULE_SELECTOR(CMonster::updateMove));
}

void CMonster::updateMove(float flDelta) 
{
	if (!m_fMyIsActive) 
	{
		return;
	}
	if (m_iMyNowPath == m_vecMyPath.size())
	{
		deathBehavior();
		return;
	}
	Vec2 targetPosition = m_vecMyPath[m_iMyNowPath];
	Vec2 nowPosition = getPosition();
	float flTargetLenth = targetPosition.distance(nowPosition);
	float flMoveLenth = flDelta * m_flMySpeed * (1 - m_flMyDeSpeedRate);
	while (flMoveLenth > flTargetLenth) 
	{
		flDelta = (flMoveLenth - flTargetLenth) / (m_flMySpeed * (1 - m_flMyDeSpeedRate));
		nowPosition = m_vecMyPath[m_iMyNowPath];
		++m_iMyNowPath;
		if (m_iMyNowPath == m_vecMyPath.size()) 
		{
			return;
		}
		targetPosition = m_vecMyPath[m_iMyNowPath];
		flTargetLenth = targetPosition.distance(nowPosition);
		flMoveLenth = flDelta * m_flMySpeed * (1 - m_flMyDeSpeedRate);
	}
	Vec2 direction = targetPosition - nowPosition;
	direction.normalize();
	this->setPosition(nowPosition + direction * m_flMyDeSpeedRate * (1 - m_flMyDeSpeedRate));
	return;
}

void CMonster::damage(int iDamageHealth) 
{
	m_iMyNowHealth -= iDamageHealth;
	if (m_iMyNowHealth <= 0) {
		deathBehavior();
		return;
	}
	m_pHpUI->showCurHealthRate(static_cast<float>(m_iMyNowHealth)/m_iMyHealth);
}

inline void CMonster::deathBehavior() 
{
	setInActive();
}

inline float CMonster::getDistanceToCarrot() const
{
	if (m_iMyNowPath >= m_vecMyPath.size()) {
		return 0;
	}
	return m_vecMyPath[m_iMyNowPath].distance(getPosition());
}

inline int CMonster::getGoldNum() const
{
	return m_iMyGoldNum;
}

inline bool CMonster::IsActive() const
{
	return m_fMyIsActive;
}

void CMonster::setActive()
{
	//设置活跃
	setMyIsActive(true);
	//设置初始位置和路径
	setMyDeSpeedRate(0);
	setMyNowPath(1);
	setPosition(m_vecMyPath[0]);
	//设置可视化
	setVisible(true);
	m_pHpUI->setVisible(true);
}

void CMonster::setInActive()
{
	//设置不活跃
	setMyIsActive(false);
	//设置位置回归初始位置
	setMyDeSpeedRate(0);
	setMyNowPath(0);
	setPosition(m_vecMyPath[0]);
	//设置不可见
	setVisible(false);
	m_pHpUI->setVisible(false);
}