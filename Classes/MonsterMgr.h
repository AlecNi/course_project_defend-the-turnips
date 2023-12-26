/*
2251918 ����ΰ 2023 12 25 ����
*/
/*
����һ������������࣬��Ҫ������������ʱ�����պͲ��ο���
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

	static CMonsterMgr* create(SWaveData& initData);

	bool initWithData(SWaveData& initData);

	void WaveStart();			//���ο�ʼ
	void MonsterGenerate();		//���������߼�

	bool isFinished();			//�����Ƿ���Ϸ�Ѿ�����
protected:
	CC_SYNTHESIZE(int, m_iCurWaveNum, CurWaveNum);	//��ʾ��ǰ����
	SWaveData* m_pWaveData;							//��������
	std::vector<CMonster*> m_vecActiveMonsterList;	//��Ծ�����
	std::vector<CMonster*> m_vecInActiveMonsterList; //����Ծ�����
};


#endif // !MONSTERMGR
