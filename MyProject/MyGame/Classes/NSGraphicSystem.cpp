#include "NSGraphicSystem.h"
#include "NSRendererComponent.h"

void NSGraphicSystem::Update(float p_fDelta, std::list<NSEntity*>& p_lEntities)
{
	std::list<NSEntity*>::iterator itr;
	for (itr = p_lEntities.begin(); itr != p_lEntities.end(); ++itr) 
	{
		((NSRendererComponent*)(*itr)->GetComponent(1))->Update();
	}
}