/*
2251918 刘骏伟 2023 12 25 ver1.0
2251918 刘骏伟 2023 12 28 ver1.1
*/
/*
ver1.0 这是一个怪物管理器类，主要负责怪物的生成时机把握和波次控制
ver1.1 修改接口create->creatWithData
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

	static CMonsterMgr* createWithData(SWaveData& initData);

	bool initWithData(SWaveData& initData);

	void WaveStart();			//波次开始
	void MonsterGenerate();		//怪物生成逻辑

	bool isFinished();			//返回是否游戏已经结束
protected:
	CC_SYNTHESIZE(int, m_iCurWaveNum, CurWaveNum);	//表示当前波次
	SWaveData* m_pWaveData;							//波次数据
	std::vector<CMonster*> m_vecActiveMonsterList;	//活跃怪物池
	std::vector<CMonster*> m_vecInActiveMonsterList; //不活跃怪物池
};


#endif // !MONSTERMGR
