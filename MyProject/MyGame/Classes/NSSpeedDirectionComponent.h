#pragma once 
#include "NSComponent.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSSpeedDirectionComponent : public NSComponent
{
public:
	NSSpeedDirectionComponent();

	void Update(float p_fDelta, std::string p_sAction);

	NSComponent::ComponentType::eType GetType();

	int GetSpeed();
	int GetDirectionX();
	int GetDirectionY();
	void SetDirectionX(int value);
	void SetDirectionY(int value);
	int GetCachedDirectionX();
	int GetCachedDirectionY();
	void SetCachedDirectionX(int);
	void SetCachedDirectionY(int);

private:
	int m_nSpeed;
	int m_nDirectionX;
	int m_nDirectionY;
	int m_nCachedDirectionX;
	int m_nCachedDirectionY;
};