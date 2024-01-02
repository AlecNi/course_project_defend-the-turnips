/*
2251918ljw ver1.0 怪物数据结构体，波次结构体，子弹结构体
2251334nle ver1.1 塔的数据结构体，塔的类型枚举
2251918ljw ver1.2 补充子弹结构中的文件名
*/


#include <vector>
#include <string>
#include "cocos2d.h"
USING_NS_CC;

struct SMonsterData
{
	/*生命值上限*/
	int m_iMyHealth;
	/*一般速度*/
	float m_flMySpeed;
	/*进萝卜损失生命值*/
	int m_iMyDeHealth;
	/*路径数组*/
	std::vector<Vec2> m_vecMyPath;
	/*死亡掉落金币数量*/
	int m_iMyGoldNum;
	//图片名字
	std::string m_strFrameName;
};

struct SWaveData
{
	/*波次总数*/
	int m_iWaveNum;
	/*所有怪物数据*/
	std::vector<SMonsterData*> m_pMonsterData;
	/*波次开始前等待时间*/
	std::vector<float> m_flWaveTime;
	/*怪物每波数量*/
	std::vector<int> m_iWaveMonsterNum;
	/*怪物时间间隔*/
	std::vector<float> m_flMonsterWaitTime;

	~SWaveData()
	{
		for (SMonsterData* p : m_pMonsterData)
		{
			delete p;
			p = nullptr;
		}
		m_pMonsterData.clear();
	}
};

struct SBulletData
{
	/*子弹伤害，可以用炮塔伤害代替*/
	int m_iBulletDamage;
	/*子弹速度*/
	float m_flBulletSpeed=10;
	/*子弹类型*/
	int m_iAttackType;
	/*子弹图片文件名*/
	std::string m_strBulletFrame;
};

struct SHpUIData
{
	/*填充图*/
	std::string strFillName;
	/*背景图*/
	std::string strBackName;
};

/*塔的攻击种类*/
enum TowerType {
	kSingle,	//单对单
	kAOE,		//群攻
	kAux,		//辅助
};

struct SGeneralTowerModel {
	/*可以升级的最大等级等级,1,2,3...*/
	int m_iMyMaxLevel;

	/*买塔及升级所需金币*/
	std::vector<int> m_pMyCost;

	/*各个等级基础攻击力*/
	std::vector<int> m_pMyBaseAttack;

	/*各个等级基础攻击周期，单位秒*/
	std::vector<float> m_pMyBaseAttackPeriod;

	/*各个等级基础攻击范围,*/
	std::vector<float> m_pMyAttackRage;

	/*各个等级炮口半径*/
	std::vector<float> m_fMyBarrelLen;

	/*转速,单位度*/
	float m_pMyBaseAngularV = 45;

	/*塔名*/
	std::string m_sMyName;

	/*塔的所有图形信息*/
	std::vector<std::string> m_sMyPath;

	/*塔类型，如对单、aoe、奶等*/
	int m_kMyType;

	/*子弹类型，如对单、aoe、奶等*/
	SBulletData* m_pMyBullet;


	~SGeneralTowerModel()
	{
		delete m_pMyBullet;
	}
};

struct STowerMgrData
{
	/*塔数据数组*/
	std::vector<SGeneralTowerModel*> m_rgTowerModel;

	~STowerMgrData()
	{
		for (SGeneralTowerModel* p : m_rgTowerModel)
		{
			delete p;
			p = nullptr;
		}
		m_rgTowerModel.clear();
	}
};

struct SLevelData
{
	STowerMgrData* m_pTowerMgr;
	SWaveData* m_pMonsterMgr;

	~SLevelData()
	{
		delete m_pMonsterMgr;
		delete m_pTowerMgr;
	}
};