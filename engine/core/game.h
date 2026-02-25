#ifndef GAME_H
#define GAME_H

#include "../scene/scene.h"

void ChangeScene(Scene* newScene);
void UpdateGame(float deltaTime);
void DrawGame(void);

#endif