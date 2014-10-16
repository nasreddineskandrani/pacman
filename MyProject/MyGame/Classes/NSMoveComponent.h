#pragma once 
#include "NSComponent.h"
#include "GameScene.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSMoveComponent : public NSComponent
{
public:
	NSMoveComponent(CCSprite* p_pSprite);

	void Update(float p_fDelta, int p_nDirectionX, int p_nDirectionY, int p_nSpeed);

	std::string GetType();
private:
	CCSprite* m_pSprite;
};