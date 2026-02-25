#include "raylib.h"
#include "../engine/core/game.h"
#include "../engine/core/renderer.h"

extern Scene MenuScene;

int main(void)
{
    ChangeScene(&MenuScene);
    StartGame(1280, 720, "Meu Jogo 3D com raylib");
    return 0;
}