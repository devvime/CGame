#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "../../../engine/entity/entity.h"

// typedef struct Player {
//     Vector3 position;
//     Vector3 velocity;
//     Vector3 size;
    
//     float speed;
//     float jumpForce;
//     float gravity;

//     bool grounded;
// } Player;

void Player_Init(Entity* player);
void Player_Update(Entity* player, float deltaTime);
void Player_Draw(Entity* player);

#endif