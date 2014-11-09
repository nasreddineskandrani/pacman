#pragma once 
#include "NSComponent.h"
#include "GameScene.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSMapIndexComponent : public NSComponent
{
public:
	NSMapIndexComponent(int p_nIndexW, int p_nIndexH);

	void Update(float p_fDelta, std::string p_sAction);

	int GetIndexW();
	int GetIndexH();
	void SetIndexW(int value);
	void SetIndexH(int value);

	NSComponent::ComponentType::eType GetType();
private:
	int m_nIndexW, m_nIndexH;
};