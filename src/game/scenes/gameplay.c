#include "raylib.h"
#include "scene/scene.h"
#include "renderer/shader.h"
#include "entity/entity.h"
#include "entity/entity_manager.h"

static Model cube, robot;
static int animCount, frameCounter = 0;
static ModelAnimation *anims;

extern Entity Robot;

static void Init() {
    cube = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    cube.materials[0].shader = GetShader();
    
    SpawnEntity(&Robot);

    // robot = LoadModel("resources/models/robot.glb");
    // for (int i = 0; i < robot.materialCount; i++) robot.materials[i].shader = GetShader();

    // anims = LoadModelAnimations("resources/models/robot.glb", &animCount);
}

static void Draw2D(float deltaTime) {
    //
}

static void Draw3D(float deltaTime) {
    DrawModelEx(cube, Vector3Zero(), (Vector3) { 0.0f, 1.0f, 0.0f }, 0.0f, (Vector3) { 10.0f, 1.0f, 10.0f }, BLUE);
    DrawModelEx(cube, (Vector3) { 1.5f, 1.0f, -1.5f }, (Vector3) { 0.0f, 1.0f, 0.0f }, 0.0f, Vector3One(), WHITE);
    // DrawModelEx(robot, (Vector3) { 0.0f, 0.5f, 0.0f }, (Vector3) { 0.0f, 1.0f, 0.0f }, 0.0f, (Vector3) { 1.0f, 1.0f, 1.0f }, RED);
}

static void Update(float deltaTime) {
    // frameCounter++;
    // frameCounter %= (anims[0].frameCount);
    // UpdateModelAnimation(robot, anims[0], (float)frameCounter);
}

static void Unload(void) {
    UnloadModel(cube);
    // UnloadModel(robot);
    UnloadModelAnimations(anims, animCount);
}

Scene Gameplay = {
    .Init = Init,
    .Draw2D = Draw2D,
    .Draw3D = Draw3D,
    .Update = Update,
    .Unload = Unload
};