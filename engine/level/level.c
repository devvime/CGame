#include "level.h"
#include "model_cache.h"
#include "../cJSON/cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static BoundingBox GenerateWorldBounds(Model* model, Vector3 position, Vector3 scale)
{
    BoundingBox box = GetModelBoundingBox(*model);

    // Aplica escala e posição
    box.min.x = box.min.x * scale.x + position.x;
    box.min.y = box.min.y * scale.y + position.y;
    box.min.z = box.min.z * scale.z + position.z;

    box.max.x = box.max.x * scale.x + position.x;
    box.max.y = box.max.y * scale.y + position.y;
    box.max.z = box.max.z * scale.z + position.z;

    return box;
}

Level LoadLevel(const char* jsonPath)
{
    Level level = {0};

    FILE* file = fopen(jsonPath, "rb");
    if (!file)
    {
        printf("Erro ao abrir %s\n", jsonPath);
        return level;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* buffer = malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    fclose(file);

    cJSON* root = cJSON_Parse(buffer);
    free(buffer);

    if (!root)
    {
        printf("Erro ao parsear JSON\n");
        return level;
    }

    int count = cJSON_GetArraySize(root);
    level.objects = calloc(count, sizeof(LevelObject));
    level.count = count;

    for (int i = 0; i < count; i++)
    {
        cJSON* obj = cJSON_GetArrayItem(root, i);

        // Nome
        cJSON* name = cJSON_GetObjectItem(obj, "name");
        if (name && name->valuestring)
            strncpy(level.objects[i].name, name->valuestring, 63);

        // Model (AGORA COM CACHE)
        cJSON* modelJson = cJSON_GetObjectItem(obj, "model");
        if (modelJson && modelJson->valuestring)
        {
            level.objects[i].model = GetModel(modelJson->valuestring);
        }
        else
        {
            level.objects[i].model = NULL;
        }

        // Position
        cJSON* pos = cJSON_GetObjectItem(obj, "position");
        if (pos)
        {
            level.objects[i].position = (Vector3){
                (float)cJSON_GetObjectItem(pos,"x")->valuedouble,
                (float)cJSON_GetObjectItem(pos,"y")->valuedouble,
                (float)cJSON_GetObjectItem(pos,"z")->valuedouble
            };
        }

        // Scale
        cJSON* scale = cJSON_GetObjectItem(obj, "scale");
        if (scale)
        {
            level.objects[i].scale = (Vector3){
                (float)cJSON_GetObjectItem(scale,"x")->valuedouble,
                (float)cJSON_GetObjectItem(scale,"y")->valuedouble,
                (float)cJSON_GetObjectItem(scale,"z")->valuedouble
            };
        }
        else
        {
            level.objects[i].scale = (Vector3){1,1,1};
        }

        // Gera bounding box automaticamente
        if (level.objects[i].model)
        {
            level.objects[i].bounds =
                GenerateWorldBounds(
                    level.objects[i].model,
                    level.objects[i].position,
                    level.objects[i].scale
                );
        }
    }

    cJSON_Delete(root);
    return level;
}

void DrawLevel(Level* level)
{
    for (int i = 0; i < level->count; i++)
    {
        if (!level->objects[i].model) continue;

        DrawModelEx(
            *level->objects[i].model,
            level->objects[i].position,
            (Vector3){0,1,0},
            0.0f,
            level->objects[i].scale,
            WHITE
        );

        // Debug colisão
        DrawBoundingBox(level->objects[i].bounds, RED);
    }
}

bool CheckLevelCollision(Level* level, BoundingBox box)
{
    for (int i = 0; i < level->count; i++)
    {
        if (CheckCollisionBoxes(box, level->objects[i].bounds))
        {
            return true;
        }
    }

    return false;
}

void UnloadLevel(Level* level)
{
    free(level->objects);
    level->objects = NULL;
    level->count = 0;
}