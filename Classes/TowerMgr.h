#pragma once
/*
* 倪朗恩 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
* 2023/12/31 ver1.3
* 
* 防御塔管理的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*/

#ifndef _TOWER_MGR_H
#define _TOWER_MGR_H

#include <vector>
#include "cocos2d.h"

struct STowerMgrData;
struct SGeneralTowerModel;
class CGeneralTower;
class CMonsterMgr;
class CMonster;
class CGold;

class CTowerMgr : public cocos2d::Layer {
public:
	virtual ~CTowerMgr();

	/*初始化数据*/
	static CTowerMgr* createWithData(STowerMgrData* pInitData,CMonsterMgr* mgr, CGold* gold);

	/*打开选择目录，如果选中的是空地（默认NULL）则打开选择列表,否则会显示升级列表,返回生成的塔的坐标，方便addChild到场景里*/
	void Memu(cocos2d::Vec2 pos);

	/*判断是否按到按钮*/
	bool insideLabel(const cocos2d::Vec2& pos);

	/*清除所有按钮，附属于menuCallBack操作*/
	void removeLabel();

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
protected:
	CREATE_FUNC(CTowerMgr);

	/*用于刷新攻击*/
	void update(float dt);

	/*申请生成一个塔并返回指针*/
	CGeneralTower* createTower(SGeneralTowerModel* model, cocos2d::Vec2 pos);

	/*删除一个塔并判断是否成功*/
	bool removeTower(CGeneralTower* move_tower);

	/*在空地生成塔的目录*/
	void menuInEmpty(cocos2d::Vec2 pos);

	/*升级或回收塔的目录*/
	void menuNotInEmpty(CGeneralTower* choose, cocos2d::Vec2 pos);

	/*根据位置找到塔*/
	CGeneralTower* searchTower(cocos2d::Vec2 pos);

	/*用于访问怪物池*/
	CMonsterMgr* m_pMyMonsterMgr;

	/*用于管理游戏金额*/
	CGold* m_pMyGold;

	/*表示当前塔数*/
	int m_iCurTowerNum;

	/*管理menu选项按钮*/
	std::vector<cocos2d::MenuItemLabel*> m_rgMyLabel;

	/*当前拥有的所有炮塔*/
	std::vector<CGeneralTower*> m_rgMyTowerList;

	/*当前拥有的所有模型*/
	std::vector<SGeneralTowerModel*> m_rgMyTowerModel;
private:
};

#endif
