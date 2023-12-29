#include <list>
#include "cocos2d.h"
#include "Tower.h"
#include "TowerMgr.h"
USING_NS_CC;

int CTowerMgr::Memu(Vec2 pos, CGeneralTower* choose)
{
    auto menu = cocos2d::Menu::create();
    addChild(menu);

    if (choose == NULL) {
        SGeneralTowerModel* model;

        /*生成选项*/
        for (int i = m_rgMyTowerModel.size(); i; --i) {
            model = &m_rgMyTowerModel[i];

            /*谁能告诉我字体路径*/
            auto numberLabel = Label::createWithTTF(std::to_string(model->m_pMyCost[0]), "fonts/arial.ttf", 24);

            /*未裁剪的图片，因为我不知道格式*/
            auto imageSprite = Sprite::create(model->m_sMyPath);

            MenuItemLabel* menuItem = MenuItemLabel::create(numberLabel, [this, menuItem, model, pos, i](Ref* sender) {
                if (sender == menuItem) {
                    if (createTower(model, pos)) {
                        CCLOG("create tower %s!", );
                        return model->m_pMyCost[0];
                    }
                    else
                        return 0;
                }
                else
                    return 0;
                });
            menuItem->addChild(imageSprite);

            // 设置菜单项位置
            menuItem->setPosition(pos + Vec2(20, 20 * i - 10 - m_rgMyTowerModel.size() * 10));

            // 将菜单项添加到菜单中
            menu->addChild(menuItem);
        }
    }
    else {
        SGeneralTowerModel* model = choose->getModel();

        /*说明创建炮塔时有问题*/
        if (model == NULL)
            return -1;

        int max_level = model->m_iMyMaxLevel;
        int now_level = choose->getMyLevel();

        if (max_level == now_level) {
            /*说明满级*/
            return 0;
        }

        /*生成选项*/
        /*谁能告诉我字体路径*/
        auto numberLabel = Label::createWithTTF(std::to_string(model->m_pMyCost[now_level]), "fonts/arial.ttf", 24);

        /*未裁剪的图片，因为我不知道格式*/
        auto imageSprite = Sprite::create(model->m_sMyPath);

        MenuItemLabel* menuItem = MenuItemLabel::create(numberLabel, [this, menuItem, model, pos, now_level](Ref* sender) {
            if (sender == menuItem) {
                    if (createTower(model, pos)) {
                        CCLOG("upgrade!", 1);
                        return model->m_pMyCost[now_level];
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            });
        menuItem->addChild(imageSprite);

        menuItem->setPosition(pos + Vec2(20, 10));

        menu->addChild(menuItem);

        /*删除选项*/
        /*谁能告诉我字体路径*/
        numberLabel = Label::createWithTTF(std::to_string(-model->m_pMyCost[now_level] / 2), "fonts/arial.ttf", 24);

        /*未裁剪的图片，因为我不知道格式*/
        imageSprite = Sprite::create(model->m_sMyPath);

        menuItem = MenuItemLabel::create(numberLabel, [this, menuItem, model, pos, now_level](Ref* sender) {
            if (sender == menuItem) {
                if (createTower(model, pos)) {
                    CCLOG("Delete!", 2);
                    if (createTower(model, pos))
                        /*回收金币机制*/
                        return -model->m_pMyCost[now_level] / 2;
                }
                else
                    return 0;
            }
            else
                return 0;
            });
        menuItem->addChild(imageSprite);

        menuItem->setPosition(pos + Vec2(20, -10));

        menu->addChild(menuItem);
    }
}
