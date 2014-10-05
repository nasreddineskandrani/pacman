#pragma once 
#include "./NSComponent.h"
#include <vector>

#include "cocos2d.h"
using namespace cocos2d;

class NSEntity
{
public:
	NSEntity();
	NSComponent* GetComponent(int id);
	void AddComponent(NSComponent* comp);
	void RemoveComponent(NSComponent* comp);
	bool HasComponent(int id);
 
private:
  std::vector<NSComponent *> m_components;
};