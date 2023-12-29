/*
2251918ljw ver1.0 �������ݽṹ�壬���νṹ�壬�ӵ��ṹ��

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
	/*�ӵ���ͼ�ļ���*/
	std::string strBulletFrame;
};

struct SHpUIData
{
	/*���ͼ*/
	std::string strFillName;
	/*����ͼ*/
	std::string strBackName;
};