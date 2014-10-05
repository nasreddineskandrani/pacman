#ifndef __NS_ENGINE_H__
#define __NS_ENGINE_H__

#include <vector>
#include <list>
#include <map>
#include "NSSystem.h"

#include "cocos2d.h"
using namespace cocos2d;

class NSEngine
{
public:
	NSEngine(std::map<std::string,CCSprite*>* p_pMapSprites,
			std::list<cocos2d::EventKeyboard::KeyCode>* p_listPressedKey, 
			std::list<cocos2d::EventKeyboard::KeyCode>* p_listReleasedKey);
	void Add(NSSystem *p_pSystem);
	void Update(float p_fDelta);
 
private:
	std::vector<NSSystem*> m_vSystems;
	std::list<NSEntity*> m_lEntities; 
};

#endif // __NS_ENGINE_H__