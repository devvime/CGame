#include "raylib.h"
#include "scene/scene.h"
#include "renderer/shader.h"
#include "entity/entity.h"
#include "entity/entity_manager.h"

static Model cube;

extern Entity Robot;

static void Init() {
    cube = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    cube.materials[0].shader = GetShader();
    
    SpawnEntity(&Robot);
}

static void Draw2D(float deltaTime) {
    //
}

static void Draw3D(float deltaTime) {
    DrawModelEx(cube, Vector3Zero(), (Vector3) { 0.0f, 1.0f, 0.0f }, 0.0f, (Vector3) { 10.0f, 1.0f, 10.0f }, BLUE);
    DrawModelEx(cube, (Vector3) { 1.5f, 1.0f, -1.5f }, (Vector3) { 0.0f, 1.0f, 0.0f }, 0.0f, Vector3One(), WHITE);
}

static void Update(float deltaTime) {
    //
}

static void Unload(void) {
    UnloadModel(cube);
}

Scene Gameplay = {
    .Init = Init,
    .Draw2D = Draw2D,
    .Draw3D = Draw3D,
    .Update = Update,
    .Unload = Unload
};