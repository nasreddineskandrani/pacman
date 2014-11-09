#include "NSRendererComponent.h"

NSRendererComponent::NSRendererComponent(CCSprite* p_pSprite)
	: NSComponent()
{
	m_pSprite = p_pSprite;
	m_eType = NSComponent::ComponentType::eType::eRenderer;
}

void NSRendererComponent::Update()
{
	//m_pSprite->cocos2d::Node::draw();
}	

NSComponent::ComponentType::eType NSRendererComponent::GetType()
{
	return m_eType;
}	