#pragma once 
#include "NSComponent.h"
#include "GameScene.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSMoveComponent : public NSComponent
{
public:
	NSMoveComponent(CCSprite* p_pSprite);

	void Update(float p_fDelta, std::string p_sAction);

	std::string GetType();
private:
	CCSprite* m_pSprite;
};