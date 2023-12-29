/*
2251918 刘骏伟 12 28 ver1.0
2251918 刘骏伟 12 29 ver1.1
2251918 刘骏伟 12 29 ver1.2
*/
/*
ver1.0 子弹类的头文件声明
ver1.1 增加接口,枚举，
	   修改部分命名
	   增加攻击类型参数
	   增加塔指针
	   修改基类，Node->Sprite
	   增加三种攻击类型的选择
ver1.2 修改creat的参数命名 p->pCGeneralTower
	   修改部分接口参数
	   增加活跃状态的参数表示
*/

#ifndef BULLET
#define BULLET

#include "cocos2d.h"
#include <functional>

USING_NS_CC;

struct SBulletData;

class CMonster;
class CGeneralTower;

enum ATTACKTYPE
{
	/*一次性子弹攻击*/
	ONCE_ATTACK,

	/*持续追踪攻击*/
	CONTINUE_ATTACK,

	/*直线距离子弹攻击*/
	DIRECT_ATTACK
};

class CBullet : public Sprite {
public:
	CBullet();
	virtual ~CBullet();

	static CBullet* createWithData(SBulletData* pInitData,CGeneralTower* pTower);
	bool initWithData(SBulletData* pInitData);

	void attack();										//实现攻击功能,请用这个

	void CollisionAttack(float flDeltaTime);			//子弹定点碰撞攻击
	void ContinueAttack(float flDeltaTime);				//激光类持续攻击
	void DirectAttack(float flDeltaTime);				//风扇类直线子弹攻击

	const bool IsCollisionWith(CMonster* pMonster);		//检测是否碰撞
	void MakeDamage(CMonster* pMonster);				//对怪物造成伤害

	void setAimedMonster(CMonster* pAimedMonster);		//设置攻击目标
	void setFatherTower(CGeneralTower* pT);				//设置发射该子弹的塔
	void setBulletDamage(int iDamage);					//设置子弹伤害
	void setInActive();									//设置为非活跃
protected:
	CC_SYNTHESIZE(int, m_iMyDamage, MyDamage);			//每次攻击伤害
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed);			//速度
	CC_SYNTHESIZE(int, m_iMyAttackType, MyAttackType);	//攻击类型
	CC_SYNTHESIZE(bool, m_fIsActive, IsActive);			//表示活跃状态

	Vec2 m_Direction;						//表示当前移动方向，直线类子弹专属
	CMonster* m_pAimedMonster;				//目标怪物指针
	CGeneralTower* m_pTowerFrom;					//产生该子弹的塔指针

};

#endif // !BULLET
