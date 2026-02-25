#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
    Vector3 position;
    float speed;
} Player;

void Player_Init(Player* player);
void Player_Update(Player* player, float deltaTime);
void Player_Draw(Player* player);

#endif