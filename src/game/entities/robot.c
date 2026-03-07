#include "entity/entity.h"

static Entity* robot = {0};
static int animCount, frameCounter = 0;

void RobotInit() {
    TraceLog(LOG_INFO, "INICIANDO ROBOT");
    robot->position = (Vector3) { 0.0f, 0.5f, 0.0f };
    robot->rotationAxis = (Vector3) { 0.0f, 1.0f, 0.0f };
    robot->scale = (Vector3) { 1.0f, 1.0f, 1.0f };
    robot->rotationAngle = 0.0f;
    robot->color = RED;
    robot->speed = 0;
    robot->gravity = 0;
    robot->kind = ENTITY_DYNAMIC;
    TraceLog(LOG_INFO, "CARREGANDO MODELOS");
    robot->model = LoadModel("resources/models/robot.glb");
    robot->anims = LoadModelAnimations("resources/models/robot.glb", &animCount);
    TraceLog(LOG_INFO, "ROBOT INICIADO");
}

void RobotUpdate(float deltaTime) {
    frameCounter++;
    frameCounter %= (robot->anims[0].frameCount);
    UpdateModelAnimation(robot->model, robot->anims[0], (float)frameCounter);
}

void RobotDraw() {
    DrawModelEx(robot->model, robot->position, robot->rotationAxis, robot->rotationAngle, robot->scale, robot->color);
}

void RobotUnload(Entity* floor) {
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