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
	pHero->AddComponent(pRendererComponent);
	pHero->AddComponent(pMapIndexComponent);
	pHero->AddComponent(pInputActionComponent);
	pHero->AddComponent(pSpeedDirectionComponent);
	pHero->AddComponent(pBoundingBoxComponent);
	pHero->AddComponent(pHeroMoveComponent);
	return pHero;
}

NSEntity* NSEntityFactory::CreateEnemy(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH)
{
	NSEntity* pEnemy = new NSEntity();
	NSRendererComponent* pEnemyRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pEnemyInputActionComponent = new NSInputActionComponent();
	NSSpeedDirectionComponent* pEnemySpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pEnemyBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pEnemyMoveComponent = new NSMoveComponent(p_pSprite);
	//pEnemy->AddComponent(pEnemyRendererComponent);
	//pEnemy->AddComponent(pEnemyInputActionComponent);
	//pEnemy->AddComponent(pEnemySpeedDirectionComponent);
	pEnemy->AddComponent(pEnemyBoundingBoxComponent);
	//pEnemy->AddComponent(pEnemyMoveComponent);
	return pEnemy;
}

NSEntity* NSEntityFactory::CreateWall(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH)
{
	NSEntity* pEnemy = new NSEntity();
	NSRendererComponent* pEnemyRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pEnemyInputActionComponent = new NSInputActionComponent();
	NSSpeedDirectionComponent* pEnemySpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pEnemyBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pEnemyMoveComponent = new NSMoveComponent(p_pSprite);
	//pEnemy->AddComponent(pEnemyRendererComponent);
	//pEnemy->AddComponent(pEnemyInputActionComponent);
	//pEnemy->AddComponent(pEnemySpeedDirectionComponent);
	pEnemy->AddComponent(pEnemyBoundingBoxComponent);
	//pEnemy->AddComponent(pEnemyMoveComponent);
	return pEnemy;
}

NSEntity* NSEntityFactory::CreateEmpty(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH)
{
	NSEntity* pEnemy = new NSEntity();
	NSRendererComponent* pEnemyRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pEnemyInputActionComponent = new NSInputActionComponent();
	NSSpeedDirectionComponent* pEnemySpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pEnemyBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pEnemyMoveComponent = new NSMoveComponent(p_pSprite);
	//pEnemy->AddComponent(pEnemyRendererComponent);
	//pEnemy->AddComponent(pEnemyInputActionComponent);
	//pEnemy->AddComponent(pEnemySpeedDirectionComponent);
	pEnemy->AddComponent(pEnemyBoundingBoxComponent);
	//pEnemy->AddComponent(pEnemyMoveComponent);
	return pEnemy;
}

NSEntity* NSEntityFactory::CreatePill(CCSprite* p_pSprite)
{
	NSEntity* pEnemy = new NSEntity();
	NSRendererComponent* pEnemyRendererComponent = new NSRendererComponent(p_pSprite);
	NSInputActionComponent* pEnemyInputActionComponent = new NSInputActionComponent();
	NSSpeedDirectionComponent* pEnemySpeedDirectionComponent = new NSSpeedDirectionComponent();
	NSBoundingBoxComponent* pEnemyBoundingBoxComponent = new NSBoundingBoxComponent(p_pSprite);
	NSMoveComponent* pEnemyMoveComponent = new NSMoveComponent(p_pSprite);
	//pEnemy->AddComponent(pEnemyRendererComponent);
	//pEnemy->AddComponent(pEnemyInputActionComponent);
	//pEnemy->AddComponent(pEnemySpeedDirectionComponent);
	pEnemy->AddComponent(pEnemyBoundingBoxComponent);
	//pEnemy->AddComponent(pEnemyMoveComponent);
	return pEnemy;
}