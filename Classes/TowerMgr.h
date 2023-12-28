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
	/*��������*/
	bool upgrades();

	/*���¹���*/
	bool update(CGeneralTower*& tower);

	/*
	* �ı�ֲ�������״̬
	* void setCondition()
	*/

	/*��������Դ�����ѡ��*/
	bool start();

	CREATE_FUNC(CTowerMgr);
protected:
	/*��������һ����������ָ��*/
	CGeneralTower* create(SGeneralTowerModel*& base);

	/*attack�����Ĵ�������*/
	CMonster* search(CGeneralTower*& tower);

	std::list<CMonsterMgr> m_lMyMonsterList;

	CMonsterMgr* m_pMyMonsterMgr;
};

/*��������ѡ�������Ҳ�֪��zzy����û�������ͻ��ɾ��*/
class CTowerMemu : public cocos2d::Scene
{
public:
    virtual bool init();

    // ��ť����ص�
	void menuCallback(Ref* sender);

    // ѡ�����ص�
	void optionCallback(Ref* sender);

    CREATE_FUNC(CTowerMemu);
};

#endif