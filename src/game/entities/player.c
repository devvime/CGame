#include "../../../engine/entity/entity.h"

void PlayerInit(Entity* player) {
    player->position = (Vector3){0, 5, 0};
    player->velocity = (Vector3){0};
    player->size = (Vector3){0.5f, 0.5f, 0.5f};
    player->speed = 5.0f;
    player->jumpForce = 6.0f;
    player->gravity = 12;
    player->grounded = false;
    player->kind = ENTITY_DYNAMIC;
    player->model = LoadModelFromMesh(GenMeshCube(1,1,1));
}

void PlayerUpdate(Entity* player, float deltaTime) {
    if (IsKeyDown(KEY_W)) player->position.z -= player->speed * deltaTime;
    if (IsKeyDown(KEY_S)) player->position.z += player->speed * deltaTime;
    if (IsKeyDown(KEY_A)) player->position.x -= player->speed * deltaTime;
    if (IsKeyDown(KEY_D)) player->position.x += player->speed * deltaTime;
    if (IsKeyPressed(KEY_SPACE) && player->grounded)
    {
        player->velocity.y = player->jumpForce;
        player->grounded = false;
    }
}

void PlayerDraw(Entity* player) {
    DrawModel(player->model, player->position, 1.0f, RED);
    DrawCylinder(
        (Vector3){player->position.x, 0.01f, player->position.z}, // posição
        0.8f,   // raio topo
        0.8f,   // raio base
        0.02f,  // altura bem pequena
        20,     // subdivisões
        Fade(BLACK, 0.4f)
    );
}

void PlayerUnload(Entity* player) {
    TraceLog(LOG_INFO, "PlayerUnload");
}

EntityType PlayerType = {
    .Init = PlayerInit,
    .Update = PlayerUpdate,
    .Draw = PlayerDraw,
    .Unload = PlayerUnload
};

Entity Player = {
    .type = &PlayerType
};