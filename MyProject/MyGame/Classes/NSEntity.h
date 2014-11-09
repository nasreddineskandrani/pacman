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

	NSComponent* GetComponent(NSComponent::ComponentType::eType p_sId);
	bool HasComponent(NSComponent::ComponentType::eType p_sId);
	void AddComponent(NSComponent* p_pComponent);
	void RemoveComponent(NSComponent* p_pComponent);

	inline std::string GetTypeName() { return m_sTypeName; };
	inline void SetTypeName(const std::string& p_sTypeName) { m_sTypeName = p_sTypeName; };
 
private:
  std::vector<NSComponent*> m_vecComponents;
  std::string m_sTypeName;
};