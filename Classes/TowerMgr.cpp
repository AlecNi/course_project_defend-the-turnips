/*
* 2251334 倪朗恩
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
*
* 防御塔的实现文件
*/
#include "cocos2d.h"
#include "Tower.h"
#include "TowerMgr.h"
#include "MonsterMgr.h"
#include "gold.h"
#include "Bullet.h"
#include "DataMgr.h"
USING_NS_CC;

CTowerMgr::~CTowerMgr()
{
    while (!m_rgMyTowerList.empty()) {
        delete m_rgMyTowerList.back();

        m_rgMyTowerList.pop_back();
    }
}

CTowerMgr* CTowerMgr::initData(CMonsterMgr* mgr, CGold* gold)
{
    m_iCurTowerNum = 0;
    m_pMyMonsterMgr = mgr;
    m_pMyGold = gold;

    return this;
}

bool CTowerMgr::init()
{
    if (!Layer::init()) {
        return false;
    }

    m_rgMyTowerList.clear();
    m_rgMyTowerModel.clear();

    schedule(CC_SCHEDULE_SELECTOR(CTowerMgr::update));

    return true;
}

inline void CTowerMgr::update(float dt)
{
    auto vec_mon = m_pMyMonsterMgr->getActiveMonsterList();
    std::vector<Vec2> tower_pos;
    std::vector<Vec2> monster_pos;

    for (int i = 0; i < m_rgMyTowerList.size(); ++i)
        tower_pos.push_back(m_rgMyTowerList[i]->getPosition());

    for (int i = 0; i < vec_mon.size() - 1; ++i)
        monster_pos.push_back(vec_mon[i]->getPosition());

    for (int i = 0; i < tower_pos.size(); ++i) {
        float tmp_len2tower = m_rgMyTowerList[i]->getMyAttackRage(), tmp_len2carrot = 65535;
        CMonster* target = NULL;
        CBullet* bullet;

        for (int j = 0; j < monster_pos.size(); ++j)
            if ((tower_pos[i] - monster_pos[j]).length() <= tmp_len2tower)
                if (vec_mon[j]->getDistanceToCarrot() < tmp_len2carrot) {
                    tmp_len2tower = (tower_pos[i] - monster_pos[j]).length();
                    tmp_len2carrot = vec_mon[j]->getDistanceToCarrot();

                    target = vec_mon[j];
                }

        if (target != NULL)
            if ((bullet = m_rgMyTowerList[i]->attack(target, dt)) != NULL)
                m_pScene->addChild(bullet);
        create
    }

}

bool CTowerMgr::addModel(SGeneralTowerModel* model)
{
    for (int i = 0; i < m_rgMyTowerList.size(); ++i)
        if (model == m_rgMyTowerModel[i])
            return false;

    m_rgMyTowerModel.push_back(model);

    return true;
}

inline int CTowerMgr::getCurTowerNum()
{
    return m_iCurTowerNum;
}

CGeneralTower* CTowerMgr::createTower(SGeneralTowerModel* model, Vec2 pos)
{
    auto new_tower = CGeneralTower::create();

    /*更新内部数据*/
    new_tower->createWithData(model, this, 1);

    new_tower->initByModel();

    /*设置精灵位置*/
    new_tower->setPosition(Vec2(100, 100));

    /*设置精灵缩放*/
    new_tower->setScale(0.5f);

    /*添加进场景*/
    m_pScene->addChild(new_tower);

    m_rgMyTowerList.push_back(new_tower);
    ++m_iCurTowerNum;

    return new_tower;
}

CGeneralTower* CTowerMgr::removeTower(CGeneralTower* move_tower)
{
    for (int i = 0; i < m_rgMyTowerList.size(); ++i)
        if (m_rgMyTowerModel[i])
            return false;
}

void CTowerMgr::menuCallback(Ref* sender)
{
    /**/
    CCLOG("Menu item clicked!");
}

CGeneralTower* CTowerMgr::Memu(Vec2 pos, CGeneralTower* choose)
{
    auto menu = cocos2d::Menu::create();
    addChild(menu);

    if (choose == NULL) {
        SGeneralTowerModel* model;

        /*生成选项*/
        for (int i = 0; i < m_rgMyTowerModel.size(); ++i) {
            model = m_rgMyTowerModel[i];

            /*谁能告诉我字体路径*/
            auto numberLabel = Label::createWithTTF(std::to_string(model->m_pMyCost[0]), "fonts/arial.ttf", 24);

            /*未裁剪的图片，因为我不知道格式*/
            auto imageSprite = Sprite::create(model->m_sMyPath);

            MenuItemLabel* menuItem = MenuItemLabel::create(numberLabel, CC_CALLBACK_1(CTowerMgr::menuCallback, this));
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
            return NULL;

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

        menuItem = MenuItemLabel::create(numberLabel, [this, menuItem, model, pos, now_level, choose] (Ref * sender) {
            if (sender == menuItem) {
                if (removeTower(choose)) {
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
