#include "player.h"

void Player_Init(Player* player)
{
    player->position = (Vector3){0, 1, 0};
    player->speed = 5.0f;
}

void Player_Update(Player* player, float deltaTime)
{
    if (IsKeyDown(KEY_W)) player->position.z -= player->speed * deltaTime;
    if (IsKeyDown(KEY_S)) player->position.z += player->speed * deltaTime;
    if (IsKeyDown(KEY_A)) player->position.x -= player->speed * deltaTime;
    if (IsKeyDown(KEY_D)) player->position.x += player->speed * deltaTime;
}

void Player_Draw(Player* player)
{
    DrawCube(player->position, 1, 1, 1, RED);
}