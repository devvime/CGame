#include "../../../engine/entity/entity.h"
#include "../../../engine/physic/physic.h"

void OnInit(Entity* floor)
{
    floor->position = (Vector3){0, 0, 0};
    floor->size = (Vector3){1, 1, 1};
    floor->speed = 0;
    floor->gravity = 0;
}

void OnUpdate(Entity* floor, float deltaTime)
{
    BoundingBox entityBox = GetEntityBoundingBox(floor);
    ApplyGravity(floor, &entityBox, 0, deltaTime);
}

void OnDraw(Entity* floor)
{
    DrawPlane(floor->position, (Vector2){20,20}, LIGHTGRAY);
}