#include "player.h"
#include "../../../engine/physic/physic.h"

void Player_Init(Entity* player)
{
    // player->position = (Vector3){0, 1, 0};
    // player->speed = 5.0f;
    player->position = (Vector3){0, 5, 0};
    player->velocity = (Vector3){0};
    player->size = (Vector3){0.4f, 0.9f, 0.4f};
    player->speed = 5.0f;
    player->jumpForce = 6.0f;
    player->gravity = 9.8f;
    player->grounded = false;
}

void Player_Update(Entity* player, float deltaTime)
{
    // if (IsKeyDown(KEY_W)) player->position.z -= player->speed * deltaTime;
    // if (IsKeyDown(KEY_S)) player->position.z += player->speed * deltaTime;
    // if (IsKeyDown(KEY_A)) player->position.x -= player->speed * deltaTime;
    // if (IsKeyDown(KEY_D)) player->position.x += player->speed * deltaTime;
    BoundingBox entityBox = GetEntityBoundingBox(player);
    ApplyGravity(player, &entityBox, 0, deltaTime);
}

void Player_Draw(Entity* player)
{
    DrawCube(player->position, 1, 1, 1, RED);
}