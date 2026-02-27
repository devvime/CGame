#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include <stdbool.h>
#include "../scene/scene.h"

void SetBasicShader();
Shader GetBasicShader();
void ChangeScene(Scene* newScene);
void UpdateGame(float deltaTime);
void DrawGame(float deltaTime);
void RequestClose(void);
bool ShouldCloseGame(void);
void CloseGame(void);

#endif