#ifndef LEVEL_H
#define LEVEL_H

#include "raylib.h"

typedef struct LevelObject {
    char name[64];

    Model* model;        // agora é ponteiro
    Vector3 position;
    Vector3 scale;

    BoundingBox bounds;  // colisão automática
} LevelObject;

typedef struct Level {
    LevelObject* objects;
    int count;
} Level;

Level LoadLevel(const char* jsonPath);
void DrawLevel(Level* level);
void UnloadLevel(Level* level);

bool CheckLevelCollision(Level* level, BoundingBox box);

#endif