#include "app.h"
#include "../render/camera.h"
#include "raylib.h"

void App_Run(int width, int height, char *title) {
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(width, height, title);
  SetTargetFPS(60);
  InitAudioDevice();

  Camera camera = Camera_Create();

  while (!WindowShouldClose()) {
    Camera_Update(&camera);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    DrawGrid(20, 1);
    DrawCube((Vector3){0, 1, 0}, 2, 2, 2, RED);

    EndMode3D();

    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseAudioDevice();
  CloseWindow();
}
