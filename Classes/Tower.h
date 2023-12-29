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
struct SBulletData;
struct SGeneralTowerModel;
class CTowerMgr;
class CMonster;

class CGeneralTower :public cocos2d::Sprite {

	/*������*/
	CC_SYNTHESIZE(int, m_iMyAttack, MyAttack);

	/*�ȼ�,1,2,3...*/
	CC_SYNTHESIZE(int, m_iMyLevel, MyLevel);

	/*�������ʱ��*/
	CC_SYNTHESIZE(float, m_fMyAttackPeriod, MyAttackPeriod);

	/*����ʱ��*/
	CC_SYNTHESIZE(float, m_fMyChargeTime, MyChargeTime);

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

	/*����ģ��*/
	CGeneralTower* initModel(SGeneralTowerModel* model);

	/*�õ����������ģ��*/
	virtual SGeneralTowerModel* getModel();

	/*���*/
	CBullet* shoot(CMonster* target);

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
	/*���������ģ��*/
	SGeneralTowerModel* m_pMyModel;

	/*������*/
	CTowerMgr* m_pTowerMgr;
private:
};

#endif

