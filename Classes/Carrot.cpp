/*
* 倪朗恩
*
* 2023/12/25
* * 2023/12/29
*
* 萝卜的头文件
* (有些注释中包含部分未实现而时间充裕可实现的功能)
*
* 萝卜与塔不同更接近于怪物故区分出来
*/
#include "Carrot.h"
#include "CarrotMgr.h"

inline bool CCarrotMgr::init()
{
    if (!Scene::init()){
        return false;
    }

    // 创建一个 Text 对象
    auto label = cocos2d::ui::Text::create();
    label->setString("Hp: " + std::to_string(m_CMyCarrot->getMyHp()));
    label->setPosition(cocos2d::Vec2(240, 160));
    label->setFontSize(24);
    this->addChild(label);

    // 模拟更新分数
    int Hp = m_CMyCarrot->getMyHp();
    this->schedule([label, &Hp, this] (float dt) {
        // 模拟更新分数，每隔一秒增加10分
        Hp = m_CMyCarrot->getMyHp();
    label->setString("Hp: " + std::to_string(Hp));
        }, 1.0f, "update_score");

    return true;
}