#pragma once

#include "GameStateMenu.h"
#include <memory>
#include <stdexcept>

class GameManager
{
public:
    GameManager();
    ~GameManager() = default;
public:
    void init();
    void changeState(std::unique_ptr<GameStateBase> newState);

    void update(float delta);
    void render();
private:
    std::unique_ptr<GameStateBase> currState_;
};