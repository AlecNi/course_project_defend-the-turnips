#pragma once
/*
* 倪朗恩 2251334
* 
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
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
struct SBulletData;
struct SGeneralTowerModel;
class CTowerMgr;
class CMonster;
class CBullet;

class CGeneralTower :public cocos2d::Sprite {
	/*等级,1,2,3...*/
	CC_SYNTHESIZE(int, m_iMyLevel, MyLevel);

	/*攻击力*/
	CC_SYNTHESIZE(int, m_iMyAttack, MyAttack);

	/*攻击间隔时间*/
	CC_SYNTHESIZE(float, m_fMyAttackPeriod, MyAttackPeriod);

	/*蓄力时间*/
	CC_SYNTHESIZE(float, m_fMyChargeTime, MyChargeTime);

	/*攻击范围*/
	CC_SYNTHESIZE(float, m_fMyAttackRage, MyAttackRage);

	/*炮口半径*/
	CC_SYNTHESIZE(float, m_fMyBarrelLen, MyBarrelLen);

	/*
	*此处默认图片水平向右*
	*角度*
	CC_SYNTHESIZE(float, m_fMyAngular, MyAngular);
	*
	* CC_SYNTHESIZE(std::set<CGeneralCondition>, m_setMyCondition, MyCondition);
	*
	* what I'm going to do if time promised
	*/

public:
	/*宏创建的静态生成函数，是Default Construction*/
	CREATE_FUNC(CGeneralTower);

	virtual ~CGeneralTower();

	/*根据model与等级重置数据*/
	virtual void initByModel();

	/*输入数据*/
	virtual CGeneralTower* createWithData(SGeneralTowerModel* model, CTowerMgr* mgr, int level = 1);

	/*得到该类的生成模板*/
	virtual SGeneralTowerModel* getModel();

	/*更新子弹行为*/
	virtual CBullet* attack(CMonster* target, float dt);

	/*得到炮口位置，可以用于实现激光等*/
	cocos2d::Vec2 getBarrelPos();

	/*升级炮塔*/
	bool upgrades();

/*
*
* bool initWithConditoin();
*
* what I'm going to do if time promised
*/
protected:
	/*转向并生成子弹*/
	CBullet* rotate(CMonster* target, float dt);

	/*该类的生成模板*/
	SGeneralTowerModel* m_pMyModel;

	/*管理器*/
	CTowerMgr* m_pTowerMgr;

	/*管理射出去的子弹*/
	std::vector<CBullet*> m_rgMyInactiveBullet;

	/*管理射出去的子弹*/
	std::vector<CBullet*> m_rgMyActiveBullet;
private:
};

#endif

