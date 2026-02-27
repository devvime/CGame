#include "raylib.h"
#include "../../../engine/scene/scene.h"
#include "../../../engine/entity/entity.h"
#include "../../../engine/physic/physic.h"
#include "../../../engine/core/camera.h"
#include "../../../engine/core/game.h"

#include "raymath.h"
#define RLIGHTS_IMPLEMENTATION
#include "../../../engine/raylib/rlights.h"

extern Entity Player, Floor;
static Entity playerEntity, floorEntity;

static Shader shader;
static Light lights[MAX_LIGHTS] = { 0 };

static void Init() {
    shader = GetBasicShader();
    lights[0] = CreateLight(LIGHT_POINT, (Vector3){ -2, 5, -2 }, (Vector3){ 0, 0, 0 }, WHITE, shader);

    playerEntity = Player;
    playerEntity.type->Init(&playerEntity);
    AddEntity(&playerEntity);

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

Scene GameplayScene = {
    .Init = Init,
    .Update = Update,
    .Draw = Draw,
    .Unload = Unload
};