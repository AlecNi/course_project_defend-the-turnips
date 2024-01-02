/*
* 2251334 倪朗恩
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
* 2023/12/31 ver1.3
*
* 防御塔的实现文件
*/

#include "TowerMgr.h"
#include "Tower.h"
#include "MonsterMgr.h"
#include "gold.h"
#include "Bullet.h"
#include "DataMgr.h"
USING_NS_CC;

CTowerMgr::CTowerMgr()
{

}

CTowerMgr::~CTowerMgr()
{
    while (!m_rgMyTowerList.empty()) {
        removeChild(m_rgMyTowerList.back(), true);

        m_rgMyTowerList.pop_back();
    }

    if (!m_rgMyLabel.empty())
        removeLabel();
}

CTowerMgr* CTowerMgr::createWithData(STowerMgrData* pInitData,CMonsterMgr* mgr, CGold* gold)
{
    CTowerMgr* pTowerMgr = CTowerMgr::create();

    if (pTowerMgr != nullptr) {
        pTowerMgr->m_rgMyTowerModel = pInitData->m_rgTowerModel;
        pTowerMgr->m_pMyMonsterMgr = mgr;
        pTowerMgr->m_pMyGold = gold;
        //pTowerMgr

        return pTowerMgr;
    }

    return nullptr;
}

bool CTowerMgr::init()
{
    if (!Layer::init()) {
        return false;
    }

    m_iCurTowerNum = 0;
    m_rgMyLabel.clear();
    m_rgMyTowerList.clear();
    m_rgMyTowerModel.clear();

    schedule(CC_SCHEDULE_SELECTOR(CTowerMgr::update));

    return true;
}

