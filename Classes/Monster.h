/*
2251918刘骏伟 2023 12 24 ver1.0
2251918刘骏伟 2023 12 28 ver1.1
2251918刘骏伟 2023 12 28 ver1.2
*/

/*
ver1.0 单个怪物的类声明头文件
ver1.1 修改了deathBehavior,增加了一个参数为金币类指针
	   增加了一个内部参数用以表示当前走到第几段路
	   修改了一些命名，集中在glod->gold，注意实现的调用
	   修改damage的参数为int iDamageHealth，代表减少的血量
ver1.2 增加了一个成员变量，用以表示该怪物对应的怪物管理器指针
	   增加了一个用以设定对应管理器的接口setMgr
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
class CGold;
class CMonsterMgr;

class CMonster : public Sprite {
public:
	CMonster();
	virtual ~CMonster();

	static CMonster* createWithData(SMonsterData* pSInitData);

	bool initWithData(SMonsterData* pSInitData);//初始化函数
	void initAutoMove();			//初始化自动移动
	void updateMove(float flDelta);	//更新移动操作
	void damage(int iDamageHealth);	//受伤接口

	void deathBehavior();				//定义死亡行为
	float getDistanceToCarrot() const;	//返回距离终点距离
	int getGoldNum() const;				//获取怪物金币数量
	bool IsActive() const;				//返回当前是否活跃接口

	void setActive();	//设置为活跃
	void setInActive();	//设置为不活跃
	void setMgr(CMonsterMgr* pMonsterMgr);	//设置怪物管理器
protected:
	CC_SYNTHESIZE(int, m_iMyHealth, MyHealth);			//总血量
	CC_SYNTHESIZE(int, m_iMyNowHealth, MyNowHealth);	//当前血量
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed);			//速度
	CC_SYNTHESIZE(int, m_iMyDeHealth, MyDeHealth);		//扣除萝卜生命值
	CC_SYNTHESIZE(std::vector<Vec2>, m_vecMyPath, MyPath);//怪物行动路径
	CC_SYNTHESIZE(float, m_flMyDeSpeedRate, MyDeSpeedRate);//速度减少比率
	CC_SYNTHESIZE(int, m_iMyGoldNum, MyGoldNum);		//死亡获得金币数
	CC_SYNTHESIZE(bool, m_fMyIsActive, MyIsActive);		//表示活跃状态
	CC_SYNTHESIZE(int, m_iMyNowPath, MyNowPath);		//表示当前移动到第几段位置
	
	CMonsterMgr* m_pMonsterMgr;							//管理器
	CMonsterHpUI* m_pHpUI;								//怪物血量ui
};
#endif // !CMONSTER
