#include "NSInputActionSystem.h"
#include "NSInputActionComponent.h"
#include<iostream>

NSInputActionSystem::NSInputActionSystem(std::list<cocos2d::EventKeyboard::KeyCode>* p_listPressedKey,
					std::list<cocos2d::EventKeyboard::KeyCode>* p_listReleasedKey)
{
	m_listPressedKey = p_listPressedKey;
	m_listReleasedKey = p_listReleasedKey;
}

void NSInputActionSystem::Update(float p_fDelta, std::vector<NSEntity*>& p_lEntities)
{
	for (int i = 0; i < p_lEntities.size(); ++i) 
	{
		if (!m_listPressedKey->empty())
		{	
			std::list<cocos2d::EventKeyboard::KeyCode>::iterator itrKey;
			for (itrKey = m_listPressedKey->begin(); itrKey != m_listPressedKey->end(); ++itrKey) 
			{ 
				NSInputActionComponent* pInputActionComponent = (NSInputActionComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eInputAction);
				if (pInputActionComponent != NULL) 
				{
					if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) 
					{	
						pInputActionComponent->Push("MOVE_LEFT");
					}
					else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) 
					{	
						pInputActionComponent->Push("MOVE_RIGHT");
					}	
					else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW) 
					{	
						pInputActionComponent->Push("MOVE_UP");
					}
					else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW) 
					{	
						pInputActionComponent->Push("MOVE_DOWN");
					}	
				}
			}
		}
	}
}

void NSInputActionSystem::Clear(float p_fDelta, std::vector<NSEntity*>& p_lEntities)
{
	for (int i = 0; i < p_lEntities.size(); ++i) 
	{
		if (!m_listReleasedKey->empty())
		{	
			NSInputActionComponent* pInputActionComponent = (NSInputActionComponent*)p_lEntities[i]->GetComponent(NSComponent::ComponentType::eType::eInputAction);
			if (pInputActionComponent != NULL) 
			{
				std::list<cocos2d::EventKeyboard::KeyCode>::iterator itrKey;
				for (itrKey = m_listReleasedKey->begin(); itrKey != m_listReleasedKey->end(); ++itrKey) 
				{ 
					if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) 
					{	
						pInputActionComponent->Remove("MOVE_LEFT");
					}
					else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) 
					{	
						pInputActionComponent->Remove("MOVE_RIGHT");
					}	
					else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW) 
					{	
						pInputActionComponent->Remove("MOVE_UP");
					}
					else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW) 
					{	
						pInputActionComponent->Remove("MOVE_DOWN");
					}	
				}
			}
		}
	}
}