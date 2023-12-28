/*
2251918 ����ΰ 12 28 ver1.0
*/
/*
ver1.0 �ӵ����ͷ�ļ�����
ver1.1 ���ӽӿ�
*/

#ifndef BULLET
#define BULLET

#include "cocos2d.h"

USING_NS_CC;

struct SBulletData;

class CMonster;
/*#ifndef NORMAL_BULLET_SPEED //NORMAL_BULLET_SPEED
//�����ӵ�һ���ٶ�
#define NORMAL_BULLET_SPEED 10*/

class CBullet : public Node {
public:
	CBullet();
	virtual ~CBullet();

	static CBullet* createWithData(SBulletData* pSInitData);
	bool initWithData(SBulletData* pSInitData);

	void attackMove(float flDeltaTime);		//ʵ�ֹ������ƶ�����
	bool checkCollision();					//����Ƿ���ײ������
	void didAttack();						//ʵ�ֹ���Ч��
	void setAimedMonster(CMonster* pAimedMonster);	//���ù���Ŀ��

protected:
	CC_SYNTHESIZE(int, m_iMyDamage, MyDamage);	//�˺�
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed); //�ٶ�


	CMonster* m_pAimedMonster;				//Ŀ�����ָ��

};

#/*endif //!NORMAL_BULLET_SPEED*/
#endif // !BULLET
