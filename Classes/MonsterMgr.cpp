/*
2251918����ΰ 2023 12 28 ver1.0
2251918����ΰ 2023 12 28 ver1.1
*/

/*
ver1.0 ����ʵ����ͷ�ļ�ver1.1�Ľӿ�,δ��ɲ��ֶ��ɱ��˸������Բ�Ӱ��ʹ��
ver1.1 ʵ��ͷ�ļ�ver1.2�Ľӿڣ�����ҽӿ���ʱ��
*/

#include "MonsterMgr.h"
#include "Monster.h"
#include "DataMgr.h"
#include "gold.h"
#include "string"



CMonsterMgr::CMonsterMgr()
{

}

CMonsterMgr::~CMonsterMgr()
{
	m_pActiveMonsterList.clear();
	m_pInActiveMonsterList.clear();
}

CMonsterMgr* CMonsterMgr::createWithData(SWaveData* pSInitData)
{
	CMonsterMgr* pMonsterMgr = new CMonsterMgr();
	if (nullptr != pMonsterMgr && pMonsterMgr->initWithData(pSInitData))
	{
		pMonsterMgr->autorelease();
		return pMonsterMgr;
	}
	CC_SAFE_DELETE(pMonsterMgr);
	return nullptr;
}

bool CMonsterMgr::initWithData(SWaveData* initData)
{
	m_pWaveData = initData;
	int iMonsterNumAll = 0;
	for (int i = 0; i < m_pWaveData->m_iWaveNum; i++)
	{
		iMonsterNumAll += m_pWaveData->m_iWaveMonsterNum[i];
	}
	CMonster* pMonster=nullptr;
	for (int i = 0; i < iMonsterNumAll; i++) {
		pMonster = CMonster::createWithData(m_pWaveData->m_pMonsterData[i]);
		m_pInActiveMonsterList.push_back(pMonster);
		pMonster->setMgr(this);
	}
	//���ó�ʼֵ
	setCurWaveNum(0);
	setCurMonIndex(0);
}

bool CMonsterMgr::WaveStart() {
	if (m_iCurWaveNum != 0)
	{
		//�˺���ֻ����ʹ��һ�Σ����ڲ��ε�ʱ�����
		return false;
	}
	if (m_iCurWaveNum > m_pWaveData->m_iWaveNum) 
	{
		return false;
	}
	float flWaitTime = 0;
	for (int i = 0; i < m_pWaveData->m_iWaveNum; i++)
	{
		flWaitTime += m_pWaveData->m_flMonsterWaitTime[i];
		this->scheduleOnce([=](float flDelta)
			{
				MonsterGenerate();
			}, flWaitTime, "Wave"+std::to_string(i+1));
	}
	return true;
}

void CMonsterMgr::MonsterGenerate()
{
	if (m_iCurWaveNum >= m_pWaveData->m_iWaveNum) {
		return;
	}
	m_iCurWaveNum++;
	for (int i = 0; i < m_pWaveData->m_iWaveMonsterNum[m_iCurWaveNum - 1]; i++)
	{
		this->scheduleOnce([=](float flDelta) {
				m_pInActiveMonsterList[m_iCurMonIndex]->setActive();
				m_pInActiveMonsterList[m_iCurMonIndex]->initAutoMove();
				m_pActiveMonsterList.push_back(m_pInActiveMonsterList[m_iCurMonIndex]);
			},m_pWaveData->m_flMonsterWaitTime[m_iCurMonIndex], "Monster" + std::to_string(m_iCurMonIndex));
		m_iCurMonIndex++;
	}
}

void CMonsterMgr::MonsterDeathMgr(CMonster* pMonster)
{
	std::vector<CMonster*>::iterator it = std::find_if(m_pActiveMonsterList.begin(), m_pActiveMonsterList.end(),
		[=](const CMonster* pM)
		{
			return pM == pMonster;
		});
	if (m_pActiveMonsterList.end() == it)
	{
		return;
	}
	m_pActiveMonsterList.erase(it);
	m_pActiveMonsterList.resize(m_pActiveMonsterList.size() - 1);
	m_pGold->addGolds(pMonster->getGoldNum());
}

inline const bool CMonsterMgr::isFinished() const
{
	return (m_pWaveData->m_iWaveNum == m_iCurWaveNum) && (m_pActiveMonsterList.size() == 0);
}

inline const std::vector<CMonster*> CMonsterMgr::getActiveMonsterList() const
{
	return m_pActiveMonsterList;
}

inline void CMonsterMgr::setGoldLink(CGold* pGold)
{
	m_pGold = pGold;
}

