#include "NSBoundingBoxComponent.h"

NSBoundingBoxComponent::NSBoundingBoxComponent(CCSprite* p_pSprite)
	: NSComponent()
{
	m_pSprite = p_pSprite;
	m_pBoundingBox = m_pSprite->getBoundingBox();
	m_eType = NSComponent::ComponentType::eBoundingBox;
}

void NSBoundingBoxComponent::Update(float p_fDelta)
{
	m_pBoundingBox = m_pSprite->getBoundingBox();
}	

NSComponent::ComponentType::eType NSBoundingBoxComponent::GetType()
{
	return m_eType;
}	

CCRect NSBoundingBoxComponent::GetBoundingBox()
{
	return m_pBoundingBox;
}	