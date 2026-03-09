#include "raylib.h"
#include "ui/ui.h"
#include "ui/button.h"
#include "scene/scene.h"
#include "scene/manager.h"
#include "renderer/renderer.h"

Button startButton;
Button exitButton;

extern Scene Gameplay;

static void Init() {
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

static void Draw() {
    DrawText("Hello world", 580, 290, 20, VIOLET);
}

static void Update(float deltaTime) {
    if (Button_Draw(&startButton)) {
        LoadScene(&Gameplay);
    }
    if (Button_Draw(&exitButton)) {
        Close();
    }
}

static void Unload() {

}

Ui MainMenu = {
    .Init = Init,
    .Draw = Draw,
    .Update = Update,
    .Unload = Unload
};