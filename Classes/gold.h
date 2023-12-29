#ifndef __GOLD_H__
#define __GOLD_H__

#include "cocos2d.h"

class CGold : public cocos2d::Sprite {
public:
    virtual bool init();
    CREATE_FUNC(CGold);

    // 增加金币数量
    void addGolds(int amount);

    // 减少金币数量
    bool spendGolds(int amount);

    // 获取当前金币数量
    int getGolds() const;

    // 更新金币标签显示
    void updateLabel();

private:
    int goolds; // 金币数量
    cocos2d::Label* label; // 用于显示金币数量的标签
};

#endif // __GOLD_H__

