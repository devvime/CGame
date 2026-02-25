#include "../entity/entity.h"

BoundingBox GetEntityBoundingBox(Entity* entity)
{
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

void ResolveCollisionAxis(
    Entity* entity,
    BoundingBox* worldBoxes,
    int worldCount,
    int axis
) {
    BoundingBox entityBox = GetEntityBoundingBox(entity);

    for (int i = 0; i < worldCount; i++)
    {
        if (CheckCollisionBoxes(entityBox, worldBoxes[i]))
        {
            if (axis == 0) // X
            {
                if (entity->velocity.x > 0)
                    entity->position.x = worldBoxes[i].min.x - entity->size.x;
                else if (entity->velocity.x < 0)
                    entity->position.x = worldBoxes[i].max.x + entity->size.x;

                entity->velocity.x = 0;
            }

            if (axis == 1) // Y
            {
                if (entity->velocity.y > 0)
                    entity->position.y = worldBoxes[i].min.y - entity->size.y;
                else if (entity->velocity.y < 0)
                {
                    entity->position.y = worldBoxes[i].max.y + entity->size.y;
                    entity->grounded = true;
                }

                entity->velocity.y = 0;
            }

            if (axis == 2) // Z
            {
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

void ApplyGravity(
    Entity* entity,
    BoundingBox* worldBoxes,
    int worldCount,
    float dt)
{
    entity->grounded = false;

    // Input horizontal
    float moveX = 0;
    float moveZ = 0;

    if (IsKeyDown(KEY_W)) moveZ -= 1;
    if (IsKeyDown(KEY_S)) moveZ += 1;
    if (IsKeyDown(KEY_A)) moveX -= 1;
    if (IsKeyDown(KEY_D)) moveX += 1;

    entity->velocity.x = moveX * entity->speed;
    entity->velocity.z = moveZ * entity->speed;

    // Gravidade
    entity->velocity.y -= entity->gravity * dt;

    // Pulo
    if (IsKeyPressed(KEY_SPACE) && entity->grounded)
    {
        entity->velocity.y = entity->jumpForce;
        entity->grounded = false;
    }

    // === Movimento por eixo ===

    // X
    entity->position.x += entity->velocity.x * dt;
    ResolveCollisionAxis(entity, worldBoxes, worldCount, 0);

    // Z
    entity->position.z += entity->velocity.z * dt;
    ResolveCollisionAxis(entity, worldBoxes, worldCount, 2);

    // Y
    entity->position.y += entity->velocity.y * dt;
    ResolveCollisionAxis(entity, worldBoxes, worldCount, 1);
}