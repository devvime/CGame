#ifndef ENTITY_MANAGER_h
#define ENTITY_MANAGER_h

#include "entity.h"

void InitEntities();
void SpawnEntity(Entity* entity);
void UpdateEntities(float dt);
void DrawEntities();
void ResetEntities();

#endif
