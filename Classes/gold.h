/*
* ������
*/
#ifndef __GOLD_H__
#define __GOLD_H__

#include "cocos2d.h"

class CGold : public cocos2d::Sprite {
public:
    CREATE_FUNC(CGold);
    CGold(int coins = 0);
    ~CGold();

    // ���ӽ������
    void addGolds(int amount);

    // ���ٽ������
    bool spendGolds(int amount);

    // ��ȡ��ǰ�������
    int getGolds() const;

    // ���½�ұ�ǩ��ʾ
    void setGolds(int coins);

private:
    int golds; // �������
    cocos2d::Label* label; // ������ʾ��������ı�ǩ
};

#endif // __GOLD_H__

