#include "NSInputActionComponent.h"

NSInputActionComponent::NSInputActionComponent()
	: NSComponent()
{
	m_listQueuedActions = new std::list<std::string>();
	m_sType = "INPUT_ACTION";
}

std::string NSInputActionComponent::GetCurrentAction()
{
	return m_currentAction;
}

void NSInputActionComponent::SetCurrentAction(std::string p_currentAction)
{
	m_currentAction = p_currentAction;
}

void NSInputActionComponent::Push(std::string p_sAction)
{
	m_listQueuedActions->push_back(p_sAction);
	SetCurrentAction(p_sAction);
}	

void NSInputActionComponent::Remove(std::string p_sAction)
{
	m_listQueuedActions->remove(p_sAction);
	if (!m_listQueuedActions->empty())
	{
		SetCurrentAction(m_listQueuedActions->back());
	}
	else 
	{
		SetCurrentAction("");
	}
}	

std::string NSInputActionComponent::GetType()
{
	return m_sType;
}	

