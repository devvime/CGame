#include "game.h"
#include <stdio.h>
#include "raylib.h"
#include "../level/model_cache.h"

static bool shouldClose = false;
static Scene* currentScene = NULL;

static Shader BasicShader;
static int lightDirLoc;
static Vector3 lightDir = { -1.0f, -1.0f, -0.5f };

void SetBasicShader()
{
    BasicShader = LoadShader(
        "engine/shaders/basic.vs",
        "engine/shaders/basic.fs"
    );
    BasicShader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(BasicShader, "viewPos");
    int ambientLoc = GetShaderLocation(BasicShader, "ambient");
    SetShaderValue(BasicShader, ambientLoc, (float[4]){ 0.1f, 0.1f, 0.1f, 1.0f }, SHADER_UNIFORM_VEC4);
}

Shader GetBasicShader() {
    return BasicShader;
}

void ChangeScene(Scene* newScene)
{
    if (currentScene && currentScene->Unload)
        currentScene->Unload();

    currentScene = newScene;

    if (currentScene && currentScene->Init)
        currentScene->Init();
}

void UpdateGame(float deltaTime)
{
    if (currentScene && currentScene->Update)
        currentScene->Update(deltaTime);
}

void DrawGame(float deltaTime)
{
    if (currentScene && currentScene->Draw3D)
        currentScene->Draw3D(deltaTime);
}

void RequestClose(void)
{
    shouldClose = true;
}

bool ShouldCloseGame(void)
{
    return shouldClose;
}

void CloseGame(void)
{
    UnloadShader(BasicShader);
    ClearModelCache();
    CloseAudioDevice();
    CloseWindow();
}