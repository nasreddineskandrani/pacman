#include "NSMoveComponent.h"

NSMoveComponent::NSMoveComponent(CCSprite* p_pSprite)
	: NSComponent()
{
	m_pSprite = p_pSprite;
	p_nCachedDirectionX = 22;
	p_nCachedDirectionY = 22;
	m_sType = "MOVE";
}

void NSMoveComponent::Update(float p_fDelta, int p_nDirectionX, int p_nDirectionY, int p_nSpeed, int p_nWantedIndexW, int p_nWantedIndexH)
{

	
}	

std::string NSMoveComponent::GetType()
{
	return m_sType;
}	

CCSprite* NSMoveComponent::GetSprite()
{
	return m_pSprite;
}	

