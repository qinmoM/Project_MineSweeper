#include "Game.h"

void Game::run()
{
    RendererBase& renderer = RendererRaylib::getInstance();
    GameManager gameManager;
    renderer.windowInit(600, 700, "test");
    renderer.FPSset(60);

    while (renderer.windowExists())
    {
        renderer.drawingBegin();
        renderer.clearBackground(Base::ColorBase{255, 255, 255, 0});

        gameManager.update(renderer.FPSgetFrameTime());
        gameManager.render();

        renderer.drawingEnd();
        renderer.FPSDelay();
    }

    renderer.windowClose();
}