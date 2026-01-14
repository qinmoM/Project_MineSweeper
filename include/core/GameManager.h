#pragma once

#include "GameStateMenu.h"
#include <memory>
#include <stdexcept>
#include <vector>

class GameManager
{
public:
    GameManager(RendererBase& renderer, std::shared_ptr<HandleInputBase> handleInput);
    ~GameManager() = default;
public:
    void init();

    void pushState(std::unique_ptr<GameStateBase> newState);
    void changeState(std::unique_ptr<GameStateBase> newState);

    void update(float delta);
    void render();
private:
    std::vector<std::unique_ptr<GameStateBase>> stateStack_;
    std::shared_ptr<RendererProxy> rendererProxy_;
    std::shared_ptr<HandleInputBase> handleInput_;
};