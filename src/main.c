#include "renderer/renderer.h"
#include "scene/scene.h"
#include "scene/manager.h"

extern Scene MenuScene;

int main(void)
{
    LoadScene(&MenuScene);
    Render(1280, 720, "Game Dev Template");
    return 0;
}