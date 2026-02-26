#include "../../../engine/entity/entity.h"

extern Entity Floor;

void PlayerInit(Entity* player) {
    player->position = (Vector3){0, 5, 0};
    player->velocity = (Vector3){0};
    player->size = (Vector3){0.4f, 0.9f, 0.4f};
    player->speed = 5.0f;
    player->jumpForce = 6.0f;
    player->gravity = 12;
    player->grounded = false;
    player->kind = ENTITY_DYNAMIC;
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
    DrawCube(player->position, 1, 1, 1, RED);
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