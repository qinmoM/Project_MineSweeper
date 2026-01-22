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
        ),
        1.0f,
        15.0f,
        1.0f
    );
    gameManager.registerState("Menu", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateMenu>(gameManager.getContext()); });
    gameManager.init("Menu");

    while (window.windowExists())
    {
        window.drawingBegin();
        window.clearBackground(Base::Color{230, 230, 230, 0});

        gameManager.update(window.FPSgetFrameTime());
        gameManager.render();

        window.drawingEnd();
        window.FPSDelay();
    }

    window.windowClose();
}