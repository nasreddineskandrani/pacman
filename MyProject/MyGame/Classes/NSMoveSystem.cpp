#pragma once
#include "NSMoveSystem.h"
#include "NSSpeedDirectionComponent.h"
#include "NSMoveComponent.h"
#include<iostream>

NSMoveSystem::NSMoveSystem()
{

}

void NSMoveSystem::Update(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{
		NSSpeedDirectionComponent* pSpeedDirectionComponent = (NSSpeedDirectionComponent*)(*itr)->GetComponent("SPEED_DIRECTION");
		NSMoveComponent* pMoveComponent = (NSMoveComponent*)(*itr)->GetComponent("MOVE");
		if (pSpeedDirectionComponent != NULL && pMoveComponent != NULL) 
		{
			pMoveComponent->Update(p_fDelta, pSpeedDirectionComponent->GetDirectionX(), pSpeedDirectionComponent->GetDirectionY(), pSpeedDirectionComponent->GetSpeed());
		}
	}
}