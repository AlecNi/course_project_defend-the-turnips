#pragma once
/*
* ���ʶ�
*
* 2023/12/25
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

class CCarrot :public cocos2d::Sprite {
public:
	CCarrot(std::string& path, int&& hp);

	/*��ʼ��*/
	bool initHp(int&& i = 1);

	/*�ܲ�����*/
	bool damage(CMonster* success_monster);

	/*
	* �ܲ��Ķ�������
	* void trumble();
	*/

	/*��������һ���ܲ�������ָ��(ͦ���ݵ�)*/
	[[nodiiscard]] static CCarrot* create(std::string& path, int&& hp = 3);

protected:
	/*damage�����Ĵ���,�����ܲ�Ѫ������ʾ*/
	void updateHp();

	int m_MyHp;
	std::string m_sMyPath;

private:
};

#endif