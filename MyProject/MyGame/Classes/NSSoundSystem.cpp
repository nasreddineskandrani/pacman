#pragma once
#include "NSSoundSystem.h"
#include "NSSoundComponent.h"
#include<iostream>

NSSoundSystem::NSSoundSystem()
{

}

void NSSoundSystem::Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities)
{
	NSSoundComponent* pSoundComponent;
	for (int i = 0; i < p_lEntities.size(); ++i) 
	{
		pSoundComponent = (NSSoundComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eSound);
		if (pSoundComponent != NULL)
		{
			pSoundComponent->PlayCurrentSound();
		}
	}
}