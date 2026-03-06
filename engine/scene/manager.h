#ifndef MANAGER_H
#define MANAGER_H

#include "../scene/scene.h"

void LoadScene(Scene* newScene);
void UpdateScene(float deltaTime);
void DrawScene2D(float deltaTime);
void DrawScene3D(float deltaTime);
void UnloadScene(void);

#endif