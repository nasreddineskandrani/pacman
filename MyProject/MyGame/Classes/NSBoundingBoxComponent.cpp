#include "NSBoundingBoxComponent.h"

NSBoundingBoxComponent::NSBoundingBoxComponent(CCSprite* p_pSprite)
	: NSComponent()
{
	m_pSprite = p_pSprite;
	m_pBoundingBox = m_pSprite->getBoundingBox();
	m_sType = "BOUNDING_BOX";
}

void NSBoundingBoxComponent::Update(float p_fDelta)
{
	m_pBoundingBox = m_pSprite->getBoundingBox();
}	

std::string NSBoundingBoxComponent::GetType()
{
	return m_sType;
}	

CCRect NSBoundingBoxComponent::GetBoundingBox()
{
	return m_pBoundingBox;
}	