#pragma once 
#include "NSSystem.h"
#include <list>
#include "cocos2d.h"
using namespace cocos2d;

class NSInputActionSystem : public NSSystem
{
public:
	NSInputActionSystem(std::list<cocos2d::EventKeyboard::KeyCode>* p_listPressedKey,
					std::list<cocos2d::EventKeyboard::KeyCode>* p_listReleasedKey);
	virtual ~NSInputActionSystem( ) {}

	void Init() {}
	//void SendMessage(int p_nMessage) {}
	void Update(float p_fDelta, std::list<NSEntity*>& p_lEntities);
	void Clear(float p_fDelta, std::list<NSEntity*>& p_lEntities);

private:
	std::list<cocos2d::EventKeyboard::KeyCode>* m_listPressedKey;
	std::list<cocos2d::EventKeyboard::KeyCode>* m_listReleasedKey;
};