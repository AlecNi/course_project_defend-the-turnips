#pragma once
/*
* ���ʶ�
*
* 2023/12/25
* * 2023/12/29
*
* �ܲ���ͷ�ļ�
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
*
* �ܲ�������ͬ���ӽ��ڹ�������ֳ���
*/

#ifndef _CARROT_H
#define _CARROT_H

#include "cocos2d.h"

class CMonster;

class CCarrot :public cocos2d::Sprite {

	/*Ѫ��*/
	CC_SYNTHESIZE(int, m_iMyHp, MyHp);

public:
	/*��ʼ��*/
	bool initHp(int&& i = 3);

	/*�ܲ�����,����true��ʾ����*/
	bool damage(int iDamageHealth);

	/*
	* �ܲ��Ķ�������
	* void trumble();
	*/

	/*��������һ���ܲ�������ָ��(ͦ���ݵ�)*/
	CREATE_FUNC(CCarrot);

protected:
	/*damage�����Ĵ���,�����ܲ�Ѫ������ʾ*/
	void updateHp();

	/*ͼƬ·��*/
	std::string m_sMyPath;
private:
};

#endif