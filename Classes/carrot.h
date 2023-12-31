#pragma once
/*
* ���ʶ� 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
*
* �ܲ���ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
*
* �ܲ�������ͬ���ӽ��ڹ�������ֳ���
*/

#ifndef _CARROT_H
#define _CARROT_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class CCarrotMgr;
class CMonster;
class CMonsterMgr;

class CCarrot :public cocos2d::Sprite {

	/*Ѫ��*/
	CC_SYNTHESIZE(int, m_iMyHp, MyHp);

public:
	virtual ~CCarrot();

	/*ˢ��Ѫ����ʾ*/
	bool init();

	static CCarrot* createWithData(cocos2d::Vec2 pos, CMonsterMgr* mgr);

	/*�ܲ�����,����true��ʾ����*/
	bool update();

	/*
	* �ܲ��Ķ�������
	* void trumble();
	*/

protected:
	/*��������һ���ܲ�������ָ��(ͦ���ݵ�)*/
	CREATE_FUNC(CCarrot);

	/*�ܲ�����,����true��ʾ����*/
	bool damage(CMonster* monster);

	cocos2d::Label* m_pMyHpUI;

	CMonsterMgr* m_pMyMonsterMgr;
private:
};

#endif