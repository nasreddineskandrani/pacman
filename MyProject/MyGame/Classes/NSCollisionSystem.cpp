#pragma once
#include "NSCollisionSystem.h"
#include "NSBoundingBoxComponent.h"
#include "NSSpeedDirectionComponent.h"
#include "NSMapIndexComponent.h"

#include<iostream>

NSCollisionSystem::NSCollisionSystem()
{

}

/* collision by bounding box
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
*/

/* collision by index */
void NSCollisionSystem::Update(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{
		NSSpeedDirectionComponent* pSpeedDirectionComponent = (NSSpeedDirectionComponent*)(*itr)->GetComponent("SPEED_DIRECTION");
		NSMoveComponent* pMoveComponent = (NSMoveComponent*)(*itr)->GetComponent("MOVE");
		NSMapIndexComponent* pMapIndexComponent = (NSMapIndexComponent*)(*itr)->GetComponent("MAP_INDEX");
		if (pSpeedDirectionComponent != NULL && pMoveComponent != NULL && pMapIndexComponent != NULL) 
		{
			//pMoveComponent->Update(p_fDelta, pSpeedDirectionComponent->GetDirectionX(), pSpeedDirectionComponent->GetDirectionY(), pSpeedDirectionComponent->GetSpeed(), nWantedIndexW, nWantedIndexH);
			
			int nSpeed = pSpeedDirectionComponent->GetSpeed();

			//use cache for direction if present
			int nDirectionX = pSpeedDirectionComponent->GetDirectionX();
			int nDirectionY = pSpeedDirectionComponent->GetDirectionY();
			int nCachedDirectionX = pSpeedDirectionComponent->GetCachedDirectionX();
			int nCachedDirectionY = pSpeedDirectionComponent->GetCachedDirectionY();
			if (nCachedDirectionX != 22 && nCachedDirectionY != 22)
			{
				nDirectionX = nCachedDirectionX;
				nDirectionY = nCachedDirectionY;
			}

			//wanted new position at new index element in map
			int nWantedIndexW = nDirectionX + pMapIndexComponent->GetIndexW();
			int nWantedIndexH = nDirectionY + pMapIndexComponent->GetIndexH();
			
			std::list<NSEntity*>::iterator itrSearchCollision;
			for (itrSearchCollision = p_lEntities.begin(); itrSearchCollision != p_lEntities.end(); ++itrSearchCollision) 
			{
				NSMapIndexComponent* pMapIndexComponent = (NSMapIndexComponent*)(*itrSearchCollision)->GetComponent("MAP_INDEX");
				if (pMapIndexComponent->GetIndexW() == nWantedIndexW && pMapIndexComponent->GetIndexH() == nWantedIndexH)
				{
					if ((*itrSearchCollision)->GetTypeName() == "WALL")
					{
						pSpeedDirectionComponent->SetCachedDirectionX(22);
						pSpeedDirectionComponent->SetCachedDirectionY(22);
						pSpeedDirectionComponent->SetDirectionX(0);
						pSpeedDirectionComponent->SetDirectionY(0);
					}
				}
			}
		}
	}
}