#include "NSRendererComponent.h"

NSRendererComponent::NSRendererComponent(CCSprite* p_pSprite)
	: NSComponent()
{
	m_pSprite = p_pSprite;
	m_sType = "RENDER";
}

void NSRendererComponent::Update()
{
	//m_pSprite->cocos2d::Node::draw();
}	

std::string NSRendererComponent::GetType()
{
	return m_sType;
}	