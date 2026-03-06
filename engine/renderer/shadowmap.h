#ifndef SHADOWMAP_H
#define SHADOWMAP_H
#define SHADOWMAP_RESOLUTION 1024

#include "raylib.h"
#include "rlgl.h"

RenderTexture2D LoadShadowmapRenderTexture(int width, int height);
void UnloadShadowmapRenderTexture(RenderTexture2D target);
RenderTexture2D SetShadowMap();
RenderTexture2D GetShadowMap();

#endif