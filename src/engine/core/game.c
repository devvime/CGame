#include "game.h"
#include <stdio.h>

static Scene* currentScene = NULL;

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

void DrawGame(void)
{
    if (currentScene && currentScene->Draw)
        currentScene->Draw();
}