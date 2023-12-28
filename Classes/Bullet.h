/*
2251918 ����ΰ 12 28 ver1.0
*/
/*
ver1.0 �ӵ����ͷ�ļ�����
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

	static CBullet* createWithData(const SBulletData& refSInitData);
	bool initWithData(const SBulletData& refSInitData);

	void attackMove(float flDeltaTime);		//ʵ�ֹ������ƶ�����
	bool checkCollision();					//����Ƿ���ײ������
	void didAttack();						//ʵ�ֹ���Ч��


protected:
	CC_SYNTHESIZE(int, m_iMyDamage, MyDamage);	//�˺�
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed); //�ٶ�


	CMonster* m_pCAimedMonster;				//Ŀ�����ָ��

};

#/*endif //!NORMAL_BULLET_SPEED*/
#endif // !BULLET
