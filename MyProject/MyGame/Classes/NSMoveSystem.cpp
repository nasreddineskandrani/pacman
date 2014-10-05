#pragma once
#include "NSMoveSystem.h"
#include "NSMoveComponent.h"
#include "NSInputActionComponent.h"
#include<iostream>

NSMoveSystem::NSMoveSystem()
{

}

void NSMoveSystem::Update(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{
		NSMoveComponent* pMoveComponent = (NSMoveComponent*)(*itr)->GetComponent("MOVE");
		NSInputActionComponent* pInputActionComponent = (NSInputActionComponent*)(*itr)->GetComponent("INPUT_ACTION");
		if (pMoveComponent != NULL) 
		{
			pMoveComponent->Update(pInputActionComponent->GetCurrentAction());
		}
	}
}