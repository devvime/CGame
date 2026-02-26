#include "raylib.h"
#include "../../../engine/scene/scene.h"
#include "../../../engine/entity/entity.h"

static Camera3D camera;

extern Entity Player;
extern Entity Floor;

static Entity player;
static Entity floor;

static void Init(void)
{
    camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 75.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    player = Player;
    floor = Floor;

    player.type->Init(&player);
    floor.type->Init(&floor);
}

static void Update(float deltaTime)
{
    player.type->Update(&player, deltaTime);
    floor.type->Update(&floor, deltaTime);
}

static void Draw(void)
{
    BeginMode3D(camera);

    player.type->Draw(&player);
    floor.type->Draw(&floor);

    EndMode3D();
}

static void Unload(void)
{
}

Scene GameplayScene = {
    .Init = Init,
    .Update = Update,
    .Draw = Draw,
    .Unload = Unload
};