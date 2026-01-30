#pragma once

#include "GameManager.h"
#include "RendererRaylib.h"
#include "WindowProxy.h"
#include "HandleInputRaylib.h"
#include "JsonSerialization.h"

class Game
{
public:
    void run();
private:
    std::unique_ptr<RendererProxy> renderer_;
    std::unique_ptr<WindowProxy> window_;
    std::unique_ptr<HandleInputSemantic> handleInput_;
    std::unique_ptr<GameStateManager> stateManager_;
    std::unique_ptr<Archive> archive_;
    std::unique_ptr<ConfigSystem> configSystem_;
    std::unique_ptr<Blackboard> blackboard_;
};