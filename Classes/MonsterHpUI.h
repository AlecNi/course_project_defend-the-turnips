/*
2251918 ����ΰ 2023 12 25 ver1.0
*/
/*
ver1.0 ����Ѫ����
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

	static CMonsterHpUI* create(const std::string& name);//����Ѫ����ʾ

	bool initWith();									//��ʼ��

	void showCurHealthRate(float flCurRate);			//����Ѫ��

protected:
	CC_SYNTHESIZE(float, m_flMyHealthRate, MyHealthRate);//Ѫ����
	ui::LoadingBar* m_MonsterHealthBar;					//Ѫ��
};


#endif // !MONSTERHPUI
