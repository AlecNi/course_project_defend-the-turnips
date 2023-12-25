#pragma once
/*
* ���ʶ�
* 
* 2023/12/25
* 
* ��������ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
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
�����ɵĻ���ģ��
�ӳ������п�ʼʱ����
����������ͷ�
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
	/*�������������ȼ��ȼ�*/
	int m_iMyMaxLevel;

	/*�����ȼ�����������*/
	int* m_iMyBaseAttack;

	/*�����ȼ������������ڣ���λ��*/
	float* m_fMyBaseAttackPeriod;

	/*�����ȼ�����������Χ,*/
	float* m_fMyAttackRage;

	/*����ת��,��λ��*/
	float m_fMyBaseAngularV;

	/*����*/
	std::string m_sMyName;

	/*��������ͼ����Ϣ*/
	std::string&& m_MyPath;

	/*�����ͣ���Ե���aoe���̵�*/
	TowerType m_TTMyType;

private:
};


class CGeneralTower :public cocos2d::Sprite {

	/*������*/
	CC_SYNTHESIZE(int, m_iMyAttack, MyAttack);

	/*�ȼ�*/
	CC_SYNTHESIZE(int, m_iMyLevel, MyLevel);

	/*�������ʱ��*/
	CC_SYNTHESIZE(float, m_fMyAttackPeriod, MyAttackPeriod);

	/*������Χ*/
	CC_SYNTHESIZE(float, m_fMyAttackRage, MyAttackRage);

	/*ת��*/
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
	/*���������ģ��*/
	CGeneralTowerModel* m_Model;

private:
};

#endif

