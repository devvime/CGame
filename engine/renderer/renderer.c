#include "renderer.h"
#include "camera.h"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"
#include "shader.h"
#include "shadowmap.h"
#include "scene/manager.h"

static bool shouldClose = false;

void DebugGame() {
    DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, GREEN);
    DrawText(TextFormat("Frame Time: %.4f", GetFrameTime()), 10, 35, 20, BLUE);
}

void Render(const int width, const int height, char* title) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, title);
    SetExitKey(0);
    InitAudioDevice();

    Camera3D camera = CreateCamera();
    Shader shadowShader = SetShader();
    Camera3D lightCamera = GetLightCamera();
    RenderTexture2D shadowMap = SetShadowMap();

    int lightVPLoc = GetLightVPLoc();
    int shadowMapLoc = GetShadowMapLoc();
    int textureActiveSlot = 10;

    Matrix lightView = { 0 };
    Matrix lightProj = { 0 };
    Matrix lightViewProj = { 0 };

    SetTargetFPS(60);
    
    while (!WindowShouldClose() && !shouldClose)
    {
        float deltaTime = GetFrameTime();
        Vector3 cameraPos = camera.position;
        SetShaderValue(shadowShader, shadowShader.locs[SHADER_LOC_VECTOR_VIEW], &cameraPos, SHADER_UNIFORM_VEC3);
        
        BeginTextureMode(shadowMap);
            ClearBackground(WHITE);
            BeginMode3D(lightCamera);
                lightView = rlGetMatrixModelview();
                lightProj = rlGetMatrixProjection();
                DrawScene3D(deltaTime);
            EndMode3D();
        EndTextureMode();

        lightViewProj = MatrixMultiply(lightView, lightProj);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DebugGame();

            UpdateScene(deltaTime);
            DrawScene2D(deltaTime);

            SetShaderValueMatrix(shadowShader, lightVPLoc, lightViewProj);
            rlEnableShader(shadowShader.id);

            rlActiveTextureSlot(textureActiveSlot);
            rlEnableTexture(shadowMap.depth.id);
            rlSetUniform(shadowMapLoc, &textureActiveSlot, SHADER_UNIFORM_INT, 1);

            BeginMode3D(camera);
                DrawScene3D(deltaTime);
            EndMode3D();

        EndDrawing();
    }

    UnloadScene();
    CloseAudioDevice();
    UnloadShader(shadowShader);
    UnloadShadowmapRenderTexture(shadowMap);

    CloseWindow();
}

void Close(void)
{
    shouldClose = true;
}