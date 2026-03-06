#include "raylib.h"
#include "renderer/renderer.h"
#include "scene/scene.h"
#include "scene/manager.h"
#include "gui/button.h"

static Button startButton;
static Button exitButton;
extern Scene Gameplay;

static void Init(void) {    
    startButton = Button_Create(
        540, 330,
        200, 50,
        "Start Game",
        BLACK,
        20,
        LIGHTGRAY,
        GRAY
    );

    exitButton = Button_Create(
        540, 390,
        200, 50,
        "Exit Game",
        BLACK,
        20,
        LIGHTGRAY,
        GRAY
    );
}

static void Draw2D(float deltaTime) {
    DrawText("Hello world", 580, 290, 20, VIOLET);
}

static void Draw3D(float deltaTime) {
    //
}

static void Update(float deltaTime) {
    if (Button_Draw(&startButton))
    {
        LoadScene(&Gameplay);
    }

    if (Button_Draw(&exitButton))
    {
        Close();
    }
}

static void Unload(void) {
}

Scene MenuScene = {
    .Init = Init,
    .Draw2D = Draw2D,
    .Draw3D = Draw3D,
    .Update = Update,
    .Unload = Unload
};