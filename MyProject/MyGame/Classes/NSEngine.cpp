#include "NSEngine.h"
#include "NSGraphicSystem.h"
#include "NSRendererComponent.h"
#include "NSEngine.h"

NSEngine::NSEngine(GameScene* gc)
{
	std::string sPathHero = "sprites/hero/pacman.png";
	NSRendererComponent* pHeroRendererComponent = new NSRendererComponent(sPathHero, gc);
	m_lEntities = std::list<NSEntity*>();
	NSEntity* pHero = new NSEntity();
	pHero->AddComponent(pHeroRendererComponent);

	NSGraphicSystem* pGraphicSystem = new NSGraphicSystem(); 
	Add(pGraphicSystem);
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
}