#include "raylib.h"
#include "../../../engine/scene/scene.h"
#include "../../../engine/entity/entity.h"
#include "../../../engine/physic/physic.h"

extern Entity Floor;
static Entity floorEntity;

static void Init() {
    floorEntity = Floor;
    floorEntity.type->Init(&floorEntity);
    AddEntity(&floorEntity);
}

static void Update(float deltaTime) {
    //
}

static void Draw(float deltaTime) {
    //
}

static void Unload(void) {
    //
}

Scene TestScene = {
    .Init = Init,
    .Update = Update,
    .Draw = Draw,
    .Unload = Unload
};