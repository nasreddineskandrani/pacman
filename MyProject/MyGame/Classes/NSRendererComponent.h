#pragma once 
#include "NSComponent.h"
#include "GameScene.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSRendererComponent : public NSComponent
{
public:
	NSRendererComponent(const std::string& p_sPath, GameScene* gc);

	void Update();

private:
	CCSprite* m_pSprite;
};