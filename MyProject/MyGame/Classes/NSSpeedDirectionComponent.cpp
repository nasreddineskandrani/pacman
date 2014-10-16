#include "NSSpeedDirectionComponent.h"

NSSpeedDirectionComponent::NSSpeedDirectionComponent()
	: NSComponent()
{
	m_nSpeed = +400;
	m_nDirectionX = 0;
	m_nDirectionY = 0;
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

