#include "model_cache.h"
#include <string.h>
#include <stdlib.h>

#define MAX_MODELS 128

typedef struct {
    char path[256];
    Model model;
} CachedModel;

static CachedModel cache[MAX_MODELS];
static int modelCount = 0;

Model* GetModel(const char* path)
{
    for (int i = 0; i < modelCount; i++)
    {
        if (strcmp(cache[i].path, path) == 0)
        {
            return &cache[i].model;
        }
    }

    if (modelCount >= MAX_MODELS) return NULL;

    strcpy(cache[modelCount].path, path);
    cache[modelCount].model = LoadModel(path);

    modelCount++;
    return &cache[modelCount - 1].model;
}

void ClearModelCache(void)
{
    for (int i = 0; i < modelCount; i++)
    {
        UnloadModel(cache[i].model);
    }

    modelCount = 0;
}