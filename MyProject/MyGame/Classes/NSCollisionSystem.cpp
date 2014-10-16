#pragma once
#include "NSCollisionSystem.h"
#include "NSBoundingBoxComponent.h"
#include<iostream>

NSCollisionSystem::NSCollisionSystem()
{

}

void NSCollisionSystem::Update(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	//update all boundingbox components
	((NSBoundingBoxComponent*)p_lEntities.front()->GetComponent("BOUNDING_BOX"))->Update(p_fDelta);
	((NSBoundingBoxComponent*)p_lEntities.back()->GetComponent("BOUNDING_BOX"))->Update(p_fDelta);

	NSEntity* pTmpHero;

	//get hero entity
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{
		pTmpHero = *itr;
		break;
	}

	//check collision between hero and world
	itr = p_lEntities.begin();
	for (++itr; itr != p_lEntities.end(); ++itr) 
	{
		NSBoundingBoxComponent* pBoundingBoxComponent = (NSBoundingBoxComponent*)(*itr)->GetComponent("BOUNDING_BOX");
		if (pBoundingBoxComponent != NULL)
		{
			if( ((NSBoundingBoxComponent*)pTmpHero->GetComponent("BOUNDING_BOX"))->GetBoundingBox().intersectsRect(pBoundingBoxComponent->GetBoundingBox()) ) 
			{
				int collision_done = 1;
			}
		}
	}
}