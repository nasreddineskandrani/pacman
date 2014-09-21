#pragma once
#include <list>
#include "NSEntity.h"

class NSSystem
{
public:
	virtual ~NSSystem( ) {}

	virtual void Init() = 0;
	//virtual void SendMessage(int p_nMessage) = 0;
	virtual void Update(float p_fDelta, std::list<NSEntity*>& objects) = 0;
};