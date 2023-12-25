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

class CGeneralCondition {
public:
	CGeneralCondition(ConditionType type,std::string name);
	
	const ConditionType getConditionType() const;
	const std::string& getConditionName() const;

protected:
	ConditionType m_CTMyType;
	std::string m_sMyName;
private:
};

#endif