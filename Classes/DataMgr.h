/*
2251918ljw ver1.0 怪物数据结构体，波次结构体，子弹结构体

*/


#include <vector>
#include <string>
#include <cocos2d.h>
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
};

struct SBulletData
{
	/*子弹伤害，可以用炮塔伤害代替*/
	int iBulletDamage;
	/*子弹速度*/
	float flBulletSpeed;
	/*子弹类型*/
	int iAttackType;
	/*子弹贴图文件名*/
	std::string strBulletFrame;
};

struct SHpUIData
{
	/*填充图*/
	std::string strFillName;
	/*背景图*/
	std::string strBackName;
};