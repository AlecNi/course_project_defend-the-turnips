/*
����ΰ 2023 12 24
*/

/*
���������������ͷ�ļ�
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

class CMonster : public Node {
public:
	CMonster();
	virtual ~CMonster();

	static CMonster* create(const SMonsterData& SInitData);

	bool initWithData(const SMonsterData& SInitData);//��ʼ������
	void initAutoMove();			//��ʼ���Զ��ƶ�
	void updateMove(float flDelta);	//�����ƶ�����
	void damage(CBullet* pBullet);	//���˽ӿ�

	void deathBehavior();			//����������Ϊ
	float getDistanceToCarrot() const;	//���ؾ����յ����
	int getGlodNum() const;				//��ȡ����������
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
	CC_SYNTHESIZE(int, m_iMyGlodNum, MyGlodNum);		//������ý����
	CC_SYNTHESIZE(bool, m_fMyIsActive, MyIsActive);		//��ʾ��Ծ״̬



	CMonsterHpUI* m_pHpUI;								//����Ѫ��ui
};
#endif // !CMONSTER
