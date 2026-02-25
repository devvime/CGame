#ifndef SCENE_H
#define SCENE_H

typedef struct Scene {
    void (*Init)(void);
    void (*Update)(float deltaTime);
    void (*Draw)(void);
    void (*Unload)(void);
} Scene;

#endif