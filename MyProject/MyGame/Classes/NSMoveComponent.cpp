#include "NSMoveComponent.h"

NSMoveComponent::NSMoveComponent(CCSprite* p_pSprite)
	: NSComponent()
{
	m_pSprite = p_pSprite;
	m_sType = "MOVE";
}

void NSMoveComponent::Update(std::string p_sAction)
{
	if (p_sAction == "MOVE_LEFT") 
	{
		m_pSprite->setPositionX(m_pSprite->getPositionX()-10);
	}
	else if (p_sAction == "MOVE_RIGHT") 
	{
		m_pSprite->setPositionX(m_pSprite->getPositionX()+10);
	}
	else if (p_sAction == "MOVE_DOWN") 
	{
		m_pSprite->setPositionY(m_pSprite->getPositionY()-10);
	}
	else if (p_sAction == "MOVE_UP") 
	{
		m_pSprite->setPositionY(m_pSprite->getPositionY()+10);
	}
}	

std::string NSMoveComponent::GetType()
{
	return m_sType;
}	

