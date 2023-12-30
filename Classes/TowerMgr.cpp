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

        // ����һ���˵�
        auto menu = cocos2d::Menu::create();
        menu->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(menu);

        // ����һ����ť��
        auto menuItem = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Click me!", "fonts/Marker Felt.ttf", 24),
            CC_CALLBACK_1(CTowerMemu::menuCallback, this));
        menu->addChild(menuItem);

        return true;
    }

    // ��ť����ص�
    void menuCallback(Ref* sender)
    {
        // ����һ�������˵�
        auto popupMenu = cocos2d::Menu::create();

        // ���ѡ��
        auto option1 = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Option 1", "fonts/Marker Felt.ttf", 24),
            CC_CALLBACK_1(CTowerMemu::optionCallback, this));
        popupMenu->addChild(option1);

        auto option2 = cocos2d::MenuItemLabel::create(cocos2d::Label::createWithTTF("Option 2", "fonts/Marker Felt.ttf", 24),
            CC_CALLBACK_1(CTowerMemu::optionCallback, this));
        popupMenu->addChild(option2);

        // ���õ����˵�λ��
        popupMenu->setPosition(cocos2d::Vec2(240, 160));

        // �������˵���ӵ�����
        this->addChild(popupMenu);
    }

    // ѡ�����ص�
    void optionCallback(Ref* sender)
    {
        CCLOG("Option selected!");
    }

    CREATE_FUNC(CTowerMemu);
};