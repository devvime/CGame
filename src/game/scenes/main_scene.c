#include "raylib.h"
#include "scene/scene.h"
#include "ui/ui.h"

extern Ui MainMenu;

static void Init(void) {    
    MainMenu.Init();
}

static void Draw2D(float deltaTime) {
    MainMenu.Draw();
}

static void Draw3D(float deltaTime) {
    //
}

static void Update(float deltaTime) {
    MainMenu.Update(deltaTime);
}

static void Unload(void) {
    //
}

Scene MainScene = {
    .Init = Init,
    .Draw2D = Draw2D,
    .Draw3D = Draw3D,
    .Update = Update,
    .Unload = Unload
};