#pragma once 
#include "NSSystem.h"
#include <list>
#include "cocos2d.h"
using namespace cocos2d;

class NSCollisionSystem : public NSSystem
{
public:
	NSCollisionSystem();
	virtual ~NSCollisionSystem( ) {}

	void Init() {}
	//void SendMessage(int p_nMessage) {}
	void Update(float p_fDelta, std::list<NSEntity*>& p_lEntities);
};