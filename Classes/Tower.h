#pragma once
/*
* 倪朗恩
* 
* 2023/12/25
* 2023/12/29
* 
* 防御塔的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*/

#ifndef _CTOWER_H
#define _CTOWER_H

#include <string>
#include <set>
#include "cocos2d.h"

/*
struct SGeneralCondition;
*/
struct SBullet;
class CTowerMgr;
class CMonster;

enum class TowerType {
	kSingle,  //
	kAOE,  //群攻
	kAux,  //辅助
};

/*
塔生成的基础模板
从程序运行开始时创建
到程序结束释放
*/
struct SGeneralTowerModel{
	/*可以升级的最大等级等级*/
	int m_iMyMaxLevel;

	/*买塔所需金币*/
	int m_iMyCost;

	/*各个等级基础攻击力*/
	int* m_iMyBaseAttack;

	/*各个等级基础攻击周期，单位秒*/
	float* m_fMyBaseAttackPeriod;

	/*各个等级基础攻击范围,*/
	float* m_fMyAttackRage;

	/*基础转速,单位度*/
	float m_fMyBaseAngularV;

	/*塔名*/
	std::string m_sMyName;

	/*塔的所有图形信息*/
	std::string m_sMyPath;

	/*塔类型，如对单、aoe、奶等*/
	TowerType m_kMyType;

	/*子弹类型，如对单、aoe、奶等*/
	SBullet* m_pMyBullet;
};

class CGeneralTower :public cocos2d::Sprite {

	/*攻击力*/
	CC_SYNTHESIZE(int, m_iMyAttack, MyAttack);

	/*等级*/
	CC_SYNTHESIZE(int, m_iMyLevel, MyLevel);

	/*攻击间隔时间*/
	CC_SYNTHESIZE(float, m_fMyAttackPeriod, MyAttackPeriod);

	/*攻击范围*/
	CC_SYNTHESIZE(float, m_fMyAttackRage, MyAttackRage);

	/*转速*/
	CC_SYNTHESIZE(float, m_fMyAngularV, MyAngularV);

	/*
	*
	* CC_SYNTHESIZE(std::set<CGeneralCondition>, m_setMyCondition, MyCondition);
	*
	* what I'm going to do if time promised
	*/

public:
	CREATE_FUNC(CGeneralTower);  //宏创建的静态生成函数，是Default Construction

	virtual bool initByModel();

protected:
	/*该类的生成模板*/
	SGeneralTowerModel* m_pMyModel;

	/*管理器*/
	CTowerMgr* m_pMonsterMgr;

private:
};

#endif

