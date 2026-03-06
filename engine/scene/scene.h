#ifndef SCENE_H
#define SCENE_H

typedef struct Scene {
    void (*Init)(void);
    void (*Draw2D)(float deltaTime);
    void (*Draw3D)(float deltaTime);
    void (*Update)(float deltaTime);
    void (*Unload)(void);
} Scene;

#endif