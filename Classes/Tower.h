#pragma once
/*
* 倪朗恩
* 
* 2023/12/25
* 
* 防御塔的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*/


#ifndef _CTEST_H
#define _CTSET_H

#include <string>
#include <set>
#include "cocos2d.h"
/*
* #include "condition.h"
*/

enum class TowerType {
	kSingle,

};

/*
塔生成的基础模板
从程序运行开始时创建
到程序结束释放
*/
class CGeneralTowerModel {
public:
	CGeneralTowerModel(std::string&& name, std::string&& path,
		TowerType&& type, int&& max_level, int*& base_attack,
		float*& base_attack_period, float*& m_iMyAttackRage, float&& base_angular_v = 45);

	const int& getMyMaxLevel() const;
	const int& getMyBaseAttack() const;
	const float& getMyBaseAngularV() const;
	const float& getMyBaseAttackPeriod() const;
	const std::string& getMyName() const;
	const TowerType& getMyType() const;

protected:
	/*可以升级的最大等级等级*/
	int m_iMyMaxLevel;

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
	std::string&& m_MyPath;

	/*塔类型，如对单、aoe、奶等*/
	TowerType m_TTMyType;

private:
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
	CGeneralTower(CGeneralTowerModel* model);

	virtual bool init();
	virtual ~CGeneralTower();

protected:
	/*该类的生成模板*/
	CGeneralTowerModel* m_Model;

private:
};

#endif

