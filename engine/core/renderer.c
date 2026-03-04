#include "raylib.h"
#include "renderer.h"
#include "game.h"
#include "../physic/physic.h"
#include "camera.h"

void Debug() {
    DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, GREEN);
    DrawText(TextFormat("Frame Time: %.4f", GetFrameTime()), 10, 35, 20, BLUE);
}

void StartGame(int width, int height, char* title) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, title);
    SetExitKey(0);
    SetTargetFPS(60);
    InitAudioDevice();
    SetBasicShader();
    InitPhysics();

    Camera3D camera = GetCamera();
    Shader shader = GetBasicShader();

    while (!WindowShouldClose() && !ShouldCloseGame())
    {
        float deltaTime = GetFrameTime();

        UpdateGame(deltaTime);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Debug();

        BeginMode3D(camera);
        BeginShaderMode(shader);

        Step(deltaTime);

        EndShaderMode();
        EndMode3D();

        DrawGame(deltaTime);

        EndDrawing();
    }

    CloseGame();
}