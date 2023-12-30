/*
2251918 ����ΰ 12 28 ver1.0
*/
/*
ver1.0 �ӵ����ͷ�ļ�����
ver1.1 ���ӽӿ�,ö�٣�
	   �޸Ĳ�������
	   ���ӹ������Ͳ���
	   ������ָ��
	   �޸Ļ��࣬Node->Sprite
	   �������ֹ������͵�ѡ��
*/

#ifndef BULLET
#define BULLET

#include "cocos2d.h"
#include <functional>

USING_NS_CC;

struct SBulletData;

class CMonster;
class CTower;

enum ATTACKTYPE
{
	/*һ�����ӵ�����*/
	ONCE_ATTACK,

	/*����׷�ٹ���*/
	CONTINUE_ATTACK,

	/*ֱ�߾����ӵ�����*/
	DIRECT_ATTACK
};
void func1()
{
	return;
}
class CBullet : public Sprite {
public:
	CBullet();
	virtual ~CBullet();

	static CBullet* createWithData(SBulletData* pInitData,CTower* p);
	bool initWithData(SBulletData* pInitData);

	void attackMove(float flDeltaTime);		//ʵ�ֹ�������

	void CollisionAttack();					//�ӵ�������ײ����
	void ContinueAttack();					//�������������
	void DirectAttack();					//������ֱ���ӵ�����

	void setAimedMonster(CMonster* pAimedMonster);	//���ù���Ŀ��
	void setFatherTower(CTower* pT);		//���÷�����ӵ�����
	void setBulletDamage() const;			//�����ӵ��˺�
	
protected:
	CC_SYNTHESIZE(int, m_iMyDamage, MyDamage);			//ÿ�ι����˺�
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed);			//�ٶ�
	CC_SYNTHESIZE(int, m_iMyAttackType, MyAttackType);	//��������

	/*��������ָ������*/
	std::vector<std::function<void()>> m_pAttackFunction = {
		std::bind(CBullet::CollisionAttack,this),
		std::bind(CBullet::ContinueAttack,this),
		std::bind(CBullet::DirectAttack,this)	
	};
	CMonster* m_pAimedMonster;				//Ŀ�����ָ��
	CTower* m_pTowerFrom;					//�������ӵ�����ָ��

};

#endif // !BULLET
