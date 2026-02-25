#include "raylib.h"
#include "../../../engine/core/game.h"
#include "../../../engine/scene/scene.h"
#include "../../../engine/gui/button.h"

static Button startButton;
static Button exitButton;

static void Init(void)
{
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

static void Update(float deltaTime)
{
    //
}

static void Draw(void)
{
    DrawText("Hello world", 580, 290, 20, VIOLET);

    if (Button_Draw(&startButton))
    {
        TraceLog(LOG_INFO, "Botão iniciar clicado!");
    }

    if (Button_Draw(&exitButton))
    {
        RequestClose();
    }
}

static void Unload(void)
{
}

Scene MenuScene = {
    .Init = Init,
    .Update = Update,
    .Draw = Draw,
    .Unload = Unload
};