void CTowerMgr::update(float dt)
{
    std::vector<CMonster*> vec_mon;
    m_pMyMonsterMgr->getActiveMonsterList(vec_mon);
    std::vector<Vec2> tower_pos;
    std::vector<Vec2> monster_pos;

    for (int i = 0; i < m_rgMyTowerList.size(); ++i)
        tower_pos.push_back(m_rgMyTowerList[i]->getPosition());

    for (int i = 0; i < vec_mon.size(); ++i)
        monster_pos.push_back(vec_mon[i]->getPosition());

    for (int i = 0; i < tower_pos.size(); ++i) {
        float tmp_len2tower = m_rgMyTowerList[i]->getMyAttackRage(), tmp_len2carrot = 65535;
        CMonster* target = nullptr;
        CBullet* bullet;

        for (int j = 0; j < monster_pos.size(); ++j)
            if ((tower_pos[i] - monster_pos[j]).length() <= tmp_len2tower)
                if (vec_mon[j]->getDistanceToCarrot() < tmp_len2carrot) {
                    tmp_len2tower = (tower_pos[i] - monster_pos[j]).length();
                    tmp_len2carrot = vec_mon[j]->getDistanceToCarrot();

                    target = vec_mon[j];
                }

        if (target != nullptr)
            m_rgMyTowerList[i]->attack(target, dt);
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

int CTowerMgr::getCurTowerNum()
{
    return m_iCurTowerNum;
}

CGeneralTower* CTowerMgr::createTower(SGeneralTowerModel* model, Vec2 pos)
{
    auto new_tower = CGeneralTower::createWithData(model, this);

    if (new_tower == nullptr)
        return nullptr;

    new_tower->initByModel();

    /*设置精灵缩放*/
    new_tower->setScale(0.5f);

    /*设置精灵位置*/
    new_tower->setPosition(Vec2(100, 100));

    /*添加进场景*/
    addChild(new_tower);

    m_rgMyTowerList.push_back(new_tower);
    ++m_iCurTowerNum;

    return new_tower;
}

bool CTowerMgr::removeTower(CGeneralTower* move_tower)
{
    for (int i = 0; i < m_rgMyTowerList.size(); ++i)
        if (m_rgMyTowerList[i] == move_tower) {
            removeChild(move_tower, true);
            --m_iCurTowerNum;

            return true;
        }

    return false;
}

CGeneralTower* CTowerMgr::searchTower(cocos2d::Vec2 pos)
{
    for (int i = 0; i < m_rgMyTowerList.size(); ++i)
        if (m_rgMyTowerList[i]->getPosition() == pos)
            return m_rgMyTowerList[i];

    return nullptr;
}

bool CTowerMgr::insideLabel(const Vec2& pos)
{
    for (auto& label : m_rgMyLabel)
        if (label->getBoundingBox().containsPoint(pos))
            return true;

    return false;
}

void CTowerMgr::removeLabel()
{
    for (auto& label : m_rgMyLabel){
        removeChild(label, true);
    }

    m_rgMyLabel.clear();
}

void CTowerMgr::menuInEmpty(Vec2 pos)
{
    SGeneralTowerModel* model;

    /*生成选项*/
    for (int i = 0; i < m_rgMyTowerModel.size(); ++i) {
        model = m_rgMyTowerModel[i];

        /*谁能告诉我字体路径*/
        auto numberLabel = Label::createWithTTF(std::to_string(model->m_pMyCost[0]), "fonts/arial.ttf", 24);

        /*未裁剪的图片，因为我不知道格式*/
        auto imageSprite = Sprite::create(model->m_sMyPath[0]);

        MenuItemLabel* menuItem = MenuItemLabel::create(numberLabel,
            [this, menuItem, model, pos](Ref* sender) {
                if (sender == menuItem) {
                    if(m_pMyGold->spendGolds(model->m_pMyCost[0]))

                    createTower(model, pos);
                }
            });
        if (menuItem != nullptr) {
            menuItem->addChild(imageSprite);

            /*设置菜单项位置*/
            menuItem->setPosition(pos + Vec2(20, 20 * i - 10 - m_rgMyTowerModel.size() * 10));

            /*将菜单项添加到菜单中*/
            addChild(menuItem);
        }
    }
}

void CTowerMgr::menuNotInEmpty(CGeneralTower* choose, Vec2 pos)
{
    auto model = choose->getModel();

    /*说明创建炮塔时有问题*/
    if (model == nullptr)
        return;

    int max_level = model->m_iMyMaxLevel;
    int now_level = choose->getMyLevel();

    if (max_level == now_level)
        /*说明满级*/
        return;

    /*生成选项*/
    /*谁能告诉我字体路径*/
    auto numberLabel = Label::createWithTTF(std::to_string(model->m_pMyCost[now_level]), "fonts/arial.ttf", 24);

    /*未裁剪的图片，因为我不知道格式*/
    auto imageSprite = Sprite::create(model->m_sMyPath[now_level]);

    MenuItemLabel* menuItem = MenuItemLabel::create(numberLabel,
        [this, menuItem, model, pos, now_level, choose](Ref* sender) {
            if (sender == menuItem) {
                if(m_pMyGold->spendGolds(model->m_pMyCost[now_level]))

                createTower(model, pos);
            }
        });
    if (menuItem != nullptr) {
        menuItem->addChild(imageSprite);

        menuItem->setPosition(pos + Vec2(20, 10));

        addChild(menuItem);
    }

    /*删除选项*/
    /*谁能告诉我字体路径*/
    numberLabel = Label::createWithTTF(std::to_string(-model->m_pMyCost[now_level] / 2), "fonts/arial.ttf", 24);

    /*未裁剪的图片，因为我不知道格式*/
    imageSprite = Sprite::create(/**/);

    /*还你一半*/
    menuItem = MenuItemLabel::create(numberLabel,
        [this, menuItem, model, pos, now_level, choose](Ref* sender) {
            if (sender == menuItem) {
                m_pMyGold->addGolds(model->m_pMyCost[now_level - 1] / 2);

                createTower(model, pos);
            }
        });
    if (menuItem != nullptr) {
        menuItem->addChild(imageSprite);

        menuItem->setPosition(pos + Vec2(20, -10));

        addChild(menuItem);
    }
}

void CTowerMgr::Memu(Vec2 pos)
{
    CGeneralTower* choose = searchTower(pos);

    /*创建选项*/
    if (choose == nullptr)
        menuInEmpty(pos);
    /*升级选项*/
    else
        menuNotInEmpty(choose, pos);
}
