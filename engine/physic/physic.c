#include "../entity/entity.h"
#include "../core/game.h"

#define MAX_ENTITIES 100

static Entity worldEntities[MAX_ENTITIES];
static int worldCount = 0;
static Shader shader = {0};

void InitPhysics(void) {
    shader = GetBasicShader();
}

BoundingBox GetEntityBoundingBox(Entity* entity) {
    Vector3 min = {
        entity->position.x - entity->size.x,
        entity->position.y - entity->size.y,
        entity->position.z - entity->size.z
    };
    Vector3 max = {
        entity->position.x + entity->size.x,
        entity->position.y + entity->size.y,
        entity->position.z + entity->size.z
    };
    return (BoundingBox){ min, max };
}

void ResolveCollisionAxis(Entity* entity, BoundingBox* worldBoxes, int worldCount, int axis)  {
    BoundingBox entityBox = GetEntityBoundingBox(entity);
    for (int i = 0; i < worldCount; i++) {
        if (CheckCollisionBoxes(entityBox, worldBoxes[i])) {
            if (axis == 0) { // X 
                if (entity->velocity.x > 0)
                    entity->position.x = worldBoxes[i].min.x - entity->size.x;
                else if (entity->velocity.x < 0)
                    entity->position.x = worldBoxes[i].max.x + entity->size.x;

                entity->velocity.x = 0;
            }
            if (axis == 1) { // Y
                if (entity->velocity.y > 0)
                    entity->position.y = worldBoxes[i].min.y - entity->size.y;
                else if (entity->velocity.y < 0)
                {
                    entity->position.y = worldBoxes[i].max.y + entity->size.y;
                    entity->grounded = true;
                }
                entity->velocity.y = 0;
            }
            if (axis == 2) { // Z
                if (entity->velocity.z > 0)
                    entity->position.z = worldBoxes[i].min.z - entity->size.z;
                else if (entity->velocity.z < 0)
                    entity->position.z = worldBoxes[i].max.z + entity->size.z;

                entity->velocity.z = 0;
            }
            entityBox = GetEntityBoundingBox(entity);
        }
    }
}

void ApplyGravity(Entity* entity, BoundingBox* worldBoxes, int worldCount, float dt) {
    entity->grounded = false;
    entity->velocity.y -= entity->gravity * dt; // Gravity
    entity->position.x += entity->velocity.x * dt; // X
    ResolveCollisionAxis(entity, worldBoxes, worldCount, 0); // X
    entity->position.z += entity->velocity.z * dt; // Z
    ResolveCollisionAxis(entity, worldBoxes, worldCount, 2); // Z
    entity->position.y += entity->velocity.y * dt; // Y
    ResolveCollisionAxis(entity, worldBoxes, worldCount, 1); // Y
}

int GetStaticWorldBoxes(Entity* entities, int count, BoundingBox* outBoxes) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        if (entities[i].kind == ENTITY_STATIC) {
            outBoxes[total++] = GetEntityBoundingBox(&entities[i]);
        }
    }
    return total;
}

void UpdateWorld(Entity* entities, int count, float dt) {
    BoundingBox staticBoxes[MAX_ENTITIES];
    int staticCount = GetStaticWorldBoxes(entities, count, staticBoxes);
    for (int i = 0; i < count; i++) {
        if (entities[i].kind == ENTITY_DYNAMIC) {
            ApplyGravity(&entities[i], staticBoxes, staticCount, dt);
        }
    }
}

void AddEntity(Entity* entity) {
    for (int i = 0; i < entity->model.materialCount; i++) {
        entity->model.materials[i].shader = shader;
    }
    worldEntities[worldCount++] = *entity;
}

void Step(float deltaTime) {
    UpdateWorld(worldEntities, worldCount, deltaTime);
    for (int i = 0; i < worldCount; i++) {
        worldEntities[i].type->Draw(&worldEntities[i]);
        worldEntities[i].type->Update(&worldEntities[i], deltaTime);
    }
}