/*
2251918 刘骏伟 2023 12 25 ver1.0
*/
/*
ver1.0 怪物血条类
ver1.1 修改了create接口和init接口的参数及命名
	   修改了变量命名
*/

#ifndef MONSTERHPUI
#define MONSTERHPUI
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
class SHpUIData;

class CMonsterHpUI : public Node {
public:
	CMonsterHpUI();
	virtual ~CMonsterHpUI();

	static CMonsterHpUI* create(SHpUIData* pHp);//创造血条显示

	bool init(SHpUIData* pHp);									//初始化

	void showCurHealthRate(float flCurRate);			//更新血条

protected:
	CC_SYNTHESIZE(float, m_flMyHealthRate, MyHealthRate);//血条比
	ui::LoadingBar* m_pMonsterHealthBar;					//血条
};


#endif // !MONSTERHPUI
