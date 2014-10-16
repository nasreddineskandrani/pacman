#include "NSEntityFactory.h"

NSEntity* NSEntityFactory::CreateHero(CCSprite* p_pSprite)
{
	NSEntity* pHero = new NSEntity();
	NSRendererComponent* pHeroRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pHeroInputActionComponent = new NSInputActionComponent();
	NSSpeedDirectionComponent* pHeroSpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pHeroBoundingBoxComponent= new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pHeroMoveComponent = new NSMoveComponent(p_pSprite);
	pHero->AddComponent(pHeroRendererComponent);
	pHero->AddComponent(pHeroInputActionComponent);
	pHero->AddComponent(pHeroSpeedDirectionComponent);
	pHero->AddComponent(pHeroBoundingBoxComponent);
	pHero->AddComponent(pHeroMoveComponent);
	return pHero;
}

NSEntity* NSEntityFactory::CreateEnemy(CCSprite* p_pSprite)
{
	NSEntity* pHero = new NSEntity();
	NSRendererComponent* pHeroRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pHeroInputActionComponent = new NSInputActionComponent();
	NSSpeedDirectionComponent* pHeroSpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pHeroBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pHeroMoveComponent = new NSMoveComponent(p_pSprite);
	pHero->AddComponent(pHeroRendererComponent);
	pHero->AddComponent(pHeroBoundingBoxComponent);
	//pHero->AddComponent(pHeroInputActionComponent);
	//pHero->AddComponent(pHeroMoveComponent);
	return pHero;
}