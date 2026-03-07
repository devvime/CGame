#include "entity/entity.h"
#include "entity/entity_manager.h"
#include "renderer/shader.h"

static int animCount, frameCounter = 0;

void RobotInit(Entity* robot) {
    robot->active = true;
    robot->position = (Vector3) { 0.0f, 0.5f, 0.0f };
    robot->rotationAxis = (Vector3) { 0.0f, 1.0f, 0.0f };
    robot->scale = (Vector3) { 1.0f, 1.0f, 1.0f };
    robot->rotationAngle = 0.0f;
    robot->color = RED;
    robot->speed = 0;
    robot->gravity = 0;
    robot->kind = ENTITY_DYNAMIC;
    robot->model = LoadModel("resources/models/robot.glb");
    robot->anims = LoadModelAnimations("resources/models/robot.glb", &animCount);
    AddShader(robot->model);
}

void RobotUpdate(Entity* robot, float deltaTime) {
    frameCounter++;
    frameCounter %= (robot->anims[0].frameCount);
    UpdateModelAnimation(robot->model, robot->anims[0], (float)frameCounter);
}

void RobotDraw(Entity* robot) {
    DrawModelEx(robot->model, robot->position, robot->rotationAxis, robot->rotationAngle, robot->scale, robot->color);
}

void RobotUnload(Entity* robot) {
    UnloadModel(robot->model);
    UnloadModelAnimations(robot->anims, animCount);
}

EntityType RobotType = {
    .Init = RobotInit,
    .Update = RobotUpdate,
    .Draw = RobotDraw,
    .Unload = RobotUnload
};

Entity Robot = {
    .type = &RobotType
};