/*
2251918 刘骏伟 2023 12 25 ver1.0
*/
/*
ver1.0 怪物血条类
*/

#ifndef MONSTERHPUI
#define MONSTERHPUI
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class CMonsterHpUI : public Node {
public:
	CMonsterHpUI();
	virtual ~CMonsterHpUI();

	static CMonsterHpUI* create(const std::string& name);//创造血条显示

	bool initWith();									//初始化

	void showCurHealthRate(float flCurRate);			//更新血条

protected:
	CC_SYNTHESIZE(float, m_flMyHealthRate, MyHealthRate);//血条比
	ui::LoadingBar* m_MonsterHealthBar;					//血条
};


#endif // !MONSTERHPUI
