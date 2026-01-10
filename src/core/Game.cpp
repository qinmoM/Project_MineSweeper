#include "Game.h"

void Game::run()
{
    WindowProxy window(RendererRaylib::getInstance());
    window.windowInit(1200, 1000, "test");
    window.FPSset(120);

    GameManager gameManager(
        RendererRaylib::getInstance(),
        std::make_shared<HandleInputRaylib>(
            MouseRaylib::getInstance(),
            KeyboardRaylib::getInstance()
        ));
    while (window.windowExists())
    {
        window.drawingBegin();
        window.clearBackground(Base::Color{200, 200, 200, 0});

        gameManager.update(window.FPSgetFrameTime());
        gameManager.render();

        window.drawingEnd();
        window.FPSDelay();
    }

    window.windowClose();
}