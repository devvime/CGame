#include "manager.h"
#include <stdio.h>

static Scene* currentScene = NULL;

void LoadScene(Scene* newScene)
{
    if (currentScene && currentScene->Unload)
        currentScene->Unload();

    currentScene = newScene;

    if (currentScene && currentScene->Init)
        currentScene->Init();
}

void UpdateScene(float deltaTime)
{
    if (currentScene && currentScene->Update)
        currentScene->Update(deltaTime);
}

void DrawScene(float deltaTime)
{
    if (currentScene && currentScene->Draw)
        currentScene->Draw(deltaTime);
}