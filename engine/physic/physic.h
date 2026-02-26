#ifndef PHYSIC_H
#define PHYSIC_H

#include "raylib.h"
#include "../entity/entity.h"

BoundingBox GetEntityBoundingBox(Entity* entity);

void ResolveCollisionAxis(
    Entity* entity,
    BoundingBox* worldBoxes,
    int worldCount,
    int axis
);

void ApplyGravity(
    Entity* entity,
    BoundingBox* worldBoxes,
    int worldCount,
    float dt
);

int GetStaticWorldBoxes(Entity* entities, int count, BoundingBox* outBoxes);

void UpdateWorld(Entity* entities, int count, float dt);

void AddEntity(Entity* entity);

void Step(float delta);

#endif