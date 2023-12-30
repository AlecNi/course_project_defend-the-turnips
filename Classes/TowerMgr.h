#pragma once
/*
* 倪朗恩
*
* 2023/12/25
* 2023/12/29
*
* 防御塔管理的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*/

#ifndef _TOWER_MGR_H
#define _TOWER_MGR_H

#include <list>
#include "cocos2d.h"

struct SGeneralTowerModel;
class CGeneralTower;
class CMonsterMgr;
class CMonster;

class CTowerMgr : public cocos2d::Layer {
	/*表示当前塔数*/
	CC_SYNTHESIZE(int, m_iCurWaveNum, CurWaveNum);

	/*表示当前塔下标*/
	CC_SYNTHESIZE(int, m_iCurMonIndex, CurMonIndex);
public:
	/*升级炮塔*/
	bool upgrades();

	/*更新攻击*/
	bool update(CGeneralTower*& tower);

	/*
	* 改变局部炮塔的状态
	* void setCondition()
	*/

	/*启动后可以打开塔的选项*/
	bool start();

	CREATE_FUNC(CTowerMgr);
protected:
	/*申请生成一个塔并返回指针*/
	CGeneralTower* create(SGeneralTowerModel*& base);

	/*attack函数的从属函数*/
	CMonster* search(CGeneralTower*& tower);

	std::list<CMonsterMgr> m_lMyMonsterList;

	CMonsterMgr* m_pMyMonsterMgr;
};

/*用来管理选塔，但我不知道zzy做了没，如果冲突就删掉*/
class CTowerMemu : public cocos2d::Scene
{
public:
    virtual bool init();

    // 按钮点击回调
	void menuCallback(Ref* sender);

    // 选项点击回调
	void optionCallback(Ref* sender);

    CREATE_FUNC(CTowerMemu);
};

#endif