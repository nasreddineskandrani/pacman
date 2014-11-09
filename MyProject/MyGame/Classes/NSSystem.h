#pragma once
#include <vector>
#include "NSEntity.h"

class NSSystem
{
public:
	virtual ~NSSystem( ) {}

	virtual void Init() = 0;
	//virtual void SendMessage(int p_nMessage) = 0;

	virtual void Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities) = 0;

	virtual void Clear(float p_fDelta, std::vector<NSEntity*>& p_lEntities) {}
};