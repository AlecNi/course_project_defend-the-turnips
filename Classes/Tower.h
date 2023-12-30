#pragma once
/*
* ���ʶ� 2251334
* 
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
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
struct SBulletData;
struct SGeneralTowerModel;
class CTowerMgr;
class CMonster;
class CBullet;

class CGeneralTower :public cocos2d::Sprite {
	/*�ȼ�,1,2,3...*/
	CC_SYNTHESIZE(int, m_iMyLevel, MyLevel);

	/*������*/
	CC_SYNTHESIZE(int, m_iMyAttack, MyAttack);

	/*�������ʱ��*/
	CC_SYNTHESIZE(float, m_fMyAttackPeriod, MyAttackPeriod);

	/*����ʱ��*/
	CC_SYNTHESIZE(float, m_fMyChargeTime, MyChargeTime);

	/*������Χ*/
	CC_SYNTHESIZE(float, m_fMyAttackRage, MyAttackRage);

	/*�ڿڰ뾶*/
	CC_SYNTHESIZE(float, m_fMyBarrelLen, MyBarrelLen);

	/*
	*�˴�Ĭ��ͼƬˮƽ����*
	*�Ƕ�*
	CC_SYNTHESIZE(float, m_fMyAngular, MyAngular);
	*
	* CC_SYNTHESIZE(std::set<CGeneralCondition>, m_setMyCondition, MyCondition);
	*
	* what I'm going to do if time promised
	*/

public:
	/*�괴���ľ�̬���ɺ�������Default Construction*/
	CREATE_FUNC(CGeneralTower);

	virtual ~CGeneralTower();

	/*����model��ȼ���������*/
	virtual void initByModel();

	/*��������*/
	virtual CGeneralTower* createWithData(SGeneralTowerModel* model, CTowerMgr* mgr, int level = 1);

	/*�õ����������ģ��*/
	virtual SGeneralTowerModel* getModel();

	/*�����ӵ���Ϊ*/
	virtual CBullet* attack(CMonster* target, float dt);

	/*�õ��ڿ�λ�ã���������ʵ�ּ����*/
	cocos2d::Vec2 getBarrelPos();

	/*��������*/
	bool upgrades();

/*
*
* bool initWithConditoin();
*
* what I'm going to do if time promised
*/
protected:
	/*ת�������ӵ�*/
	CBullet* rotate(CMonster* target, float dt);

	/*���������ģ��*/
	SGeneralTowerModel* m_pMyModel;

	/*������*/
	CTowerMgr* m_pTowerMgr;

	/*�������ȥ���ӵ�*/
	std::vector<CBullet*> m_rgMyInactiveBullet;

	/*�������ȥ���ӵ�*/
	std::vector<CBullet*> m_rgMyActiveBullet;
private:
};

#endif

