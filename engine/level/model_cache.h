#ifndef MODEL_CACHE_H
#define MODEL_CACHE_H

#include "raylib.h"

Model* GetModel(const char* path);
void ClearModelCache(void);

#endif