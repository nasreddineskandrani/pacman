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

void NSSpeedDirectionSystem::Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities)
{
	NSSpeedDirectionComponent* pSpeedDirectionComponent;
	NSMapIndexComponent* pMapIndexComponent;
	NSInputActionComponent* pInputActionComponent;
	NSIAActionComponent* pIAActionComponent;
	for (int i = 0; i < p_lEntities.size(); ++i) 
	{
		pSpeedDirectionComponent = (NSSpeedDirectionComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eSpeedDirection);
		pMapIndexComponent = (NSMapIndexComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eMapIndex);
		pInputActionComponent = (NSInputActionComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eInputAction);
		pIAActionComponent = (NSIAActionComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eIAAction);
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