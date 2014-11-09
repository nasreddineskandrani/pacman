#pragma once 
#include "NSComponent.h"
#include "GameScene.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSMoveComponent : public NSComponent
{
public:
	NSMoveComponent(CCSprite* p_pSprite);

	void Update(float p_fDelta, int p_nDirectionX, int p_nDirectionY, int p_nSpeed, int p_nWantedIndexW, int p_nWantedIndexH);

	NSComponent::ComponentType::eType GetType();
	CCSprite* GetSprite();
private:
	CCSprite* m_pSprite;
	int p_nCachedDirectionX;
	int p_nCachedDirectionY;
};