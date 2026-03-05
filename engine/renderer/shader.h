#ifndef SHADER_H
#define SHADER_H
#define SHADOWMAP_RESOLUTION 1024

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

Shader SetShader();
Shader GetShader();
Camera3D GetLightCamera();
int GetLightVPLoc();
int GetShadowMapLoc();

#endif