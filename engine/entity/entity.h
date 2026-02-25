#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

typedef struct Entity {
    Vector3 position;
    Vector3 velocity;
    Vector3 size;
    
    float speed;
    float jumpForce;
    float gravity;

    bool grounded;
} Entity;

#endif