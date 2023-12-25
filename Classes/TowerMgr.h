#pragma once
/*
* 倪朗恩
*
* 2023/12/25
*
* 防御塔管理的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*/

#ifndef _TOWER_MGR_H
#define _TOWER_MGR_H

#include <list>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "Tower.h"
#include "Monster.h"

class CTowerMgr {
public:
	/*升级炮塔*/
	bool upgrades();

	/*更新攻击*/
	bool updateAttack(CGeneralTower*& tower);

	/*
	* 改变局部炮塔的状态
	* void setCondition()
	*/

	/*申请生成一个塔并返回指针*/
	[[nodiscard]] static CGeneralTower* create(CGeneralTowerModel*& base);

private:
	/*attack函数的从属函数*/
	CMonster* search(CGeneralTower*& tower);

	CPole<CMonster>& m_MyMonsterPole;
	CPole<CGeneral>& m_MyTowerPole;
}


#endif