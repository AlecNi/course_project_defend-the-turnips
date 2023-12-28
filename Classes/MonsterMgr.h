/*
2251918 ����ΰ 2023 12 25 ver1.0
2251918 ����ΰ 2023 12 28 ver1.1
*/
/*
ver1.0 ����һ������������࣬��Ҫ������������ʱ�����պͲ��ο���
ver1.1 �޸Ľӿ�create->creatWithData
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

	bool WaveStart();			//���ο�ʼ,�����Զ�
	void MonsterGenerate();		//���������߼���һ������������
	void MonsterDeathMgr(CMonster* pMonster);	//������������
	bool isFinished() const;			//�����Ƿ���Ϸ�Ѿ�����
protected:
	CC_SYNTHESIZE(int, m_iCurWaveNum, CurWaveNum);	//��ʾ��ǰ����
	CC_SYNTHESIZE(int, m_iCurMonIndex, CurMonIndex);//��ʾ��ǰ�����±�
	SWaveData* m_pWaveData;							//��������
	std::vector<CMonster*> m_pActiveMonsterList;	//��Ծ�����
	std::vector<CMonster*> m_pInActiveMonsterList; //����Ծ�����
};


#endif // !MONSTERMGR
