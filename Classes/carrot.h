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

class CCarrot :public cocos2d::Sprite {

	/*Ѫ��*/
	CC_SYNTHESIZE(int, m_iMyHp, MyHp);

public:
	virtual ~CCarrot();

	/*ˢ��Ѫ����ʾ*/
	bool init();

	/*�ܲ�����,����true��ʾ����*/
	bool damage(int iDamageHealth);

	/*
	* �ܲ��Ķ�������
	* void trumble();
	*/

	/*��������һ���ܲ�������ָ��(ͦ���ݵ�)*/
	CREATE_FUNC(CCarrot);
protected:
	cocos2d::ui::Text* m_pMyHpUI;
private:
};

#endif