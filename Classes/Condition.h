#pragma once
/*
* ���ʶ�
*
* 2023/12/25
*
* ״̬��ͷ�ļ�
* (δʵ�ֶ�ʱ���ԣ��ʵ�ֵĹ���)
* 
* �������������Ѫ��
*/

#ifndef _CONDITION_H
#define _CONDITION_H

#include <string>

enum class ConditionType{};

struct SGeneralCondition {
	ConditionType m_CTMyType;
	std::string m_sMyName;
};

#endif