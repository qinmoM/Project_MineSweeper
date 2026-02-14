#pragma once

#include "RendererProxy.h"
#include "HandleInputSemantic.h"
#include "ButtonBase.h"
#include "Archive.h"
#include "ConfigSystem.h"
#include "Blackboard.h"
#include "IAudioSystem.h"
#include <memory>
#include <vector>

class GameStateManager;

struct GameStateContext
{
    GameStateContext(RendererProxy& renderer, HandleInputSemantic& handleInput, IAudioSystem& audioSystem, GameStateManager& stateManager, Archive& archive, ConfigSystem& configSystem, Blackboard& blackboard)
        : renderer(renderer)
        , handleInput(handleInput)
        , audio(audioSystem)
        , stateManager(stateManager)
        , archive(archive)
        , configSystem(configSystem)
        , blackboard(blackboard)
    { }
    
    RendererProxy& renderer;
    HandleInputSemantic& handleInput;
    IAudioSystem& audio;
    GameStateManager& stateManager;
    Archive& archive;
    ConfigSystem& configSystem;
    Blackboard& blackboard;
};

class GameStateBase
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

    virtual void update(float delta) = 0;
    virtual void render() = 0;
public:
    GameStateBase(GameStateContext& context, const std::string& stateName)
        : context_(context)
        , stateName_(stateName)
    { }
    virtual ~GameStateBase() = default;
protected:
    GameStateContext& context_;
    std::string stateName_;
    std::vector<std::shared_ptr<ButtonBase>> button_;
};