#pragma once 
#include "NSSystem.h"
#include <list>
#include "cocos2d.h"
using namespace cocos2d;

class NSSpeedDirectionSystem : public NSSystem
{
public:
	NSSpeedDirectionSystem();
	virtual ~NSSpeedDirectionSystem( ) {}

	void Init() {}
	//void SendMessage(int p_nMessage) {}
	void Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities);
};