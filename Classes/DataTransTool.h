/*
2251918 ����ΰ 2023 12 31 ver1.0 
*/

/*
ver1.0 ����һ�����ļ�ת��Ϊ�ṹ�����ݵĹ������ļ� 
*/

#ifndef _DATA_TOOL_H
#define _DATA_TOOL_H

#include "DataMgr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cocos2d.h>

std::shared_ptr<SLevelData*> openFile(const std::string& refFileName)
{
	std::ifstream fileStream(refFileName);

	if (!fileStream.is_open())
	{
		return;
	}

	SLevelData* pInitData = new SLevelData();
	//����������
	/*
	�ļ���ʽ���£�
	��ǰ��������������a
a��:
{
			���ȼ� ������ ������ ������� ������Χ �ڿڰ뾶 ���� ��ͼ���ļ��� ������
�ӵ�����:	�ӵ����� �ӵ�ͼƬ�ļ���
}
	��ǰ�ص�ͼ·�������n
n��:	·�����x��·�����y ����

	��ǰ�ز�������b
b��:
{
		��ǰ���ι�������n  ���ο�ʼ�ȴ�ʱ�� 
n��:	���ε��ù����ļ��� ������صȴ�ʱ��
}
	
	*/
	/*
	�����ļ���ʽ���£�
	��������ֵ���� ���������ٶ� ���ﴥ���ܲ���ʧ����ֵ ��������������
	����ͼƬ���� 
	*/

	pInitData->m_pTowerMgr = new STowerMgrData();
	pInitData->m_pMonsterMgr = new SWaveData();
	int iTowerNum = 0, iWaveNum = 0, iPathNum = 0;
	fileStream >> iTowerNum;
	for (int i = 0; i < iTowerNum; i++)
	{
		SGeneralTowerModel* TowerModel = new SGeneralTowerModel();
		fileStream >> TowerModel->m_iMyMaxLevel >> TowerModel->m_pMyCost >> TowerModel->m_pMyBaseAttackPeriod >> TowerModel->m_pMyAttackRage
			>> TowerModel->m_fMyBarrelLen >> TowerModel->m_sMyName >> TowerModel->m_sMyPath >> TowerModel->m_kMyType;
		SBulletData* Bullet = new SBulletData();
		fileStream >> Bullet->m_iAttackType >> Bullet->m_strBulletFrame;
		TowerModel->m_pMyBullet = Bullet;
		pInitData->m_pTowerMgr->m_rgTowerModel.push_back(TowerModel);
	}

	fileStream >> iPathNum;
	std::vector<cocos2d::Vec2> rgMyPath;
	float ix = 0, iy = 0;
	for (int i = 0; i < iPathNum; i++)
	{
		fileStream >> ix >> iy;
		rgMyPath.push_back(cocos2d::Vec2(ix, iy));
	}

	fileStream >> iWaveNum;
	pInitData->m_pMonsterMgr->m_iWaveNum = iWaveNum;

	int iMonsterNum = 0;
	float flWaveWaitTime = 0, flMonsterWaitTime = 0;
	std::string MonsterFileName;
	for (int i = 0; i < iWaveNum; i++)
	{
		fileStream >> iMonsterNum >> flWaveWaitTime;
		pInitData->m_pMonsterMgr->m_iWaveMonsterNum.push_back(iMonsterNum);
		pInitData->m_pMonsterMgr->m_flWaveTime.push_back(flWaveWaitTime);
		for (int i = 0; i < iMonsterNum; i++)
		{
			fileStream >> MonsterFileName >> flMonsterWaitTime;
			std::ifstream MonsterFile(MonsterFileName);
			if (!MonsterFile.is_open())
			{
				break;
			}
			SMonsterData* pMonster = new SMonsterData();
			pMonster->m_vecMyPath = rgMyPath;
			MonsterFile >> pMonster->m_iMyHealth >> pMonster->m_flMySpeed >> pMonster->m_iMyDeHealth 
				>> pMonster->m_iMyGoldNum >> pMonster->m_strFrameName;
			pInitData->m_pMonsterMgr->m_pMonsterData.push_back(pMonster);
			MonsterFile.close();
		}
	}

}




#endif // !_DATA_TOOL_H
