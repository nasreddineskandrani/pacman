#pragma once 
#include "NSSystem.h"
#include <list>
#include "cocos2d.h"
using namespace cocos2d;

class NSSoundSystem : public NSSystem
{
public:
	NSSoundSystem();
	virtual ~NSSoundSystem( ) {}

	void Init() {}
	//void SendMessage(int p_nMessage) {}
	void Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities);
};