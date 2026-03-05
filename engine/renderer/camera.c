#include "camera.h"

static Camera3D camera = (Camera3D){ 0 };

Camera3D CreateCamera() {
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = Vector3Zero();
    camera.projection = CAMERA_PERSPECTIVE;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 75.0f;
    return camera;
}

Camera3D GetMainCamera(void) {
    return camera;
}