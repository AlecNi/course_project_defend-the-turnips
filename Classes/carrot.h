#pragma once
/*
* 倪朗恩 2251334
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
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

class CCarrotMgr;

class CCarrot :public cocos2d::Sprite {

	/*血量*/
	CC_SYNTHESIZE(int, m_iMyHp, MyHp);

public:
	virtual ~CCarrot();

	/*刷新血量显示*/
	bool init();

	/*萝卜受伤,返回true表示死亡*/
	bool damage(int iDamageHealth);

	/*
	* 萝卜的抖动动画
	* void trumble();
	*/

	/*申请生成一个萝卜并返回指针(挺生草的)*/
	CREATE_FUNC(CCarrot);
protected:
	cocos2d::ui::Text* m_pMyHpUI;
private:
};

#endif