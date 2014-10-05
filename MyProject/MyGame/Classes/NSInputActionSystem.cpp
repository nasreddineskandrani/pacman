#include "NSInputActionSystem.h"
#include "NSInputActionComponent.h"
#include<iostream>

NSInputActionSystem::NSInputActionSystem(std::list<cocos2d::EventKeyboard::KeyCode>* p_listPressedKey,
					std::list<cocos2d::EventKeyboard::KeyCode>* p_listReleasedKey)
{
	m_listPressedKey = p_listPressedKey;
	m_listReleasedKey = p_listReleasedKey;
}

void NSInputActionSystem::Update(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{
		if (!m_listPressedKey->empty())
		{	
			std::list<cocos2d::EventKeyboard::KeyCode>::iterator itrKey;
			for (itrKey = m_listPressedKey->begin(); itrKey != m_listPressedKey->end(); ++itrKey) 
			{ 
				if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) 
				{	
					((NSInputActionComponent*)(*itr)->GetComponent(1))->Push("MOVE_LEFT");
				}
				else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) 
				{	
					((NSInputActionComponent*)(*itr)->GetComponent(1))->Push("MOVE_RIGHT");
				}	
				else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW) 
				{	
					((NSInputActionComponent*)(*itr)->GetComponent(1))->Push("MOVE_UP");
				}
				else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW) 
				{	
					((NSInputActionComponent*)(*itr)->GetComponent(1))->Push("MOVE_DOWN");
				}	
			}
		}
	}
}

void NSInputActionSystem::Clear(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{
		if (!m_listReleasedKey->empty())
		{	
			std::list<cocos2d::EventKeyboard::KeyCode>::iterator itrKey;
			for (itrKey = m_listReleasedKey->begin(); itrKey != m_listReleasedKey->end(); ++itrKey) 
			{ 
				if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) 
				{	
					((NSInputActionComponent*)(*itr)->GetComponent(1))->Remove("MOVE_LEFT");
				}
				else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) 
				{	
					((NSInputActionComponent*)(*itr)->GetComponent(1))->Remove("MOVE_RIGHT");
				}	
				else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW) 
				{	
					((NSInputActionComponent*)(*itr)->GetComponent(1))->Remove("MOVE_UP");
				}
				else if ((*itrKey) == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW) 
				{	
					((NSInputActionComponent*)(*itr)->GetComponent(1))->Remove("MOVE_DOWN");
				}	
			}
		}
	}
}