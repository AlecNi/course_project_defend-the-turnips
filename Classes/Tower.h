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
	/*�������������ȼ��ȼ�,1,2,3...*/
	int m_iMyMaxLevel;

	/*����������������*/
	int* m_pMyCost;

	/*�����ȼ�����������*/
	int* m_pMyBaseAttack;

	/*�����ȼ������������ڣ���λ��*/
	float* m_pMyBaseAttackPeriod;

	/*�����ȼ�����������Χ,*/
	float* m_pMyAttackRage;

	/*�����ȼ��ڿڰ뾶*/
	float* m_fMyBarrelLen;

	/*ת��,��λ��*/
	float m_pMyBaseAngularV = 45;

	/*����*/
	std::string m_sMyName;

	/*��������ͼ����Ϣ*/
	std::string m_sMyPath;

	/*�����ͣ���Ե���aoe���̵�*/
	const TowerType m_kMyType;

	/*�ӵ����ͣ���Ե���aoe���̵�*/
	SBullet* m_pMyBullet;
};

class CGeneralTower :public cocos2d::Sprite {

	/*������*/
	CC_SYNTHESIZE(int, m_iMyAttack, MyAttack);

	/*�ȼ�,1,2,3...*/
	CC_SYNTHESIZE(int, m_iMyLevel, MyLevel);

	/*�������ʱ��*/
	CC_SYNTHESIZE(float, m_fMyAttackPeriod, MyAttackPeriod);

	/*������Χ*/
	CC_SYNTHESIZE(float, m_fMyAttackRage, MyAttackRage);

	/*�ڿڰ뾶*/
	CC_SYNTHESIZE(float, m_fMyBarrelLen, MyBarrelLen);

	/*�˴�Ĭ��ͼƬˮƽ����*/
	/*�Ƕ�*/
	CC_SYNTHESIZE(float, m_fMyAngular, MyAngular);

	/*
	*
	* CC_SYNTHESIZE(std::set<CGeneralCondition>, m_setMyCondition, MyCondition);
	*
	* what I'm going to do if time promised
	*/

public:
	CREATE_FUNC(CGeneralTower);  //�괴���ľ�̬���ɺ�������Default Construction

	/*����model��������*/
	virtual void initByModel();

	/*�õ����������ģ��*/
	virtual SGeneralTowerModel* getModel();

	/*�õ��ڿ�λ�ã���������ʵ�ּ����*/
	cocos2d::Vec2 getBarrelPos();

/*
*
* bool initWithConditoin();
*
* what I'm going to do if time promised
*/

	/*��������*/
	bool upgrades();

protected:
	/*���������ģ��*/
	SGeneralTowerModel* m_pMyModel;

	/*������*/
	CTowerMgr* m_pTowerMgr;

private:
};

#endif

