#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"
#include "raymath.h"

static Camera3D camera;

Camera3D CreateCamera(void);
Camera3D GetMainCamera(void);

#endif