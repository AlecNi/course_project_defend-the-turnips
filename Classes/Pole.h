#pragma once
/*
* ���ʶ�
* 2023/12/25
* 
* �ص�ģ��ͷ�ļ�
* 
* ʵ�ֹ���������ص�
*/

#ifndef _POLE_H
#define _POLE_H

#include <list>

#include "Tower.h"

template<typename T>
class CPole{
public:
	/**/
	bool init();
	bool push(T* node);
	bool pop();

	int poleSize() const;
	/*int typeCount(T* node) const;*/

protected:

	int m_MySize;
	std::list<CGeneralTower> m_MyPole;

private:
};

#endif
