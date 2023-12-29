#pragma once
/*
* ���ʶ�
*
* 2023/12/25
* 2023/12/29
*
* �����������ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
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
	/*��ʾ��ǰ����*/
	CC_SYNTHESIZE(int, m_iCurWaveNum, CurWaveNum);

	/*��ʾ��ǰ���±�*/
	CC_SYNTHESIZE(int, m_iCurMonIndex, CurMonIndex);
public:
	/*��ѡ��Ŀ¼�����ѡ�е��ǿյأ�Ĭ��NULL�����ѡ���б�,�������ʾ�����б�,����ʹ�õĽ������*/
	int Memu(Vec2 pos, CGeneralTower* choose = NULL);

	 /*����ˢ�¹���*/
	 bool init();

	 /*��������ģ��*/
	 bool addModel(SGeneralTowerModel model);

	/*
	* �ı�ֲ�������״̬
	* void setCondition()
	*/

	CREATE_FUNC(CTowerMgr);
protected:
	/*��������һ����������ָ��*/
	CGeneralTower* createTower(SGeneralTowerModel* model, Vec2 pos);

	/*�ж�mgr����û��������͵�ģ��*/
	bool search(SGeneralTowerModel* model);

	/*��ǰӵ�е���������*/
	std::list<CGeneralTower> m_lMyTowerList;

	/*��ǰӵ�е�����ģ��*/
	std::vector<SGeneralTowerModel> m_rgMyTowerModel;

	/*���ڷ��ʹ����*/
	CMonsterMgr* m_pMyMonsterMgr;
};

#endif
