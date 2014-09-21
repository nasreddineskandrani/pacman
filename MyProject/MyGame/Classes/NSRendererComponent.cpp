#include "NSRendererComponent.h"

NSRendererComponent::NSRendererComponent(const std::string& p_sPath, GameScene* gc)
	: NSComponent()
{
	m_pSprite = CCSprite::create(p_sPath);
	m_pSprite->setPosition(440, 440);
	m_pSprite->setScale(0.3);
	gc->addChild(m_pSprite);
}

void NSRendererComponent::Update()
{

}	