#pragma once 
#include "NSComponent.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSSoundComponent : public NSComponent
{
public:
	NSSoundComponent();

	void Update();

	ComponentType::eType GetType();
	
	void PlayCurrentSound();

	inline std::string GetCurrentSound() { return m_sCurrentSound;}
	inline void SetCurrentSound(const std::string& p_sCurrentSound) {m_sCurrentSound = p_sCurrentSound;}
private:
	std::string m_sCurrentSound;
};