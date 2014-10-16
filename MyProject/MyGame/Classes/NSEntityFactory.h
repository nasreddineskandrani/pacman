#pragma once 
#include "NSEntity.h"
//components
#include "NSRendererComponent.h"
#include "NSInputActionComponent.h"
#include "NSSpeedDirectionComponent.h"
#include "NSBoundingBoxComponent.h"
#include "NSMoveComponent.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSEntityFactory
{
public:
    static NSEntity* CreateHero(CCSprite* p_pSprite);
	static NSEntity* CreateEnemy(CCSprite* p_pSprite);
};