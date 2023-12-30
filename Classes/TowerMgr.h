#pragma once
/*
* ���ʶ� 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
*
* �����������ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
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

	/*��ʼ������*/
	virtual CTowerMgr* initData(CMonsterMgr* mgr, CGold* gold);

	/*��ѡ��Ŀ¼�����ѡ�е��ǿյأ�Ĭ��NULL�����ѡ���б�,�������ʾ�����б�,�������ɵ��������꣬����addChild��������*/
	CGeneralTower* Memu(cocos2d::Vec2 pos, CGeneralTower* choose = NULL);

	/*����*/
	bool init();

	/*��������ģ��*/
	bool addModel(SGeneralTowerModel* model);

	/*������������*/
	int getCurTowerNum();

	/*
	* �ı�ֲ�������״̬
	* void setCondition(cocos2d::Vec2 pos);
	*/

	CREATE_FUNC(CTowerMgr);
protected:
	/*����ˢ�¹���*/
	void update(float dt);

	/*��������һ����������ָ��*/
	CGeneralTower* createTower(SGeneralTowerModel* model, cocos2d::Vec2 pos);

	/*ɾ��һ����������ָ��*/
	CGeneralTower* removeTower(CGeneralTower* move_tower);

	/*���ڷ��ʹ����*/
	CMonsterMgr* m_pMyMonsterMgr;

	/*���ڹ�����Ϸ���*/
	CGold* m_pMyGold;

	/*��ʾ��ǰ����*/
	int m_iCurTowerNum;

	/*��ǰӵ�е���������*/
	std::vector<CGeneralTower*> m_rgMyTowerList;

	/*��ǰӵ�е�����ģ��*/
	std::vector<SGeneralTowerModel*> m_rgMyTowerModel;
};

#endif
