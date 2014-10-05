#pragma once 
#include "NSSystem.h"
#include <list>
#include "cocos2d.h"
using namespace cocos2d;

class NSMoveSystem : public NSSystem
{
public:
	NSMoveSystem();
	virtual ~NSMoveSystem( ) {}

	void Init() {}
	//void SendMessage(int p_nMessage) {}
	void Update(float p_fDelta, std::list<NSEntity*>& p_lEntities);
};