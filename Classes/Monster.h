/*
刘骏伟 2023 12 24
*/

/*
单个怪物的类声明头文件
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

	bool initWithData(const SMonsterData& SInitData);//初始化函数
	void initAutoMove();			//初始化自动移动
	void updateMove(float flDelta);	//更新移动操作
	void damage(CBullet* pBullet);	//受伤接口

	void deathBehavior();			//定义死亡行为
	float getDistanceToCarrot() const;	//返回距离终点距离
	int getGlodNum() const;				//获取怪物金币数量
	bool IsActive() const;				//返回当前是否活跃接口

	void setActive();			//设置为活跃
	void setInActive();			//设置为不活跃
protected:
	CC_SYNTHESIZE(int, m_iMyHealth, MyHealth);			//总血量
	CC_SYNTHESIZE(int, m_iMyNowHealth, MyNowHealth);	//当前血量
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed);			//速度
	CC_SYNTHESIZE(int, m_iMyDeHealth, MyDeHealth);		//扣除萝卜生命值
	CC_SYNTHESIZE(std::vector<Vec2>, m_vecMyPath, MyPath);//怪物行动路径
	CC_SYNTHESIZE(float, m_flMyDeSpeedRate, MyDeSpeedRate);//速度减少比率
	CC_SYNTHESIZE(int, m_iMyGlodNum, MyGlodNum);		//死亡获得金币数
	CC_SYNTHESIZE(bool, m_fMyIsActive, MyIsActive);		//表示活跃状态



	CMonsterHpUI* m_pHpUI;								//怪物血量ui
};
#endif // !CMONSTER
