#pragma once 
#include "NSEntity.h"
//components
#include "NSRendererComponent.h"
#include "NSInputActionComponent.h"
#include "NSSpeedDirectionComponent.h"
#include "NSBoundingBoxComponent.h"
#include "NSMoveComponent.h"
#include "NSMapIndexComponent.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSEntityFactory
{
public:
    static NSEntity* CreateHero(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH);
	static NSEntity* CreateEnemy(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH);
	static NSEntity* CreateEmpty(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH);
	static NSEntity* CreateWall(CCSprite* p_pSprite, int p_nIndexW, int p_nIndexH);
	static NSEntity* CreatePill(CCSprite* p_pSprite);
};