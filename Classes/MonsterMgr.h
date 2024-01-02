/*
2251918 刘骏伟 2023 12 25 ver1.0
2251918 刘骏伟 2023 12 28 ver1.1
2251918 刘骏伟 2023 12 29 ver1.2
2251918 刘骏伟 2023 12 29 ver1.3
*/
/*
ver1.0 这是一个怪物管理器类，主要负责怪物的生成时机把握和波次控制
ver1.1 修改接口create->creatWithData
ver1.2 增加接口，用以返回活跃列表
ver1.3 增加成员:gold类的指针,以及链接gold类的接口
*/
#ifndef MONSTERMGR
#define MONSTERMGR

#include "cocos2d.h"
#include "Monster.h"
#include <vector>
USING_NS_CC;

struct SWaveData;
class CGold;
class CMonsterMgr : public Layer {
public:
	CMonsterMgr();
	virtual ~CMonsterMgr();

	static CMonsterMgr* createWithData(SWaveData* pSInitData);

	bool initWithData(SWaveData* pSInitData);

	bool WaveStart();								//波次开始,后续自动
	void MonsterGenerate();							//怪物生成逻辑，一般情况无需调用
	void MonsterDeathMgr(CMonster* pMonster);		//怪物死亡管理，一般只被怪物类调用
	const bool isFinished() const;					//返回是否游戏已经结束
	void setGoldLink(CGold* pGold);					//建立gold类链接

	void getActiveMonsterList(std::vector<CMonster*>& rgMonsterList) const;	//返回活跃怪物列表
protected:
	CC_SYNTHESIZE(int, m_iCurWaveNum, CurWaveNum);	//表示当前波次
	CC_SYNTHESIZE(int, m_iCurMonIndex, CurMonIndex);//表示当前怪物下标
	SWaveData* m_pWaveData;							//波次数据
	std::vector<CMonster*> m_pActiveMonsterList;	//活跃怪物池
	std::vector<CMonster*> m_pInActiveMonsterList;	//不活跃怪物池
	CGold* m_pGold;									//金币类指针
};


#endif // !MONSTERMGR
