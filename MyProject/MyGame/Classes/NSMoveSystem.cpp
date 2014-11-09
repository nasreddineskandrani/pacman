#pragma once
#include "NSMoveSystem.h"
#include "NSSpeedDirectionComponent.h"
#include "NSMoveComponent.h"
#include "NSMapIndexComponent.h"
#include<iostream>

NSMoveSystem::NSMoveSystem()
{

}

void NSMoveSystem::Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	NSSpeedDirectionComponent* pSpeedDirectionComponent;
	NSMoveComponent* pMoveComponent;
	NSMapIndexComponent* pMapIndexComponent;
	for (int i = 0; i < p_lEntities.size(); ++i) 
	{
		pSpeedDirectionComponent = (NSSpeedDirectionComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eSpeedDirection);
		pMoveComponent = (NSMoveComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eMove);
		pMapIndexComponent = (NSMapIndexComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eMapIndex);
		
		if (pSpeedDirectionComponent != NULL && pMoveComponent != NULL && pMapIndexComponent != NULL) 
		{
			
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
			int nWantedPositionW = nWantedIndexW * 40 + 40/2;
			int nWantedPositionH = nWantedIndexH * 40 + 40/2;
			
			
			if (nDirectionX == 1 || nDirectionX == -1)
			{
				if (nDirectionX > 0)
				{
					float nNextPositionW = pMoveComponent->GetSprite()->getPositionX()+nDirectionX*nSpeed*p_fDelta;
					if (nNextPositionW > nWantedPositionW)
					{
						//if same direction pressed dont clip
						if (pSpeedDirectionComponent->GetDirectionX() == 0 && pSpeedDirectionComponent->GetCachedDirectionX() == 22) 
						{
							pMapIndexComponent->SetIndexW(pMapIndexComponent->GetIndexW()+nDirectionX);
							pMoveComponent->GetSprite()->setPositionX(nWantedPositionW);
							pSpeedDirectionComponent->SetCachedDirectionX(22);
							pSpeedDirectionComponent->SetCachedDirectionY(22);
						}
						else 
						{
							pMapIndexComponent->SetIndexW(pMapIndexComponent->GetIndexW()+nDirectionX);
							pMoveComponent->GetSprite()->setPositionX(nNextPositionW);
							pSpeedDirectionComponent->SetCachedDirectionX(22);
							pSpeedDirectionComponent->SetCachedDirectionY(22);
						}
					}
					else 
					{
						pMoveComponent->GetSprite()->setPositionX(nNextPositionW);
						pSpeedDirectionComponent->SetCachedDirectionX(nDirectionX);
						pSpeedDirectionComponent->SetCachedDirectionY(nDirectionY);
					}
				}
				else 
				{
					float nNextPositionW = pMoveComponent->GetSprite()->getPositionX()+nDirectionX*nSpeed*p_fDelta;
					if (nNextPositionW < nWantedPositionW)
					{
						//if same direction pressed dont clip
						if (pSpeedDirectionComponent->GetDirectionX() == 0 && pSpeedDirectionComponent->GetCachedDirectionX() == 22) 
						{
							pMapIndexComponent->SetIndexW(pMapIndexComponent->GetIndexW()+nDirectionX);
							pMoveComponent->GetSprite()->setPositionX(nWantedPositionW);
							pSpeedDirectionComponent->SetCachedDirectionX(22);
							pSpeedDirectionComponent->SetCachedDirectionY(22);
						}
						else 
						{
							pMapIndexComponent->SetIndexW(pMapIndexComponent->GetIndexW()+nDirectionX);
							pMoveComponent->GetSprite()->setPositionX(nNextPositionW);
							pSpeedDirectionComponent->SetCachedDirectionX(22);
							pSpeedDirectionComponent->SetCachedDirectionY(22);
						}
					}
					else 
					{
						pMoveComponent->GetSprite()->setPositionX(nNextPositionW);
						pSpeedDirectionComponent->SetCachedDirectionX(nDirectionX);
						pSpeedDirectionComponent->SetCachedDirectionY(nDirectionY);
					}
				}
			}
			else
			{
				pMoveComponent->GetSprite()->setPositionX(nWantedPositionW);
			}

			if (nDirectionY == 1 || nDirectionY == -1)
			{
				if (nDirectionY > 0)
				{
					float nNextPositionH = pMoveComponent->GetSprite()->getPositionY()+nDirectionY*nSpeed*p_fDelta;
					if (nNextPositionH > nWantedPositionH)
					{
						if (pSpeedDirectionComponent->GetDirectionY() == 0 && pSpeedDirectionComponent->GetCachedDirectionY() == 22) 
						{
							pMapIndexComponent->SetIndexH(pMapIndexComponent->GetIndexH()+nDirectionY);
							pMoveComponent->GetSprite()->setPositionY(nWantedPositionH);
							pSpeedDirectionComponent->SetCachedDirectionX(22);
							pSpeedDirectionComponent->SetCachedDirectionY(22);
						}
						else 
						{
							pMapIndexComponent->SetIndexH(pMapIndexComponent->GetIndexH()+nDirectionY);
							pMoveComponent->GetSprite()->setPositionY(nNextPositionH);
							pSpeedDirectionComponent->SetCachedDirectionX(22);
							pSpeedDirectionComponent->SetCachedDirectionY(22);
						}
					}
					else 
					{
						pMoveComponent->GetSprite()->setPositionY(nNextPositionH);
						pSpeedDirectionComponent->SetCachedDirectionX(nDirectionX);
						pSpeedDirectionComponent->SetCachedDirectionY(nDirectionY);
					}
				}
				else 
				{
					float nNextPositionH = pMoveComponent->GetSprite()->getPositionY()+nDirectionY*nSpeed*p_fDelta;
					if (nNextPositionH < nWantedPositionH)
					{
						if (pSpeedDirectionComponent->GetDirectionY() == 0 && pSpeedDirectionComponent->GetCachedDirectionY() == 22) 
						{
							pMapIndexComponent->SetIndexH(pMapIndexComponent->GetIndexH()+nDirectionY);
							pMoveComponent->GetSprite()->setPositionY(nWantedPositionH);
							pSpeedDirectionComponent->SetCachedDirectionX(22);
							pSpeedDirectionComponent->SetCachedDirectionY(22);
						}
						else 
						{
							pMapIndexComponent->SetIndexH(pMapIndexComponent->GetIndexH()+nDirectionY);
							pMoveComponent->GetSprite()->setPositionY(nNextPositionH);
							pSpeedDirectionComponent->SetCachedDirectionX(22);
							pSpeedDirectionComponent->SetCachedDirectionY(22);
						}
					}
					else 
					{
						pMoveComponent->GetSprite()->setPositionY(nNextPositionH);
						pSpeedDirectionComponent->SetCachedDirectionX(nDirectionX);
						pSpeedDirectionComponent->SetCachedDirectionY(nDirectionY);
					}
				}
			}
			else
			{
				pMoveComponent->GetSprite()->setPositionY(nWantedPositionH);
			}
		}
	}
}