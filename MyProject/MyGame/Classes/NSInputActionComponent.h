#pragma once 
#include "NSComponent.h"
#include <string>
#include <list>

class NSInputActionComponent : public NSComponent
{
public:
	NSInputActionComponent();

	void SetCurrentAction(std::string);
	std::string GetCurrentAction();

	void Push(std::string p_sAction);
	void Remove(std::string p_sAction);

	NSComponent::ComponentType::eType GetType();
private:
	std::string m_currentAction;
	std::list<std::string>* m_listQueuedActions; 
};