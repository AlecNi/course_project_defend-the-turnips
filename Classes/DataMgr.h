/*
2251918ljw ver1.0 �������ݽṹ�壬���νṹ�壬�ӵ��ṹ��

*/


#include <vector>
#include <string>
#include <cocos2d.h>
USING_NS_CC;

struct SMonsterData
{
	int m_iMyHealth;
	int m_iMyNowHealth;
	float m_flMySpeed;
	int m_iMyDeHealth;
	std::vector<Vec2> m_vecMyPath;
	int m_iMyGoldNum;
	//ͼƬ����
	std::string m_strFrameName;
};

struct SWaveData
{
	int m_iWaveNum;
	std::vector<SMonsterData*> m_pMonsterData;
	std::vector<float> m_flWaveTime;
	std::vector<int> m_iWaveMonsterNum;
	std::vector<float> m_flMonsterWaitTime;
};

struct SBulletData;