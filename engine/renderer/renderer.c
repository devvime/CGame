#include "renderer.h"
#include "camera.h"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"
#include "shader.h"
#include "shadowmap.h"

static bool shouldClose = false;
static void DrawScene(Model cube, Model robot);

void Render(const int width, const int height, char* title) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, title);

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


    Model cube = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    cube.materials[0].shader = shadowShader;
    Model robot = LoadModel("resources/models/robot.glb");
    for (int i = 0; i < robot.materialCount; i++) robot.materials[i].shader = shadowShader;

    int animCount = 0;
    int frameCounter = 0;
    ModelAnimation *anims = LoadModelAnimations("resources/models/robot.glb", &animCount);

    SetTargetFPS(60);
    
    while (!WindowShouldClose() && !shouldClose)
    {
        float deltaTime = GetFrameTime();
        Vector3 cameraPos = camera.position;
        SetShaderValue(shadowShader, shadowShader.locs[SHADER_LOC_VECTOR_VIEW], &cameraPos, SHADER_UNIFORM_VEC3);

        frameCounter++;
        frameCounter %= (anims[0].frameCount);
        UpdateModelAnimation(robot, anims[0], (float)frameCounter);
        
        BeginTextureMode(shadowMap);
            ClearBackground(WHITE);
            BeginMode3D(lightCamera);
                lightView = rlGetMatrixModelview();
                lightProj = rlGetMatrixProjection();
                DrawScene(cube, robot);
            EndMode3D();
        EndTextureMode();

        lightViewProj = MatrixMultiply(lightView, lightProj);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            SetShaderValueMatrix(shadowShader, lightVPLoc, lightViewProj);
            rlEnableShader(shadowShader.id);

            rlActiveTextureSlot(textureActiveSlot);
            rlEnableTexture(shadowMap.depth.id);
            rlSetUniform(shadowMapLoc, &textureActiveSlot, SHADER_UNIFORM_INT, 1);

            BeginMode3D(camera);
                DrawScene(cube, robot);
            EndMode3D();

        EndDrawing();
    }

    UnloadShader(shadowShader);
    UnloadModel(cube);
    UnloadModel(robot);
    UnloadModelAnimations(anims, animCount);
    UnloadShadowmapRenderTexture(shadowMap);

    CloseWindow();
}

static void DrawScene(Model cube, Model robot)
{
    DrawModelEx(cube, Vector3Zero(), (Vector3) { 0.0f, 1.0f, 0.0f }, 0.0f, (Vector3) { 10.0f, 1.0f, 10.0f }, BLUE);
    DrawModelEx(cube, (Vector3) { 1.5f, 1.0f, -1.5f }, (Vector3) { 0.0f, 1.0f, 0.0f }, 0.0f, Vector3One(), WHITE);
    DrawModelEx(robot, (Vector3) { 0.0f, 0.5f, 0.0f }, (Vector3) { 0.0f, 1.0f, 0.0f }, 0.0f, (Vector3) { 1.0f, 1.0f, 1.0f }, RED);
}

void Close(void)
{
    shouldClose = true;
}