#pragma once

#include "GameStateMenu.h"
#include <stdexcept>
#include <vector>

class GameManager
{
public:
    GameManager(RendererBase& renderer, std::shared_ptr<HandleInputBase> handleInput, std::string state);
    ~GameManager() = default;
public:
    void init(std::string state);

    void update(float delta);
    void render();
protected:
    GameStateContext context_;
};