#pragma once 
#include "NSComponent.h"
#include "GameScene.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSMoveComponent : public NSComponent
{
public:
	NSMoveComponent(CCSprite* p_pSprite);

	void Update(std::string p_sAction);

private:
	CCSprite* m_pSprite;
};