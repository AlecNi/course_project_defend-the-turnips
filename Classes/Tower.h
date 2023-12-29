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
struct SBulletData;
struct SGeneralTowerModel;
class CTowerMgr;
class CMonster;

class CGeneralTower :public cocos2d::Sprite {

	/*攻击力*/
	CC_SYNTHESIZE(int, m_iMyAttack, MyAttack);

	/*等级,1,2,3...*/
	CC_SYNTHESIZE(int, m_iMyLevel, MyLevel);

	/*攻击间隔时间*/
	CC_SYNTHESIZE(float, m_fMyAttackPeriod, MyAttackPeriod);

	/*蓄力时间*/
	CC_SYNTHESIZE(float, m_fMyChargeTime, MyChargeTime);

	/*攻击范围*/
	CC_SYNTHESIZE(float, m_fMyAttackRage, MyAttackRage);

	/*炮口半径*/
	CC_SYNTHESIZE(float, m_fMyBarrelLen, MyBarrelLen);

	/*此处默认图片水平向右*/
	/*角度*/
	CC_SYNTHESIZE(float, m_fMyAngular, MyAngular);

	/*
	*
	* CC_SYNTHESIZE(std::set<CGeneralCondition>, m_setMyCondition, MyCondition);
	*
	* what I'm going to do if time promised
	*/

public:
	CREATE_FUNC(CGeneralTower);  //宏创建的静态生成函数，是Default Construction

	/*根据model重置数据*/
	virtual void initByModel();

	/*输入模板*/
	CGeneralTower* initModel(SGeneralTowerModel* model);

	/*得到该类的生成模板*/
	virtual SGeneralTowerModel* getModel();

	/*射击*/
	CBullet* shoot(CMonster* target);

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
	/*该类的生成模板*/
	SGeneralTowerModel* m_pMyModel;

	/*管理器*/
	CTowerMgr* m_pTowerMgr;
private:
};

#endif

