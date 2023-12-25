#pragma once
/*
* 倪朗恩
*
* 2023/12/25
*
* 状态的头文件
* (未实现而时间充裕可实现的功能)
* 
* 如冰冻、持续扣血等
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