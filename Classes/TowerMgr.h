#pragma once
/*
* ���ʶ�
*
* 2023/12/25
*
* �����������ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
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
	/*��������*/
	bool upgrades();

	/*���¹���*/
	bool updateAttack(CGeneralTower*& tower);

	/*
	* �ı�ֲ�������״̬
	* void setCondition()
	*/

	/*��������һ����������ָ��*/
	[[nodiscard]] static CGeneralTower* create(CGeneralTowerModel*& base);

private:
	/*attack�����Ĵ�������*/
	CMonster* search(CGeneralTower*& tower);

	CPole<CMonster>& m_MyMonsterPole;
	CPole<CGeneral>& m_MyTowerPole;
}


#endif