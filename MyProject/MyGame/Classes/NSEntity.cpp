#include "NSEntity.h"

NSEntity::NSEntity()
{
}

void NSEntity::AddComponent(NSComponent* p_pComponent)
{
	m_mapComponents[p_pComponent->GetType()] = p_pComponent;
}

NSComponent* NSEntity::GetComponent(std::string p_sId)
{
	return m_mapComponents[p_sId];
}