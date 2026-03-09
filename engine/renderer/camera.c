#include "camera.h"

static Camera camera = (Camera){ 0 };

Camera CreateCamera() {
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = Vector3Zero();
    camera.projection = CAMERA_PERSPECTIVE;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 75.0f;
    return camera;
}

Camera GetMainCamera(void) {
    return camera;
}