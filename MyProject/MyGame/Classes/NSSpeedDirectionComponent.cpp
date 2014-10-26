#include "NSSpeedDirectionComponent.h"

NSSpeedDirectionComponent::NSSpeedDirectionComponent()
	: NSComponent()
{
	//m_nSpeed = +180+20;
	m_nSpeed = +150;
	m_nDirectionX = 0;
	m_nDirectionY = 0;
	m_nCachedDirectionX = 22;
	m_nCachedDirectionY = 22;
	m_sType = "SPEED_DIRECTION";
}

void NSSpeedDirectionComponent::Update(float p_fDelta, std::string p_sAction)
{
	if (p_sAction == "MOVE_LEFT")
	{
		m_nDirectionX = -1;
		m_nDirectionY = 0;
	}
	else if (p_sAction == "MOVE_RIGHT") 
	{
		m_nDirectionX = +1;
		m_nDirectionY = 0;
	}
	else if (p_sAction == "MOVE_DOWN") 
	{
		m_nDirectionX = 0;
		m_nDirectionY = -1;
	}
	else if (p_sAction == "MOVE_UP") 
	{
		m_nDirectionX = 0;
		m_nDirectionY = +1;
	}
	else 
	{
		m_nDirectionX = 0;
		m_nDirectionY = 0;
	}	
}	

std::string NSSpeedDirectionComponent::GetType()
{
	return m_sType;
}	

int NSSpeedDirectionComponent::GetSpeed()
{
	return m_nSpeed;
}	

int NSSpeedDirectionComponent::GetDirectionX()
{
	return m_nDirectionX;
}	

int NSSpeedDirectionComponent::GetDirectionY()
{
	return m_nDirectionY;
}	

void NSSpeedDirectionComponent::SetDirectionX(int value)
{
	m_nDirectionX = value;
}	

void NSSpeedDirectionComponent::SetDirectionY(int value)
{
	m_nDirectionY = value;
}	

int NSSpeedDirectionComponent::GetCachedDirectionX()
{
	return m_nCachedDirectionX;
}	

int NSSpeedDirectionComponent::GetCachedDirectionY()
{
	return m_nCachedDirectionY;
}	

void NSSpeedDirectionComponent::SetCachedDirectionX(int value)
{
	m_nCachedDirectionX = value;
}	

void NSSpeedDirectionComponent::SetCachedDirectionY(int value)
{
	m_nCachedDirectionY = value;
}	