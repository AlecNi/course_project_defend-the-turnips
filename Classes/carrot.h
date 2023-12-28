#pragma once
/*
* 倪朗恩
*
* 2023/12/25
* * 2023/12/29
*
* 萝卜的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*
* 萝卜与塔不同更接近于怪物故区分出来
*/

#ifndef _CARROT_H
#define _CARROT_H

#include "cocos2d.h"

class CMonster;

class CCarrot :public cocos2d::Sprite {

	/*血量*/
	CC_SYNTHESIZE(int, m_iMyHp, MyHp);

public:
	/*初始化*/
	bool initHp(int&& i = 3);

	/*萝卜受伤,返回true表示死亡*/
	bool damage(int iDamageHealth);

	/*
	* 萝卜的抖动动画
	* void trumble();
	*/

	/*申请生成一个萝卜并返回指针(挺生草的)*/
	CREATE_FUNC(CCarrot);

protected:
	/*damage函数的从属,更新萝卜血量及提示*/
	void updateHp();

	/*图片路径*/
	std::string m_sMyPath;
private:
};

#endif