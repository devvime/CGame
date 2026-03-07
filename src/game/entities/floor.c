#include "entity/entity.h"

static Entity* floor;

void FloorInit() {
    floor->position = (Vector3){0, 0, 0};
    floor->size = (Vector3){10, 0.1f, 10};
    floor->speed = 0;
    floor->gravity = 0;
    floor->kind = ENTITY_STATIC;
}

void FloorUpdate(float deltaTime) {
    //
}

void FloorDraw() {
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