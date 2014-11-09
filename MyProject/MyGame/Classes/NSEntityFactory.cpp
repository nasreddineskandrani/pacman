#include "NSEntityFactory.h"

NSEntity* NSEntityFactory::CreateHero(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH)
{
	NSEntity* pHero = new NSEntity();
	NSMapIndexComponent* pMapIndexComponent = new NSMapIndexComponent(p_nIndexW, p_nIndexH);
	NSRendererComponent* pRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pInputActionComponent = new NSInputActionComponent();
	NSSpeedDirectionComponent* pSpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pBoundingBoxComponent= new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pHeroMoveComponent = new NSMoveComponent(p_pSprite);
	pHero->AddComponent(pSpeedDirectionComponent);
	pHero->AddComponent(pBoundingBoxComponent);
	pHero->AddComponent(NULL);
	pHero->AddComponent(pInputActionComponent);
	pHero->AddComponent(pMapIndexComponent);
	pHero->AddComponent(pHeroMoveComponent);
	pHero->AddComponent(NULL);
	pHero->SetTypeName("HERO");
	return pHero;
}

NSEntity* NSEntityFactory::CreateEnemy(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH)
{
	NSEntity* pEnemy = new NSEntity();
	NSMapIndexComponent* pMapIndexComponent = new NSMapIndexComponent(p_nIndexW, p_nIndexH);
	NSRendererComponent* pEnemyRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pEnemyInputActionComponent = new NSInputActionComponent();
	NSIAActionComponent* pEnemyIAActionComponent = new NSIAActionComponent();
	NSSpeedDirectionComponent* pEnemySpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pEnemyBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pEnemyMoveComponent = new NSMoveComponent(p_pSprite);
	pEnemy->AddComponent(pEnemySpeedDirectionComponent);
	pEnemy->AddComponent(pEnemyBoundingBoxComponent);
	pEnemy->AddComponent(pEnemyIAActionComponent);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(pMapIndexComponent);
	pEnemy->AddComponent(pEnemyMoveComponent);
	pEnemy->AddComponent(NULL);
	pEnemy->SetTypeName("GHOST");
	return pEnemy;
}

NSEntity* NSEntityFactory::CreateWall(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH)
{
	NSEntity* pEnemy = new NSEntity();
	NSMapIndexComponent* pMapIndexComponent = new NSMapIndexComponent(p_nIndexW, p_nIndexH);
	NSRendererComponent* pEnemyRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pEnemyInputActionComponent = new NSInputActionComponent();
	NSIAActionComponent* pEnemyIAActionComponent = new NSIAActionComponent();
	NSSpeedDirectionComponent* pEnemySpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pEnemyBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pEnemyMoveComponent = new NSMoveComponent(p_pSprite);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(pEnemyBoundingBoxComponent);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(pMapIndexComponent);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(NULL);
	pEnemy->SetTypeName("WALL");
	return pEnemy;
}

NSEntity* NSEntityFactory::CreateEmpty(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH)
{
	NSEntity* pEnemy = new NSEntity();
	NSMapIndexComponent* pMapIndexComponent = new NSMapIndexComponent(p_nIndexW, p_nIndexH);
	NSRendererComponent* pEnemyRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pEnemyInputActionComponent = new NSInputActionComponent();
	NSIAActionComponent* pEnemyIAActionComponent = new NSIAActionComponent();
	NSSpeedDirectionComponent* pEnemySpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pEnemyBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pEnemyMoveComponent = new NSMoveComponent(p_pSprite);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(pEnemyBoundingBoxComponent);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(pMapIndexComponent);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(NULL);
	pEnemy->SetTypeName("EMPTY");
	return pEnemy;
}

NSEntity* NSEntityFactory::CreatePill(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH)
{
	NSEntity* pEnemy = new NSEntity();
	NSMapIndexComponent* pMapIndexComponent = new NSMapIndexComponent(p_nIndexW, p_nIndexH);
	NSRendererComponent* pEnemyRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pEnemyInputActionComponent = new NSInputActionComponent();
	NSIAActionComponent* pEnemyIAActionComponent = new NSIAActionComponent();
	NSSpeedDirectionComponent* pEnemySpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pEnemyBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pEnemyMoveComponent = new NSMoveComponent(p_pSprite);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(pEnemyBoundingBoxComponent);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(NULL);
	pEnemy->AddComponent(pMapIndexComponent);
	pEnemy->AddComponent(pEnemyMoveComponent);
	pEnemy->AddComponent(NULL);
	pEnemy->SetTypeName("PILL");
	return pEnemy;
}