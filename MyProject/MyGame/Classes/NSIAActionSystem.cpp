#include "NSIAActionSystem.h"
#include "NSIAActionComponent.h"
#include<iostream>

NSIAActionSystem::NSIAActionSystem()
{

}

void NSIAActionSystem::Update(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{
		NSIAActionComponent* pIAActionComponent = (NSIAActionComponent*)(*itr)->GetComponent("IA_ACTION");
		if (pIAActionComponent != NULL) 
		{
			int nRandomInt = std::rand()%5;
			if (nRandomInt == 1) 
			{
				pIAActionComponent->SetCurrentAction("MOVE_LEFT");
			}
			else 
			if (nRandomInt == 2) 
			{
				pIAActionComponent->SetCurrentAction("MOVE_RIGHT");
			}
			else 
			if (nRandomInt == 3) 
			{
				pIAActionComponent->SetCurrentAction("MOVE_UP");
			}
			else 
			if (nRandomInt == 4) 
			{
				pIAActionComponent->SetCurrentAction("MOVE_DOWN");
			}
		}
	}
}
