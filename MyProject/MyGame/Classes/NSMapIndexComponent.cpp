#include "NSMapIndexComponent.h"

NSMapIndexComponent::NSMapIndexComponent(int p_nIndexW, int p_nIndexH)
	: NSComponent()
{
	m_nIndexW = p_nIndexW;
	m_nIndexH = p_nIndexH;

	m_eType = NSComponent::ComponentType::eType::eMapIndex;
}

void NSMapIndexComponent::Update(float p_fDelta, std::string p_sAction)
{

}	

int NSMapIndexComponent::GetIndexW()
{
	return m_nIndexW;
}	

int NSMapIndexComponent::GetIndexH()
{
	return m_nIndexH;
}	

void NSMapIndexComponent::SetIndexW(int value)
{
	m_nIndexW = value;
}	

void NSMapIndexComponent::SetIndexH(int value)
{
	m_nIndexH = value;
}	

NSComponent::ComponentType::eType NSMapIndexComponent::GetType()
{
	return m_eType;
}	

