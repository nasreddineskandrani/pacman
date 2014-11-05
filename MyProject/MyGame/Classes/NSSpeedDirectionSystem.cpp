#pragma once
#include "NSSpeedDirectionSystem.h"
#include "NSSpeedDirectionComponent.h"
#include "NSInputActionComponent.h"
#include "NSIAActionComponent.h"
#include "NSMapIndexComponent.h"
#include<iostream>

NSSpeedDirectionSystem::NSSpeedDirectionSystem()
{

}

void NSSpeedDirectionSystem::Update(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{

		NSSpeedDirectionComponent* pSpeedDirectionComponent = (NSSpeedDirectionComponent*)(*itr)->GetComponent("SPEED_DIRECTION");
		NSMapIndexComponent* pMapIndexComponent = (NSMapIndexComponent*)(*itr)->GetComponent("MAP_INDEX");
		NSInputActionComponent* pInputActionComponent = (NSInputActionComponent*)(*itr)->GetComponent("INPUT_ACTION");
		NSIAActionComponent* pIAActionComponent = (NSIAActionComponent*)(*itr)->GetComponent("IA_ACTION");
		if (pSpeedDirectionComponent != NULL && pInputActionComponent != NULL) 
		{
			pSpeedDirectionComponent->Update(p_fDelta, pInputActionComponent->GetCurrentAction());
			pMapIndexComponent->Update(p_fDelta, pInputActionComponent->GetCurrentAction());
		}
		else 
		if (pSpeedDirectionComponent != NULL && pIAActionComponent != NULL)
		{
			pSpeedDirectionComponent->Update(p_fDelta, pIAActionComponent->GetCurrentAction());
		}	
	}
}