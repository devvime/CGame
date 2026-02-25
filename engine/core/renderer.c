#include "raylib.h"
#include "renderer.h"
#include "game.h"
#include "../level/model_cache.h"

void StartGame(int width, int height, char* title) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1280, 720, "Meu Jogo 3D com raylib");
    SetExitKey(0);
    SetTargetFPS(60);
    InitAudioDevice();

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
}