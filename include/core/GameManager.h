#pragma once

#include "GameStateMenu.h"
#include <memory>
#include <stdexcept>

class GameManager
{
public:
    GameManager(RendererBase& renderer, std::shared_ptr<HandleInputBase> handleInput);
    ~GameManager() = default;
public:
    void init();
    void changeState(std::unique_ptr<GameStateBase> newState);

    void update(float delta);
    void render();
private:
    std::unique_ptr<GameStateBase> currState_;
    std::shared_ptr<RendererProxy> rendererProxy_;
    std::shared_ptr<HandleInputBase> handleInput_;
};