#pragma once
/*
* 倪朗恩 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
*
* 防御塔管理的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*/

#ifndef _TOWER_MGR_H
#define _TOWER_MGR_H

#include <vector>
#include "cocos2d.h"

struct SGeneralTowerModel;
class CGeneralTower;
class CMonsterMgr;
class CMonster;
class CGold;

class CTowerMgr : public cocos2d::Layer {
public:
	virtual ~CTowerMgr();

	/*初始化数据*/
	virtual CTowerMgr* initData(CMonsterMgr* mgr, CGold* gold);

	/*打开选择目录，如果选中的是空地（默认NULL）则打开选择列表,否则会显示升级列表,返回生成的塔的坐标，方便addChild到场景里*/
	CGeneralTower* Memu(cocos2d::Vec2 pos, CGeneralTower* choose = NULL);

	/*启动*/
	bool init();

	/*增加炮塔模型*/
	bool addModel(SGeneralTowerModel* model);

	/*返回炮塔数量*/
	int getCurTowerNum();

	/*
	* 改变局部炮塔的状态
	* void setCondition(cocos2d::Vec2 pos);
	*/

	CREATE_FUNC(CTowerMgr);
protected:
	/*用于刷新攻击*/
	void update(float dt);

	/*申请生成一个塔并返回指针*/
	CGeneralTower* createTower(SGeneralTowerModel* model, cocos2d::Vec2 pos);

	/*删除一个塔并返回指针*/
	CGeneralTower* removeTower(CGeneralTower* move_tower);

	/*用于访问怪物池*/
	CMonsterMgr* m_pMyMonsterMgr;

	/*用于管理游戏金额*/
	CGold* m_pMyGold;

	/*表示当前塔数*/
	int m_iCurTowerNum;

	/*当前拥有的所有炮塔*/
	std::vector<CGeneralTower*> m_rgMyTowerList;

	/*当前拥有的所有模型*/
	std::vector<SGeneralTowerModel*> m_rgMyTowerModel;
};

#endif
