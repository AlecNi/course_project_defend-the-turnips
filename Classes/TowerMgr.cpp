/*
* 2251334 ���ʶ�
*
* 2023/12/25 ver1.0
* 2023/12/29 ver1.1
* 2023/12/30 ver1.2
* 2023/12/31 ver1.3
*
* ��������ʵ���ļ�
*/
#include "ui/CocosGUI.h"
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
        removeChild(m_rgMyTowerList.back(), true);

        m_rgMyTowerList.pop_back();
    }

    if (!m_rgMyLabel.empty())
        removeLabel();
}

CTowerMgr* CTowerMgr::createWithData(CMonsterMgr* mgr, CGold* gold)
{
    m_pMyMonsterMgr = mgr;
    m_pMyGold = gold;

    return this;
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

inline int CTowerMgr::getCurTowerNum()
{
    return m_iCurTowerNum;
}

CGeneralTower* CTowerMgr::createTower(SGeneralTowerModel* model, Vec2 pos)
{
    auto new_tower = CGeneralTower::create();

    /*�����ڲ�����*/
    new_tower->createWithData(model, this, 1);

    new_tower->initByModel();

    /*���þ�������*/
    new_tower->setScale(0.5f);

    /*���þ���λ��*/
    new_tower->setPosition(Vec2(100, 100));

    /*��ӽ�����*/
    addChild(new_tower);

    m_rgMyTowerList.push_back(new_tower);
    ++m_iCurTowerNum;

    return new_tower;
}

bool CTowerMgr::removeTower(CGeneralTower* move_tower)
{
    for (int i = 0; i < m_rgMyTowerList.size(); ++i)
        if (m_rgMyTowerList[i] == move_tower) {
            removeChild(move_tower);
            --m_iCurTowerNum;

            return true;
        }

    return false;
}

inline CGeneralTower* CTowerMgr::searchTower(cocos2d::Vec2 pos)
{
    for (int i = 0; i < m_rgMyTowerList.size(); ++i)
        if (m_rgMyTowerList[i]->getPosition() == pos)
            return m_rgMyTowerList[i];

    return nullptr;
}

inline bool CTowerMgr::insideLabel(const Vec2& pos)
{
    for (auto& label : m_rgMyLabel)
        if (label->getBoundingBox().containsPoint(pos))
            return true;

    return false;
}

inline void CTowerMgr::removeLabel()
{
    for (auto& label : m_rgMyLabel){
        removeChild(label);
    }

    m_rgMyLabel.clear();
}

void CTowerMgr::menuInEmpty(Vec2 pos)
{
    SGeneralTowerModel* model;

    /*����ѡ��*/
    for (int i = 0; i < m_rgMyTowerModel.size(); ++i) {
        model = m_rgMyTowerModel[i];

        /*˭�ܸ���������·��*/
        auto numberLabel = Label::createWithTTF(std::to_string(model->m_pMyCost[0]), "fonts/arial.ttf", 24);

        /*δ�ü���ͼƬ����Ϊ�Ҳ�֪����ʽ*/
        auto imageSprite = Sprite::create(model->m_sMyPath);

        MenuItemLabel* menuItem = MenuItemLabel::create(numberLabel,
            [this, menuItem, model, pos](Ref* sender) {
                if (sender == menuItem) {
                    m_pMyGold->spendGolds(model->m_pMyCost[0]);

                    createTower(model, pos);
                }
            });
        menuItem->addChild(imageSprite);

        /*���ò˵���λ��*/
        menuItem->setPosition(pos + Vec2(20, 20 * i - 10 - m_rgMyTowerModel.size() * 10));

        /*���˵�����ӵ��˵���*/
        addChild(menuItem);
    }
}

void CTowerMgr::menuNotInEmpty(CGeneralTower* choose, Vec2 pos)
{
    auto choose = searchTower(pos);
    auto model = choose->getModel();

    /*˵����������ʱ������*/
    if (model == nullptr)
        return;

    int max_level = model->m_iMyMaxLevel;
    int now_level = choose->getMyLevel();

    if (max_level == now_level)
        /*˵������*/
        return;

    /*����ѡ��*/
    /*˭�ܸ���������·��*/
    auto numberLabel = Label::createWithTTF(std::to_string(model->m_pMyCost[now_level]), "fonts/arial.ttf", 24);

    /*δ�ü���ͼƬ����Ϊ�Ҳ�֪����ʽ*/
    auto imageSprite = Sprite::create(model->m_sMyPath);

    MenuItemLabel* menuItem = MenuItemLabel::create(numberLabel,
        [this, menuItem, model, pos, now_level, choose](Ref* sender) {
            if (sender == menuItem) {
                m_pMyGold->spendGolds(model->m_pMyCost[now_level]);

                createTower(model, pos);
            }
        });
    menuItem->addChild(imageSprite);

    menuItem->setPosition(pos + Vec2(20, 10));

    addChild(menuItem);


    /*ɾ��ѡ��*/
    /*˭�ܸ���������·��*/
    numberLabel = Label::createWithTTF(std::to_string(-model->m_pMyCost[now_level] / 2), "fonts/arial.ttf", 24);

    /*δ�ü���ͼƬ����Ϊ�Ҳ�֪����ʽ*/
    imageSprite = Sprite::create(model->m_sMyPath);

    /*����һ��*/
    menuItem = MenuItemLabel::create(numberLabel,
        [this, menuItem, model, pos, now_level, choose](Ref* sender) {
            if (sender == menuItem) {
                m_pMyGold->addGolds(model->m_pMyCost[now_level - 1] / 2);

                createTower(model, pos);
            }
        });
    menuItem->addChild(imageSprite);

    menuItem->setPosition(pos + Vec2(20, -10));

    addChild(menuItem);
}

void CTowerMgr::Memu(Vec2 pos)
{
    CGeneralTower* choose = searchTower(pos);

    /*����ѡ��*/
    if (choose == nullptr)
        menuInEmpty(pos);
    /*����ѡ��*/
    else
        menuNotInEmpty(choose, pos);
}
