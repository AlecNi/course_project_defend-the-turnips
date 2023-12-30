/*
2251918ljw ver1.0 �������ݽṹ�壬���νṹ�壬�ӵ��ṹ��
2251334nle ver1.1 �������ݽṹ�壬��������ö��
*/


#include <vector>
#include <string>
#include <cocos2d.h>
USING_NS_CC;

struct SMonsterData
{
	/*����ֵ����*/
	int m_iMyHealth;
	/*һ���ٶ�*/
	float m_flMySpeed;
	/*���ܲ���ʧ����ֵ*/
	int m_iMyDeHealth;
	/*·������*/
	std::vector<Vec2> m_vecMyPath;
	/*��������������*/
	int m_iMyGoldNum;
	//ͼƬ����
	std::string m_strFrameName;
};

struct SWaveData
{
	/*��������*/
	int m_iWaveNum;
	/*���й�������*/
	std::vector<SMonsterData*> m_pMonsterData;
	/*���ο�ʼǰ�ȴ�ʱ��*/
	std::vector<float> m_flWaveTime;
	/*����ÿ������*/
	std::vector<int> m_iWaveMonsterNum;
	/*����ʱ����*/
	std::vector<float> m_flMonsterWaitTime;
};

struct SBulletData
{
	/*�ӵ��˺��������������˺�����*/
	int iBulletDamage;
	/*�ӵ��ٶ�*/
	float flBulletSpeed;
	/*�ӵ�����*/
	int iAttackType;
};

struct SHpUIData
{
	/*���ͼ*/
	std::string strFillName;
	/*����ͼ*/
	std::string strBackName;
};

/*���Ĺ�������*/
enum class TowerType {
	kSingle,  //���Ե�
	kAOE,  //Ⱥ��
	kAux,  //����
};

struct SGeneralTowerModel {
	/*�������������ȼ��ȼ�,1,2,3...*/
	int m_iMyMaxLevel;

	/*����������������*/
	int* m_pMyCost;

	/*�����ȼ�����������*/
	int* m_pMyBaseAttack;

	/*�����ȼ������������ڣ���λ��*/
	float* m_pMyBaseAttackPeriod;

	/*�����ȼ�����������Χ,*/
	float* m_pMyAttackRage;

	/*�����ȼ��ڿڰ뾶*/
	float* m_fMyBarrelLen;

	/*ת��,��λ��*/
	float m_pMyBaseAngularV = 45;

	/*����*/
	std::string m_sMyName;

	/*��������ͼ����Ϣ*/
	std::string m_sMyPath;

	/*�����ͣ���Ե���aoe���̵�*/
	const TowerType m_kMyType;

	/*�ӵ����ͣ���Ե���aoe���̵�*/
	SBulletData* m_pMyBullet;
};