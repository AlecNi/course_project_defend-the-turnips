/*
2251918 ����ΰ 2023 12 25 ver1.0
2251918 ����ΰ 2023 12 28 ver1.1
2251918 ����ΰ 2023 12 29 ver1.2
*/
/*
ver1.0 ����һ������������࣬��Ҫ������������ʱ�����պͲ��ο���
ver1.1 �޸Ľӿ�create->creatWithData
ver1.2 ���ӽӿڣ����Է��ػ�Ծ�б�
*/
#ifndef MONSTERMGR
#define MONSTERMGR

#include "cocos2d.h"
#include "Monster.h"
#include <vector>
USING_NS_CC;

struct SWaveData;

class CMonsterMgr : public Layer {
public:
	CMonsterMgr();
	virtual ~CMonsterMgr();

	static CMonsterMgr* createWithData(SWaveData* pSInitData);

	bool initWithData(SWaveData* pSInitData);

	bool WaveStart();								//���ο�ʼ,�����Զ�
	void MonsterGenerate();							//���������߼���һ������������
	void MonsterDeathMgr(CMonster* pMonster);		//������������һ��ֻ�����������
	const bool isFinished() const;					//�����Ƿ���Ϸ�Ѿ�����

	const std::vector<CMonster*> getActiveMonsterList() const;	//���ػ�Ծ�����б�
protected:
	CC_SYNTHESIZE(int, m_iCurWaveNum, CurWaveNum);	//��ʾ��ǰ����
	CC_SYNTHESIZE(int, m_iCurMonIndex, CurMonIndex);//��ʾ��ǰ�����±�
	SWaveData* m_pWaveData;							//��������
	std::vector<CMonster*> m_pActiveMonsterList;	//��Ծ�����
	std::vector<CMonster*> m_pInActiveMonsterList;	//����Ծ�����
};


#endif // !MONSTERMGR
