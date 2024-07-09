
/*
2251918 ����ΰ 2023 12 31 ver1.0 
*/

/*
ver1.0 ����һ�����ļ�ת��Ϊ�ṹ�����ݵĹ������ļ� 
*/

/*
	�ļ���ʽ���£�
	��ǰ��������������a
a��:
{
	�����ļ���
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
	����ߵȼ�n
n�Σ�{
	��������������ң������������������������Χ���ڿڰ뾶 ���� ������ ��ͼƬ�ļ���
	�ӵ����ͣ��ӵ�ͼƬ�ļ���
}
	*/
	/*
	�����ļ���ʽ���£�
	��������ֵ���� ���������ٶ� ���ﴥ���ܲ���ʧ����ֵ ��������������
	����ͼƬ����
	*/



#include "DataTransTool.h"
#include "DataMgr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

std::vector<int> trans_xy_to_ij(Vec2 vec) {
	return { static_cast<int>((vec.x) / 80) ,6 - static_cast<int>((vec.y) / 80) };
}

cocos2d::Vec2 trans_ij_to_xy(int ix, int iy) {
	cocos2d::Vec2 vec;
	vec.x = 40 + iy * 80;
	vec.y = 40 + (6 - ix) * 80;
	return vec;
}

SLevelData* openFile(const std::string& refFileName)
{
	std::ifstream fileStream(refFileName);

	if (!fileStream.is_open())
	{
		CCLOG("false open!");
		return nullptr;
	}
	CCLOG(refFileName.c_str());
	SLevelData* pInitData = new SLevelData();
	//����������
	int iTowerNum = 0, iWaveNum = 0, iPathNum = 0;
	fileStream >> iTowerNum;
	std::string myTower;
	for (int i = 0; i < iTowerNum; i++)
	{
		fileStream >> myTower;
		std::ifstream TowerFile(myTower);

		if (!TowerFile.is_open())
		{
			CCLOG("false open!");
			return nullptr;
		}
		CCLOG(myTower.c_str());
		int iMaxLevel = 0;
		TowerFile >> iMaxLevel;
		SGeneralTowerModel* TowerModel = new SGeneralTowerModel();
		int iCost = 0, iAttack = 0;
		float flATime = 0, flARage = 0, flLen = 0;
		int iTowerType = 0, iBulletType = 1;

		TowerModel->m_iMyMaxLevel = iMaxLevel;
		
		std::string strTowerName, strTowerPath, strBulletPath;
		for (int i = 0; i < iMaxLevel; i++)
		{
			TowerFile >> iCost >> iAttack >> flATime >> flARage >>flLen>> strTowerName >> iTowerType >> strTowerPath >> iBulletType >> strBulletPath;
			TowerModel->m_pMyCost.push_back(iCost);
			TowerModel->m_pMyBaseAttack.push_back(iAttack);
			TowerModel->m_pMyBaseAttackPeriod.push_back(flATime);
			TowerModel->m_fMyBarrelLen.push_back(flLen);
			TowerModel->m_pMyAttackRage.push_back(flARage);
			TowerModel->m_sMyPath.push_back(strTowerPath);
		}
		TowerModel->m_kMyType = iTowerType;
		TowerModel->m_sMyName = strTowerName;
		
		SBulletData* Bullet = new SBulletData();
		Bullet->m_iAttackType = iBulletType;
		Bullet->m_iBulletDamage = iAttack;
		Bullet->m_strBulletFrame = strBulletPath;
		TowerModel->m_pMyBullet = Bullet;

		pInitData->m_pTowerMgr->m_rgTowerModel.push_back(TowerModel);
	}

	fileStream >> iPathNum;
	std::vector<cocos2d::Vec2> rgMyPath;
	float ix = 0, iy = 0;
	for (int i = 0; i < iPathNum; i++)
	{
		fileStream >> ix >> iy;
		rgMyPath.push_back(trans_ij_to_xy(ix,iy));
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
			CCLOG(MonsterFileName.c_str());
			SMonsterData* pMonster = new SMonsterData();
			pMonster->m_vecMyPath = rgMyPath;
			MonsterFile >> pMonster->m_iMyHealth >> pMonster->m_flMySpeed >> pMonster->m_iMyDeHealth 
				>> pMonster->m_iMyGoldNum >> pMonster->m_strFrameName;
			pInitData->m_pMonsterMgr->m_flMonsterWaitTime.push_back(flMonsterWaitTime);
			pInitData->m_pMonsterMgr->m_pMonsterData.push_back(pMonster);
			MonsterFile.close();
		}
	}

	std::string addressAsString = std::to_string(reinterpret_cast<uintptr_t>(pInitData));
	CCLOG(addressAsString.c_str());
	return pInitData;
}

