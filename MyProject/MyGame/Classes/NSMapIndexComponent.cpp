#include "NSMapIndexComponent.h"

NSMapIndexComponent::NSMapIndexComponent(int p_nIndexW, int p_nIndexH)
	: NSComponent()
{
	m_nIndexW = p_nIndexW;
	m_nIndexH = p_nIndexH;

	m_sType = "MAP_INDEX";
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

std::string NSMapIndexComponent::GetType()
{
	return m_sType;
}	

