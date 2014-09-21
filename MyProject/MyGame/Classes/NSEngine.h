#ifndef __NS_ENGINE_H__
#define __NS_ENGINE_H__

#include <vector>
#include <list>
#include "NSSystem.h"

//http://stackoverflow.com/questions/7665912/double-include-solution
class GameScene; 

class NSEngine
{
public:
	NSEngine(GameScene* gc);
	void Add(NSSystem *p_pSystem);
	void Update(float p_fDelta);
 
private:
	std::vector<NSSystem*> m_vSystems;
	std::list<NSEntity*> m_lEntities; 
};

#endif // __NS_ENGINE_H__