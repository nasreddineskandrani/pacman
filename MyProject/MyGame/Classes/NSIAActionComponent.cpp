#include "NSIAActionComponent.h"

NSIAActionComponent::NSIAActionComponent()
	: NSComponent()
{
	m_listQueuedActions = new std::list<std::string>();
	m_sType = "IA_ACTION";
}

std::string NSIAActionComponent::GetCurrentAction()
{
	return m_currentAction;
}

void NSIAActionComponent::SetCurrentAction(std::string p_currentAction)
{
	m_currentAction = p_currentAction;
}

void NSIAActionComponent::Push(std::string p_sAction)
{
	/*
	m_listQueuedActions->push_back(p_sAction);
	SetCurrentAction(p_sAction);
	*/
}	

void NSIAActionComponent::Remove(std::string p_sAction)
{
	/*
	m_listQueuedActions->remove(p_sAction);
	if (!m_listQueuedActions->empty())
	{
		SetCurrentAction(m_listQueuedActions->back());
	}
	else 
	{
		SetCurrentAction("");
	}
	*/
}	

std::string NSIAActionComponent::GetType()
{
	return m_sType;
}	

