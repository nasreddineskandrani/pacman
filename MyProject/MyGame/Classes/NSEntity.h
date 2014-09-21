#pragma once 
#include "./NSComponent.h"
#include <vector>

class NSEntity
{
public:
  NSComponent* GetComponent(int id);
  void AddComponent(NSComponent* comp);
  void RemoveComponent(NSComponent* comp);
  bool HasComponent(int id);
 
private:
  std::vector<NSComponent *> m_components;
};