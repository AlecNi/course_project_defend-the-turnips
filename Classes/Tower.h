#pragma once
/*
* ���ʶ�
* 
* 2023/12/25
* 2023/12/29
* 
* ��������ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
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
	kAOE,  //Ⱥ��
	kAux,  //����
};

/*
�����ɵĻ���ģ��
�ӳ������п�ʼʱ����
����������ͷ�
*/
struct SGeneralTowerModel{
	/*�������������ȼ��ȼ�*/
	int m_iMyMaxLevel;

	/*����������*/
	int m_iMyCost;

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
	std::string m_sMyPath;

	/*�����ͣ���Ե���aoe���̵�*/
	TowerType m_kMyType;

	/*�ӵ����ͣ���Ե���aoe���̵�*/
	SBullet* m_pMyBullet;
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
	CREATE_FUNC(CGeneralTower);  //�괴���ľ�̬���ɺ�������Default Construction

	virtual bool initByModel();

protected:
	/*���������ģ��*/
	SGeneralTowerModel* m_pMyModel;

	/*������*/
	CTowerMgr* m_pMonsterMgr;

private:
};

#endif

