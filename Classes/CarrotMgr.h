#pragma once
/*
* 倪朗恩
*
* 2023/12/29
*
* 萝卜管理的头文件
* 【用来管理选塔，但我不知道zzy做了没，如果冲突就删掉】
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*/

#ifndef _CARROT_MGR_H
#define _CARROT_MGR_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class CCarrot;

class CCarrotMgr :public cocos2d::Scene {
public:
	virtual bool init();

	CREATE_FUNC(CCarrotMgr);
protected:
	CCarrot* m_pMyCarrot;
private:
};

#endif