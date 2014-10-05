#pragma once 
#include <string>

class NSComponent
{
public:
	NSComponent() {}

	virtual std::string GetType() = 0;

protected:
	std::string m_sType;
};