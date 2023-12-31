/*
2251918 刘骏伟 2023 12 31 ver1.0 
*/

/*
ver1.0 这是一个将文件转化为结构体数据的工具性文件 
*/

/*
	文件格式如下：
	当前关炮塔种类数量a
a段:
{
	炮塔文件名
}
	当前关地图路径点个数n
n段:	路径点的x，路径点的y ……

	当前关波次数量b
b段:
{
		当前波次怪物数量n  波次开始等待时间
n次:	波次调用怪物文件名 怪物加载等待时间
}
	*/
	/*
	炮塔文件格式如下：
	塔最高等级n
n段：{
	购买或升级所需金币，攻击力，攻击间隔，攻击范围，炮口半径 塔名 塔类型 塔图片文件名
	子弹类型，子弹图片文件名
}
	*/
	/*
	怪物文件格式如下：
	怪物生命值上限 怪物正常速度 怪物触碰萝卜损失生命值 死亡掉落金币数量
	怪物图片名字
	*/
#ifndef _DATA_TOOL_H
#define _DATA_TOOL_H

#include "DataMgr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cocos2d.h>

cocos2d::Vec2 trans_ij_to_xy(int ix,int iy) {
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
		return;
	}

	SLevelData* pInitData = new SLevelData();
	//先输入炮塔
	

	pInitData->m_pTowerMgr = new STowerMgrData();
	pInitData->m_pMonsterMgr = new SWaveData();
	int iTowerNum = 0, iWaveNum = 0, iPathNum = 0;
	fileStream >> iTowerNum;
	for (int i = 0; i < iTowerNum; i++)
	{
		std::ifstream TowerFile(refFileName);

		if (!TowerFile.is_open())
		{
			return;
		}
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
			SMonsterData* pMonster = new SMonsterData();
			pMonster->m_vecMyPath = rgMyPath;
			MonsterFile >> pMonster->m_iMyHealth >> pMonster->m_flMySpeed >> pMonster->m_iMyDeHealth 
				>> pMonster->m_iMyGoldNum >> pMonster->m_strFrameName;
			pInitData->m_pMonsterMgr->m_pMonsterData.push_back(pMonster);
			MonsterFile.close();
		}
	}
	std::shared_ptr<SLevelData> ptr(pInitData);
	return ptr.get();
}




#endif // !_DATA_TOOL_H
