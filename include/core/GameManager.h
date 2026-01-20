#pragma once

#include "GameStateMenu.h"
#include <stdexcept>
#include <vector>

class GameManager
{
public:
    GameManager(RendererBase& renderer, std::shared_ptr<HandleInputBase> handleInput);
    ~GameManager() = default;
public:
    void init();

    void update(float delta);
    void render();
protected:
    std::shared_ptr<RendererProxy> rendererProxy_;
    std::shared_ptr<HandleInputSemantic> handleInput_;
    std::shared_ptr<GameStateManager> stateManager_;
};