#pragma once
/*
* ���ʶ� 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
* 2023/12/31 ver1.3
* 
* �����������ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
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

	/*��ʼ������*/
	static CTowerMgr* createWithData(STowerMgrData* pInitData,CMonsterMgr* mgr, CGold* gold);

	/*��ѡ��Ŀ¼�����ѡ�е��ǿյأ�Ĭ��NULL�����ѡ���б�,�������ʾ�����б�,�������ɵ��������꣬����addChild��������*/
	void Memu(cocos2d::Vec2 pos);

	/*�ж��Ƿ񰴵���ť*/
	bool insideLabel(const cocos2d::Vec2& pos);

	/*������а�ť��������menuCallBack����*/
	void removeLabel();

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
protected:
	CREATE_FUNC(CTowerMgr);

	/*����ˢ�¹���*/
	void update(float dt);

	/*��������һ����������ָ��*/
	CGeneralTower* createTower(SGeneralTowerModel* model, cocos2d::Vec2 pos);

	/*ɾ��һ�������ж��Ƿ�ɹ�*/
	bool removeTower(CGeneralTower* move_tower);

	/*�ڿյ���������Ŀ¼*/
	void menuInEmpty(cocos2d::Vec2 pos);

	/*�������������Ŀ¼*/
	void menuNotInEmpty(CGeneralTower* choose, cocos2d::Vec2 pos);

	/*����λ���ҵ���*/
	CGeneralTower* searchTower(cocos2d::Vec2 pos);

	/*���ڷ��ʹ����*/
	CMonsterMgr* m_pMyMonsterMgr;

	/*���ڹ�����Ϸ���*/
	CGold* m_pMyGold;

	/*��ʾ��ǰ����*/
	int m_iCurTowerNum;

	/*����menuѡ�ť*/
	std::vector<cocos2d::MenuItemLabel*> m_rgMyLabel;

	/*��ǰӵ�е���������*/
	std::vector<CGeneralTower*> m_rgMyTowerList;

	/*��ǰӵ�е�����ģ��*/
	std::vector<SGeneralTowerModel*> m_rgMyTowerModel;
private:
};

#endif
