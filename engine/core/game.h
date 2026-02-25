#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "../scene/scene.h"

void ChangeScene(Scene* newScene);
void UpdateGame(float deltaTime);
void DrawGame(void);
void RequestClose(void);
bool ShouldCloseGame(void);
void CloseGame(void);

#endif