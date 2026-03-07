#include <stdio.h>
#include "manager.h"
#include "entity/entity_manager.h"

static Scene* currentScene = NULL;

void LoadScene(Scene* newScene)
{
    if (currentScene && currentScene->Unload)
        currentScene->Unload();
        ResetEntities();

    currentScene = newScene;

    if (currentScene && currentScene->Init)
        currentScene->Init();
        InitEntities();
}

void UpdateScene(float deltaTime)
{
    if (currentScene && currentScene->Update)
        currentScene->Update(deltaTime);
        UpdateEntities(deltaTime);
}

void DrawScene2D(float deltaTime)
{
    if (currentScene && currentScene->Draw2D)
        currentScene->Draw2D(deltaTime);
}

void DrawScene3D(float deltaTime)
{
    if (currentScene && currentScene->Draw3D)
        currentScene->Draw3D(deltaTime);
        DrawEntities();
}

void UnloadScene(void) {
    if (currentScene && currentScene->Unload)
        currentScene->Unload();
        ResetEntities();
}