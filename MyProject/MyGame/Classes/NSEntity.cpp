#include "NSEntity.h"

NSEntity::NSEntity()
{
}

void NSEntity::AddComponent(NSComponent* p_pComponent)
{
	m_components.push_back(p_pComponent);
}

NSComponent* NSEntity::GetComponent(int id)
{
	return m_components[id];
}