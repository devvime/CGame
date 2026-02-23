#include "camera.h"

Camera Camera_Create(void) {
  Camera camera = {0};

  camera.position = (Vector3){0.0f, 5.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 75.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  return camera;
}

void Camera_Update(Camera *camera) { 
  UpdateCamera(camera, CAMERA_ORBITAL); 
}
