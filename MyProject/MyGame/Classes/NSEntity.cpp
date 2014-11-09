#include "NSEntity.h"

NSEntity::NSEntity()
{
}

void NSEntity::AddComponent(NSComponent* p_pComponent)
{
	m_vecComponents.push_back(p_pComponent);
}

NSComponent* NSEntity::GetComponent(NSComponent::ComponentType::eType p_sId)
{
	return m_vecComponents[p_sId];
}