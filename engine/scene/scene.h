#ifndef SCENE_H
#define SCENE_H

typedef struct Scene {
    void (*Init)(void);
    void (*Update)(float deltaTime);
    void (*Draw)(float deltaTime);
    void (*Unload)(void);
} Scene;

#endif