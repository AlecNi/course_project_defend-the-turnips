/*
2251918 ����ΰ 12 28 ver1.0
2251918 ����ΰ 12 29 ver1.1
2251918 ����ΰ 12 29 ver1.2
*/
/*
ver1.0 �ӵ����ͷ�ļ�����
ver1.1 ���ӽӿ�,ö�٣�
	   �޸Ĳ�������
	   ���ӹ������Ͳ���
	   ������ָ��
	   �޸Ļ��࣬Node->Sprite
	   �������ֹ������͵�ѡ��
ver1.2 �޸�creat�Ĳ������� p->pCGeneralTower
	   �޸Ĳ��ֽӿڲ���
	   ���ӻ�Ծ״̬�Ĳ�����ʾ
*/

#ifndef BULLET
#define BULLET

#include "cocos2d.h"
#include <functional>

USING_NS_CC;

struct SBulletData;

class CMonster;
class CGeneralTower;

enum ATTACKTYPE
{
	/*һ�����ӵ�����*/
	ONCE_ATTACK,

	/*����׷�ٹ���*/
	CONTINUE_ATTACK,

	/*ֱ�߾����ӵ�����*/
	DIRECT_ATTACK
};

class CBullet : public Sprite {
public:
	CBullet();
	virtual ~CBullet();

	static CBullet* createWithData(SBulletData* pInitData,CGeneralTower* pTower);
	bool initWithData(SBulletData* pInitData);

	void attack();										//ʵ�ֹ�������,�������

	void CollisionAttack(float flDeltaTime);			//�ӵ�������ײ����
	void ContinueAttack(float flDeltaTime);				//�������������
	void DirectAttack(float flDeltaTime);				//������ֱ���ӵ�����

	const bool IsCollisionWith(CMonster* pMonster);		//����Ƿ���ײ
	void MakeDamage(CMonster* pMonster);				//�Թ�������˺�

	void setAimedMonster(CMonster* pAimedMonster);		//���ù���Ŀ��
	void setFatherTower(CGeneralTower* pT);				//���÷�����ӵ�����
	void setBulletDamage(int iDamage);					//�����ӵ��˺�
	void setInActive();									//����Ϊ�ǻ�Ծ
protected:
	CC_SYNTHESIZE(int, m_iMyDamage, MyDamage);			//ÿ�ι����˺�
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed);			//�ٶ�
	CC_SYNTHESIZE(int, m_iMyAttackType, MyAttackType);	//��������
	CC_SYNTHESIZE(bool, m_fIsActive, IsActive);			//��ʾ��Ծ״̬

	Vec2 m_Direction;						//��ʾ��ǰ�ƶ�����ֱ�����ӵ�ר��
	CMonster* m_pAimedMonster;				//Ŀ�����ָ��
	CGeneralTower* m_pTowerFrom;					//�������ӵ�����ָ��

};

#endif // !BULLET
