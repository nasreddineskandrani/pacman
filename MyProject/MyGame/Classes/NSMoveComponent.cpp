#include "NSMoveComponent.h"

NSMoveComponent::NSMoveComponent(CCSprite* p_pSprite)
	: NSComponent()
{
	m_pSprite = p_pSprite;
	m_sType = "MOVE";
}

void NSMoveComponent::Update(float p_fDelta, int p_nDirectionX, int p_nDirectionY, int p_nSpeed)
{
	m_pSprite->setPositionX(m_pSprite->getPositionX()+p_nDirectionX*p_nSpeed*p_fDelta);
	m_pSprite->setPositionY(m_pSprite->getPositionY()+p_nDirectionY*p_nSpeed*p_fDelta);
}	

std::string NSMoveComponent::GetType()
{
	return m_sType;
}	

