#include "raylib.h"
#include "../../../engine/core/game.h"
#include "../../../engine/scene/scene.h"
#include "../../../engine/entity/entity.h"
#include "../../../engine/physic/physic.h"

static Camera3D camera;
extern Entity Player, Floor;
static Entity player, floor;

static void Init() {
    camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 75.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Shader shader = SetBasicShader();

    player = Player;
    floor = Floor;

    for (int i = 0; i < player.model.materialCount; i++) {
        player.model.materials[i].shader = shader;
    }
    for (int i = 0; i < floor.model.materialCount; i++) {
        floor.model.materials[i].shader = shader;
    }

    player.type->Init(&player);
    floor.type->Init(&floor);

    AddEntity(&player);
    AddEntity(&floor);
}

static void Update(float deltaTime) {
    //
}

static void Draw(float deltaTime) {
    BeginMode3D(camera);

    Step(deltaTime);

    EndMode3D();
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