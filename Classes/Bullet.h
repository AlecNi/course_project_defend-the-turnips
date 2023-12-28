/*
2251918 刘骏伟 12 28 ver1.0
*/
/*
ver1.0 子弹类的头文件声明
*/

#ifndef BULLET
#define BULLET

#include "cocos2d.h"

USING_NS_CC;

struct SBulletData;

class CMonster;
/*#ifndef NORMAL_BULLET_SPEED //NORMAL_BULLET_SPEED
//定义子弹一般速度
#define NORMAL_BULLET_SPEED 10*/

class CBullet : public Node {
public:
	CBullet();
	virtual ~CBullet();

	static CBullet* createWithData(const SBulletData& refSInitData);
	bool initWithData(const SBulletData& refSInitData);

	void attackMove(float flDeltaTime);		//实现攻击性移动功能
	bool checkCollision();					//检测是否碰撞到敌人
	void didAttack();						//实现攻击效果


protected:
	CC_SYNTHESIZE(int, m_iMyDamage, MyDamage);	//伤害
	CC_SYNTHESIZE(float, m_flMySpeed, MySpeed); //速度


	CMonster* m_pCAimedMonster;				//目标怪物指针

};

#/*endif //!NORMAL_BULLET_SPEED*/
#endif // !BULLET
