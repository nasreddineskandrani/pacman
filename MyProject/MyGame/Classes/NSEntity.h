#pragma once 
#include "./NSComponent.h"
#include <map>
#include <string>

#include "cocos2d.h"
using namespace cocos2d;

class NSEntity
{
public:
	NSEntity();

	NSComponent* GetComponent(std::string p_sId);
	bool HasComponent(std::string p_sId);
	void AddComponent(NSComponent* p_pComponent);
	void RemoveComponent(NSComponent* p_pComponent);

 
private:
  std::map<std::string,NSComponent*> m_mapComponents;
};