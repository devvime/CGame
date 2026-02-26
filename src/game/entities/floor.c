#include "../../../engine/entity/entity.h"

void FloorInit(Entity* floor) {
    floor->position = (Vector3){0, 0, 0};
    floor->size = (Vector3){20, 0.1f, 20};
    floor->speed = 0;
    floor->gravity = 0;
    floor->kind = ENTITY_STATIC;
}

void FloorUpdate(Entity* floor, float deltaTime) {
    //
}

void FloorDraw(Entity* floor) {
    DrawPlane(floor->position, (Vector2){20,20}, LIGHTGRAY);
}

void FloorUnload(Entity* floor) {
    //
}

EntityType FloorType = {
    .Init = FloorInit,
    .Update = FloorUpdate,
    .Draw = FloorDraw,
    .Unload = FloorUnload
};

Entity Floor = {
    .type = &FloorType
};