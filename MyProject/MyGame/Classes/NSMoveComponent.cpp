#include "NSMoveComponent.h"

NSMoveComponent::NSMoveComponent(CCSprite* p_pSprite)
	: NSComponent()
{
	m_pSprite = p_pSprite;
	m_sType = "MOVE";
}

void NSMoveComponent::Update(float p_fDelta, std::string p_sAction)
{
	float speed = +400.0f;
	if (p_sAction == "MOVE_LEFT") 
	{
		m_pSprite->setPositionX(m_pSprite->getPositionX()+(-1)*speed*p_fDelta);
	}
	else if (p_sAction == "MOVE_RIGHT") 
	{
		m_pSprite->setPositionX(m_pSprite->getPositionX()+(+1)*speed*p_fDelta);
	}
	else if (p_sAction == "MOVE_DOWN") 
	{
		m_pSprite->setPositionY(m_pSprite->getPositionY()+(-1)*speed*p_fDelta);
	}
	else if (p_sAction == "MOVE_UP") 
	{
		m_pSprite->setPositionY(m_pSprite->getPositionY()+(+1)*speed*p_fDelta);
	}
}	

std::string NSMoveComponent::GetType()
{
	return m_sType;
}	

