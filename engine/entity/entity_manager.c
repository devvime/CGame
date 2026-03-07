#include <string.h>
#include "entity_manager.h"
#include "renderer/shader.h"

#define MAX_ENTITIES 1000

Entity entities[MAX_ENTITIES] = {0};
int worldCount = 0;

void InitEntities() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        if (entities[i].type && entities[i].type->Init) {
            TraceLog(LOG_INFO, "ENTITY INICIADO");
            entities[i].type->Init(&entities[i]);
        }
    }
}

void SpawnEntity(Entity *entity) {
    if (worldCount >= MAX_ENTITIES) return;
    
    for (int i = 0; i < entity->model.materialCount; i++) entity->model.materials[i].shader = GetShader();

    TraceLog(LOG_INFO, "ENTITY SPAWNADO");
    entities[worldCount++] = *entity;
}

void UpdateEntities(float dt) {
    for (int i = 0; i < worldCount; i++) {
        if (!entities[i].active) continue;

        if (entities[i].type && entities[i].type->Update) {
            TraceLog(LOG_INFO, "ENTITY ATUALIZADO");
            entities[i].type->Update(&entities[i], dt);
        }
    }
}

void DrawEntities() {
    for (int i = 0; i < worldCount; i++) {
        if (!entities[i].active) continue;

        if (entities[i].type && entities[i].type->Draw) {
            TraceLog(LOG_INFO, "ENTITY DESENHADO");
            entities[i].type->Draw(&entities[i]);
        }
    }
}

void ResetEntities() {
    for (int i = 0; i < worldCount; i++) {
        if (entities[i].type && entities[i].type->Unload) {
            TraceLog(LOG_INFO, "ENTITY RESETADO");
            entities[i].type->Unload(&entities[i]);
        }
    }
    memset(entities, 0, sizeof(entities));
    worldCount = 0;
}