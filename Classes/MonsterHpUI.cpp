#include "MonsterHpUI.h"
#include "DataMgr.h"

CMonsterHpUI::CMonsterHpUI()
	:m_flMyHealthRate(100.0f)
{

}

CMonsterHpUI::~CMonsterHpUI()
{
	
}

CMonsterHpUI* CMonsterHpUI::create(SHpUIData* pHp)
{
	CMonsterHpUI* pUI = new CMonsterHpUI;
	if (nullptr != pUI && pUI->init(pHp))
	{
		pUI->autorelease();
		return pUI;
	}
	CC_SAFE_DELETE(pUI);
	return nullptr;
}

bool CMonsterHpUI::init(SHpUIData* pHp)
{
	if (!Node::init)
	{
		return false;
	}

	m_pMonsterHealthBar = ui::LoadingBar::create();
	m_pMonsterHealthBar->loadTexture(pHp->strFillName, ui::LoadingBar::TextureResType::LOCAL);
	m_pMonsterHealthBar->loadTexture(pHp->strBackName, ui::LoadingBar::TextureResType::LOCAL);
	m_pMonsterHealthBar->setDirection(ui::LoadingBar::Direction::LEFT);
	m_pMonsterHealthBar->setPercent(m_flMyHealthRate);

	m_pMonsterHealthBar->setContentSize(Size(100,10));
	return true;

}

void CMonsterHpUI::showCurHealthRate(float flCurRate)
{
	if (flCurRate <= 0 || flCurRate > 100)
	{
		return;
	}

	setMyHealthRate(flCurRate);
	m_pMonsterHealthBar->setPercent(m_flMyHealthRate);
}
