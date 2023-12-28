/*
2251918����ΰ 2023 12 24 ver1.0
2251918����ΰ 2023 12 28 ver1.1
*/

/*
ver1.0 ���������������ͷ�ļ�
ver1.1 �޸���deathBehavior,������һ������Ϊ�����ָ��
	   ������һ���ڲ��������Ա�ʾ��ǰ�ߵ��ڼ���·
	   �޸���һЩ������������glod->gold��ע��ʵ�ֵĵ���
	   �޸�damage�Ĳ���Ϊint iDamageHealth��������ٵ�Ѫ��
*/

#ifndef CMONSTER
#define CMONSTER

#include "cocos2d.h"
#include <vector>
#include <string>

#include "MonsterHpUI.h"
USING_NS_CC;

class CBullet;
class SMonsterData;
class GameLevel;
class CGold;

class CMonster : public Sprite {
public:
	CMonster();
	virtual ~CMonster();

	static CMonster* createWithData(const SMonsterData& SInitData);

	bool initWithData(const SMonsterData& SInitData);//��ʼ������
	void initAutoMove();			//��ʼ���Զ��ƶ�
	void updateMove(float flDelta);	//�����ƶ�����
	void damage(int iDamageHealth);	//���˽ӿ�

	void deathBehavior();			//����������Ϊ
	float getDistanceToCarrot() const;	//���ؾ����յ����
	int getGoldNum() const;				//��ȡ����������
	bool IsActive() const;				//���ص�ǰ�Ƿ��Ծ�ӿ�

	void setActive();			//����Ϊ��Ծ
	void setInActive();			//����Ϊ����Ծ
protected:
	CC_SYNTHESIZE(int, m_iMyHealth, MyHealth);			//��Ѫ��
	CC_SYNTHESIZE(int, m_iMyNowHealth, MyNowHealth);	//��ǰѪ��
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed);			//�ٶ�
	CC_SYNTHESIZE(int, m_iMyDeHealth, MyDeHealth);		//�۳��ܲ�����ֵ
	CC_SYNTHESIZE(std::vector<Vec2>, m_vecMyPath, MyPath);//�����ж�·��
	CC_SYNTHESIZE(float, m_flMyDeSpeedRate, MyDeSpeedRate);//�ٶȼ��ٱ���
	CC_SYNTHESIZE(int, m_iMyGoldNum, MyGoldNum);		//������ý����
	CC_SYNTHESIZE(bool, m_fMyIsActive, MyIsActive);		//��ʾ��Ծ״̬
	CC_SYNTHESIZE(int, m_iMyNowPath, MyNowPath);		//��ʾ��ǰ�ƶ����ڼ���λ��


	CMonsterHpUI* m_pHpUI;								//����Ѫ��ui
};
#endif // !CMONSTER
