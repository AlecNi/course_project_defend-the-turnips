#ifndef __GOLD_H__
#define __GOLD_H__

#include "cocos2d.h"

class CGold : public cocos2d::Sprite {
public:
    virtual bool init();
    CREATE_FUNC(CGold);

    // ���ӽ������
    void addGolds(int amount);

    // ���ٽ������
    bool spendGolds(int amount);

    // ��ȡ��ǰ�������
    int getGolds() const;

    // ���½�ұ�ǩ��ʾ
    void updateLabel();

private:
    int goolds; // �������
    cocos2d::Label* label; // ������ʾ��������ı�ǩ
};

#endif // __GOLD_H__

