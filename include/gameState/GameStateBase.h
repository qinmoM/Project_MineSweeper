#pragma once

#include "RendererProxy.h"
#include "HandleInputSemantic.h"
#include "ButtonBase.h"
#include "Archive.h"
#include "ConfigSystem.h"
#include <memory>
#include <vector>

class GameStateManager;

struct GameStateContext
{
    GameStateContext(RendererProxy& renderer, HandleInputSemantic& handleInput, GameStateManager& stateManager, Archive& archive, ConfigSystem& configSystem)
        : renderer(renderer)
        , handleInput(handleInput)
        , stateManager(stateManager)
        , archive(archive)
        , configSystem(configSystem)
    { }
    
    RendererProxy& renderer;
    HandleInputSemantic& handleInput;
    GameStateManager& stateManager;
    Archive& archive;
    ConfigSystem& configSystem;
};

class GameStateBase
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

    virtual void update(float delta) = 0;
    virtual void render() = 0;
public:
    GameStateBase(GameStateContext& context)
        : context_(context)
    { }
    virtual ~GameStateBase() = default;
protected:
    GameStateContext& context_;
    std::vector<std::shared_ptr<ButtonBase>> button_;
};