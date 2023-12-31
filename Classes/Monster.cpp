/*
2251918刘骏伟 ver1.0 实现1.1版本接口
2251918刘骏伟 ver1.1 修改部分有关活跃状态接口的实现
*/


#include "Monster.h"
#include "MonsterHpUI.h"
#include "Bullet.h"
#include "DataMgr.h"
#include "MonsterMgr.h"
#include "AudioEngine.h"


CMonster::CMonster() 
:m_flMyDeSpeedRate(0),m_flMySpeed(0),m_fMyIsActive(0),
m_iMyDeHealth(1),m_iMyGoldNum(14),m_iMyHealth(10),m_iMyNowHealth(10)
{
	m_pHpUI = new CMonsterHpUI();
}

CMonster::~CMonster()
{
	m_pHpUI->release();
}

CMonster* CMonster::createWithData(SMonsterData* pSInitData)
{
	CMonster* pMonster = new CMonster();
	if (nullptr != pMonster && pMonster->initWithData(pSInitData)) {
		CCLOG("Monster success");
		return pMonster;
	}
	CCLOG("Monster fail");
	CC_SAFE_DELETE(pMonster);
	return nullptr;
}

bool CMonster::initWithData(SMonsterData* pSInitData)
{
	//图片初始化
	if(!this->initWithFile(pSInitData->m_strFrameName))
	{

		return false;
	}

	setMyDeHealth(pSInitData->m_iMyDeHealth);
	setMyDeSpeedRate(0);
	setMyGoldNum(pSInitData->m_iMyGoldNum);
	setMyHealth(pSInitData->m_iMyHealth);
	setMyIsActive(0);
	setMyNowHealth(getMyHealth());
	setMySpeed(pSInitData->m_flMySpeed);
	setMyPath(pSInitData->m_vecMyPath);
	setSlowDownTime(0);
	setMyNowPath(0);

	m_pHpUI =CMonsterHpUI::create();
	if (!m_pHpUI->init())
	{
		return false;
	}
	this->addChild(m_pHpUI);
	m_pHpUI->setPosition(getContentSize().width / 2, getContentSize().height+10);

	this->initAutoMove();
	this->setInActive();
	return true;
}

void CMonster::initAutoMove() {
	setPosition(m_vecMyPath[0]);
	this->schedule(CC_SCHEDULE_SELECTOR(CMonster::updateMove));
	this->schedule(CC_SCHEDULE_SELECTOR(CMonster::updateSpeed));
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

	int iScale = Director::getInstance()->getScheduler()->getTimeScale();
	Vec2 targetPosition = m_vecMyPath[m_iMyNowPath];
	Vec2 nowPosition = getPosition();
	float flTargetLenth = targetPosition.distance(nowPosition);
	float flMoveLenth = flDelta * m_flMySpeed * (1 - m_flMyDeSpeedRate) * iScale;
	while (std::fabs(flMoveLenth-flTargetLenth)<=2)
	{
		flDelta = (flMoveLenth - flTargetLenth) / (m_flMySpeed * (1 - m_flMyDeSpeedRate)*iScale);
		nowPosition = m_vecMyPath[m_iMyNowPath];
		++m_iMyNowPath;
		if (m_iMyNowPath == m_vecMyPath.size()) 
		{
			deathBehavior();
			return;
		}
		targetPosition = m_vecMyPath[m_iMyNowPath];
		flTargetLenth = targetPosition.distance(nowPosition);
		flMoveLenth = flDelta * m_flMySpeed * (1 - m_flMyDeSpeedRate)*iScale;
	}
	Vec2 direction = targetPosition - nowPosition;
	direction.normalize();
	this->setPosition(nowPosition + direction * m_flMySpeed * (1 - m_flMyDeSpeedRate)*iScale);
	CCLOG("%f,%f", nowPosition.x, nowPosition.y);
	return;
}

void CMonster::damage(int iDamageHealth) 
{
	m_iMyNowHealth -= iDamageHealth;
	if (m_iMyNowHealth <= 0) {
		deathBehavior();
		return;
	}
	m_pHpUI->setHealth(static_cast<float>(m_iMyNowHealth)/m_iMyHealth);
}

inline void CMonster::deathBehavior()
{
	m_pMonsterMgr->MonsterDeathMgr(this);
	setInActive();
	AudioEngine::play2d("death_effect.mp3",false);
}

float CMonster::getDistanceToCarrot() const
{
	if (m_iMyNowPath >= m_vecMyPath.size()) {
		return 0;
	}
	return m_vecMyPath[m_vecMyPath.size()-1].distance(getPosition());
}

int CMonster::getMyGoldNum()
{
	return m_iMyGoldNum;
}

bool CMonster::MyIsActive() 
{
	return m_fMyIsActive;
}

void CMonster::setActive()
{
	CCLOG("Monster Move!");
	setContentSize(Size(80, 80));
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

void CMonster::setMgr(CMonsterMgr* pMonsterMgr)
{
	m_pMonsterMgr = pMonsterMgr;
}

void CMonster::SlowDown(float flSlowDownRate, float flSlowDownTime)
{
	//若减速效果弱于当前，则不减速
	if (flSlowDownRate < m_flMyDeSpeedRate)
	{
		return;
	}
	//计时初始化
	m_flSlowDownTime = flSlowDownTime;
	m_flMyCurTime = 0.0f;
	setMyDeSpeedRate(flSlowDownRate);
}

void CMonster::updateSpeed(float flDelta)
{
	m_flMyCurTime += flDelta;
	if (m_flMyCurTime >= m_flSlowDownTime) 
	{
		m_flSlowDownTime = 0;
		m_flMyCurTime = 0;
		m_flMyDeSpeedRate = 0;
	}
}