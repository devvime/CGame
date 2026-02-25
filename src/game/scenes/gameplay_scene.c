#include "raylib.h"
#include "../../../engine/scene/scene.h"
#include "../entities/player.h"

static Player player;
static Camera3D camera;

static void Init(void)
{
    Player_Init(&player);

    camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

static void Update(float deltaTime)
{
    Player_Update(&player, deltaTime);
}

static void Draw(void)
{
    BeginMode3D(camera);

    DrawPlane((Vector3){0,0,0}, (Vector2){20,20}, LIGHTGRAY);
    Player_Draw(&player);

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