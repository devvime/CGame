#include "raylib.h"
#include "renderer.h"
#include "game.h"
#include "../physic/physic.h"
#include "camera.h"

void StartGame(int width, int height, char* title) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1280, 720, "Meu Jogo 3D com raylib");
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