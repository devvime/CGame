#include "raylib.h"
#include "engine/core/game.h"
#include "engine/level/model_cache.h"

extern Scene GameplayScene;

int main(void)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1280, 720, "Meu Jogo 3D com raylib");
    SetExitKey(0);
    SetTargetFPS(60);
    InitAudioDevice();

    ChangeScene(&GameplayScene);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        UpdateGame(deltaTime);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawGame();

        EndDrawing();
    }

    ClearModelCache();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}