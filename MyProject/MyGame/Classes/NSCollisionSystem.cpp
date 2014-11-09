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
void NSCollisionSystem::Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities)
{
	for (int i = 0; i < p_lEntities.size(); ++i) 
	{
		NSSpeedDirectionComponent* pSpeedDirectionComponent = (NSSpeedDirectionComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eSpeedDirection);
		NSMoveComponent* pMoveComponent = (NSMoveComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eMove);
		NSMapIndexComponent* pMapIndexComponent = (NSMapIndexComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eMapIndex);
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
			
			for (int j = 0; j < p_lEntities.size(); ++j) 
			{
				NSMapIndexComponent* pMapIndexComponent = (NSMapIndexComponent*)p_lEntities[j]->GetComponent(NSComponent::ComponentType::eType::eMapIndex);
				if (pMapIndexComponent->GetIndexW() == nWantedIndexW && pMapIndexComponent->GetIndexH() == nWantedIndexH)
				{
					if (p_lEntities[j]->GetTypeName() == "WALL")
					{
						pSpeedDirectionComponent->SetCachedDirectionX(22);
						pSpeedDirectionComponent->SetCachedDirectionY(22);
						pSpeedDirectionComponent->SetDirectionX(0);
						pSpeedDirectionComponent->SetDirectionY(0);
					}
					/*else 
					if ((*itrSearchCollision)->GetTypeName() == "PILL")
					{
						NSMoveComponent* pMoveComponent = (NSMoveComponent*)(*itrSearchCollision)->GetComponent("MOVE");
						pMoveComponent->GetSprite()->setVisible(false);
					}*/
				
				}
			}
		}
	}

	NSEntity* pTmpHero;

	//get hero entity
	for (int k = 0; k < p_lEntities.size(); ++k) 
	{
		if (p_lEntities[k]->GetTypeName() == "HERO")
		{
			pTmpHero = p_lEntities[k];
			break;
		}
	}

	//check collision between hero and world
	for (int l = 0; l < p_lEntities.size(); ++l) 
	{
		NSBoundingBoxComponent* pBoundingBoxComponent = (NSBoundingBoxComponent*)p_lEntities[l]->GetComponent(NSComponent::ComponentType::eType::eBoundingBox);
		if (pBoundingBoxComponent != NULL)
		{
			if (p_lEntities[l]->GetTypeName() == "PILL")
			{
				pBoundingBoxComponent->Update(p_fDelta);
				((NSBoundingBoxComponent*)pTmpHero->GetComponent(NSComponent::ComponentType::eType::eBoundingBox))->Update(p_fDelta);
				if( ((NSBoundingBoxComponent*)pTmpHero->GetComponent(NSComponent::ComponentType::eType::eBoundingBox))->GetBoundingBox().intersectsRect(pBoundingBoxComponent->GetBoundingBox()) ) 
				{
					NSMoveComponent* pMoveComponent = (NSMoveComponent*)p_lEntities[l]->GetComponent(NSComponent::ComponentType::eType::eMove);
					pMoveComponent->GetSprite()->setVisible(false);
				}
			}
		}
	}
}