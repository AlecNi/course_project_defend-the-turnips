#pragma once
/*
* ���ʶ�
*
* 2023/12/29
*
* �ܲ������ͷ�ļ�
* ����������ѡ�������Ҳ�֪��zzy����û�������ͻ��ɾ����
* (��Щע���а�������δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
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