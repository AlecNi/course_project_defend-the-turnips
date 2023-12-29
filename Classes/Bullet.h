/*
2251918 刘骏伟 12 28 ver1.0
*/
/*
ver1.0 子弹类的头文件声明
ver1.1 增加接口,枚举，
	   修改部分命名
	   增加攻击类型参数
	   增加塔指针
	   修改基类，Node->Sprite
	   增加三种攻击类型的选择
*/

#ifndef BULLET
#define BULLET

#include "cocos2d.h"
#include <functional>

USING_NS_CC;

struct SBulletData;

class CMonster;
class CTower;

enum ATTACKTYPE
{
	/*一次性子弹攻击*/
	ONCE_ATTACK,

	/*持续追踪攻击*/
	CONTINUE_ATTACK,

	/*直线距离子弹攻击*/
	DIRECT_ATTACK
};
void func1()
{
	return;
}
class CBullet : public Sprite {
public:
	CBullet();
	virtual ~CBullet();

	static CBullet* createWithData(SBulletData* pInitData,CTower* p);
	bool initWithData(SBulletData* pInitData);

	void attackMove(float flDeltaTime);		//实现攻击功能

	void CollisionAttack();					//子弹定点碰撞攻击
	void ContinueAttack();					//激光类持续攻击
	void DirectAttack();					//风扇类直线子弹攻击

	void setAimedMonster(CMonster* pAimedMonster);	//设置攻击目标
	void setFatherTower(CTower* pT);		//设置发射该子弹的塔
	void setBulletDamage() const;			//设置子弹伤害
	
protected:
	CC_SYNTHESIZE(int, m_iMyDamage, MyDamage);			//每次攻击伤害
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed);			//速度
	CC_SYNTHESIZE(int, m_iMyAttackType, MyAttackType);	//攻击类型

	/*攻击函数指针数组*/
	std::vector<std::function<void()>> m_pAttackFunction = {
		std::bind(CBullet::CollisionAttack,this),
		std::bind(CBullet::ContinueAttack,this),
		std::bind(CBullet::DirectAttack,this)	
	};
	CMonster* m_pAimedMonster;				//目标怪物指针
	CTower* m_pTowerFrom;					//产生该子弹的塔指针

};

#endif // !BULLET
