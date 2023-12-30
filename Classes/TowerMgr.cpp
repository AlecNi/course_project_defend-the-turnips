#include <list>
#include "cocos2d.h"
#include "TowerMgr.h"

class CTowerMemu : public cocos2d::Scene
{
public:
    virtual bool init()
    {
        if (!Scene::init())
        {
            return false;
        }

        // 创建一个菜单
        auto menu = cocos2d::Menu::create();
        menu->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(menu);

        // 创建一个按钮项
        auto menuItem = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Click me!", "fonts/Marker Felt.ttf", 24),
            CC_CALLBACK_1(CTowerMemu::menuCallback, this));
        menu->addChild(menuItem);

        return true;
    }

    // 按钮点击回调
    void menuCallback(Ref* sender)
    {
        // 创建一个弹出菜单
        auto popupMenu = cocos2d::Menu::create();

        // 添加选项
        auto option1 = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Option 1", "fonts/Marker Felt.ttf", 24),
            CC_CALLBACK_1(CTowerMemu::optionCallback, this));
        popupMenu->addChild(option1);

        auto option2 = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Option 2", "fonts/Marker Felt.ttf", 24),
            CC_CALLBACK_1(CTowerMemu::optionCallback, this));
        popupMenu->addChild(option2);

        // 设置弹出菜单位置
        popupMenu->setPosition(cocos2d::Vec2(240, 160));

        // 将弹出菜单添加到场景
        this->addChild(popupMenu);
    }

    // 选项点击回调
    void optionCallback(Ref* sender)
    {
        CCLOG("Option selected!");
    }

    CREATE_FUNC(CTowerMemu);
};