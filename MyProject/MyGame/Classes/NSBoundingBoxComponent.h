#pragma once 
#include "NSComponent.h"
#include "GameScene.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSBoundingBoxComponent : public NSComponent
{
public:
	NSBoundingBoxComponent(CCSprite* p_pSprite);

	void Update(float p_fDelta);

	std::string GetType();

	CCRect GetBoundingBox();
private:
	CCSprite* m_pSprite;
	CCRect m_pBoundingBox;
};