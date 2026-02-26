#include "raylib.h"
#include "../../../engine/scene/scene.h"
#include "../../../engine/entity/entity.h"

static Camera3D camera;

extern Entity Player;
static Entity floor;

static void Init(void)
{
    camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 75.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Player.type->Init(&Player);
    OnInit(&floor);
}

static void Update(float deltaTime)
{
    Player.type->Update(&Player, deltaTime);
    OnUpdate(&floor, deltaTime);
}

static void Draw(void)
{
    BeginMode3D(camera);

    // DrawPlane((Vector3){0,0,0}, (Vector2){20,20}, LIGHTGRAY);
    Player.type->Draw(&Player);
    OnDraw(&floor);

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