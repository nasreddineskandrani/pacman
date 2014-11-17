#include "NSSoundComponent.h"
#include <SimpleAudioEngine.h>

NSSoundComponent::NSSoundComponent()
	: NSComponent()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/test.wav");
}

void NSSoundComponent::Update()
{
	
}	

NSComponent::ComponentType::eType NSSoundComponent::GetType()
{
	return m_eType;
}	

void NSSoundComponent::PlayCurrentSound()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(m_sCurrentSound.c_str()); 
	m_sCurrentSound = "";
}
