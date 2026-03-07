#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include <stdbool.h>

typedef enum {
    ENTITY_STATIC,
    ENTITY_DYNAMIC
} EntityKind;

typedef struct EntityType {
    void (*Init)();
    void (*Update)(float dt);
    void (*Draw)();
    void (*Unload)();
} EntityType;

typedef struct Entity {
    Vector3 position;
    Vector3 velocity;
    Vector3 size;
    Vector3 rotationAxis;
    Vector3 scale; 
    Color color;
    Model model;
    ModelAnimation *anims;
    
    bool active;
    bool grounded;
    
    float rotationAngle;
    float speed;
    float jumpForce;
    float gravity;

    EntityKind kind;
    EntityType* type;
} Entity;

#endif