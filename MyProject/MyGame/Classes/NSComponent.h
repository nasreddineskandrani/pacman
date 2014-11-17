#pragma once 
#include <string>

class NSComponent
{
public:
	struct ComponentType
	{
	  enum eType
	  {
		eSpeedDirection = 0,
		eBoundingBox = 1,
		eIAAction = 2,
		eInputAction = 3,
		eMapIndex = 4,
		eMove = 5,
		eRenderer = 6,
		eSound = 7
	  };
	};

	NSComponent() {}

	virtual ComponentType::eType GetType() = 0;

protected:
	ComponentType::eType m_eType;
};