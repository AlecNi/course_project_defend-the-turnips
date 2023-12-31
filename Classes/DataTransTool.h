/*
2251918 刘骏伟 2023 12 31 ver1.0 
*/

/*
ver1.0 这是一个将文件转化为结构体数据的工具性文件 
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
	//先输入炮塔
	/*
	文件格式如下：
	当前关炮塔种类数量a
a段:
{
			最大等级 购买金币 攻击力 攻击间隔 攻击范围 炮口半径 塔名 塔图形文件名 塔类型
子弹数据:	子弹类型 子弹图片文件名
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
	怪物文件格式如下：
	怪物生命值上限 怪物正常速度 怪物触碰萝卜损失生命值 死亡掉落金币数量
	怪物图片名字 
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
