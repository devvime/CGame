#ifndef SHADER_H
#define SHADER_H

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

Shader SetShader();
Shader GetShader();
Camera3D GetLightCamera();
int GetLightVPLoc();
int GetShadowMapLoc();

#endif