/*
2251918 ����ΰ 2023 12 25 ver1.0
*/
/*
ver1.0 ����Ѫ����
ver1.1 �޸���create�ӿں�init�ӿڵĲ���������
	   �޸��˱�������
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

	static CMonsterHpUI* create(SHpUIData* pHp);//����Ѫ����ʾ

	bool init(SHpUIData* pHp);									//��ʼ��

	void showCurHealthRate(float flCurRate);			//����Ѫ��

protected:
	CC_SYNTHESIZE(float, m_flMyHealthRate, MyHealthRate);//Ѫ����
	ui::LoadingBar* m_pMonsterHealthBar;					//Ѫ��
};


#endif // !MONSTERHPUI
