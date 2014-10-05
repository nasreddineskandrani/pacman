#pragma once 
#include "NSComponent.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSRendererComponent : public NSComponent
{
public:
	NSRendererComponent(CCSprite* p_pSprite);

	void Update();

private:
	CCSprite* m_pSprite;
};