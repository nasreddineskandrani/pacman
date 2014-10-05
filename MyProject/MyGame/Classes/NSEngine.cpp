#include "NSEngine.h"
//systems
#include "NSGraphicSystem.h"
#include "NSInputActionSystem.h"
#include "NSMoveSystem.h"
//components
#include "NSRendererComponent.h"
#include "NSInputActionComponent.h"
#include "NSMoveComponent.h"

NSEngine::NSEngine(std::map<std::string,CCSprite*>* p_pMapSprites,
				std::list<cocos2d::EventKeyboard::KeyCode>* p_listPressedKey, 
				std::list<cocos2d::EventKeyboard::KeyCode>* p_listReleasedKey)
{
	NSEntity* pHero = new NSEntity();
	NSRendererComponent* pHeroRendererComponent = new NSRendererComponent((*p_pMapSprites)["HERO"]);
	NSInputActionComponent* pHeroInputActionComponent = new NSInputActionComponent();
	NSMoveComponent* pHeroMoveComponent = new NSMoveComponent((*p_pMapSprites)["HERO"]);
	pHero->AddComponent(pHeroRendererComponent);
	pHero->AddComponent(pHeroInputActionComponent);
	pHero->AddComponent(pHeroMoveComponent);

	m_lEntities = std::list<NSEntity*>();
	m_lEntities.push_back(pHero);

	//not needed be cause cocos2d.x draw auto the sprite
	/* 
	NSGraphicSystem* pGraphicSystem = new NSGraphicSystem(); 
	Add(pGraphicSystem);
	*/

	NSInputActionSystem* pInputActionSystem = new NSInputActionSystem(p_listPressedKey, p_listReleasedKey); 
	Add(pInputActionSystem);

	NSMoveSystem* pMoveSystem = new NSMoveSystem(); 
	Add(pMoveSystem);
}

void NSEngine::Add(NSSystem* p_pSystem)
{
	m_vSystems.push_back(p_pSystem);
}

void NSEngine::Update(float p_fDelta)
{
	for(unsigned i = 0; i < m_vSystems.size( ); ++i)
	{
		m_vSystems[i]->Update(p_fDelta, m_lEntities);
	}

	for(unsigned i = 0; i < m_vSystems.size( ); ++i)
	{
		m_vSystems[i]->Clear(p_fDelta, m_lEntities);
	}
}