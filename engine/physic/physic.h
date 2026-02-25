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

#endif