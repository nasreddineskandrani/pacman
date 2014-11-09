#include "NSIAActionSystem.h"
#include "NSIAActionComponent.h"
#include<iostream>

NSIAActionSystem::NSIAActionSystem()
{

}

void NSIAActionSystem::Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities)
{
	for (int i = 0; i < p_lEntities.size(); ++i) 
	{
		NSIAActionComponent* pIAActionComponent = (NSIAActionComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eIAAction);
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
