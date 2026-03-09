#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"
#include "raymath.h"

static Camera camera;

Camera CreateCamera(void);
Camera GetMainCamera(void);

#endif