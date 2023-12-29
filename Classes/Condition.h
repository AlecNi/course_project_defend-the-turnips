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

struct SGeneralCondition {
	ConditionType m_CTMyType;
	std::string m_sMyName;
};

#endif