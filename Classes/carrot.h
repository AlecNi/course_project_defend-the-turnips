#pragma once
/*
* 倪朗恩
*
* 2023/12/25
*
* 萝卜的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*
* 萝卜与塔不同更接近于怪物故区分出来
*/
#ifndef _CARROT_H
#define _CARROT_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class CCarrot :public cocos2d::Sprite {
public:
	CCarrot(std::string& path, int&& hp);

	/*初始化*/
	bool initHp(int&& i = 1);

	/*萝卜受伤*/
	bool damage(CMonster* success_monster);

	/*
	* 萝卜的抖动动画
	* void trumble();
	*/

	/*申请生成一个萝卜并返回指针(挺生草的)*/
	[[nodiiscard]] static CCarrot* create(std::string& path, int&& hp = 3);

protected:
	/*damage函数的从属,更新萝卜血量及提示*/
	void updateHp();

	int m_MyHp;
	std::string m_sMyPath;

private:
};

#endif