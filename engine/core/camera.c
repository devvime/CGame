#include "camera.h"

static Camera3D MainCamera = {
    .position = (Vector3){0.0f, 10.0f, 10.0f},
    .target = (Vector3){0.0f, 0.0f, 0.0f},
    .up = (Vector3){0.0f, 1.0f, 0.0f},
    .fovy = 75.0f,
    .projection = CAMERA_PERSPECTIVE
};

void SetCamera(Camera3D camera) {
    MainCamera = camera;
}

Camera3D GetCamera(void) {
    return MainCamera;
}