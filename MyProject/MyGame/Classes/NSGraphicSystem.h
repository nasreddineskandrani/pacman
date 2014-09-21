#pragma once 
#include "NSSystem.h"

class NSGraphicSystem : public NSSystem
{
public:
	virtual ~NSGraphicSystem( ) {}

	void Init() {}
	//void SendMessage(int p_nMessage) {}
	void Update(float p_fDelta, std::list<NSEntity*>& p_lEntities);
};