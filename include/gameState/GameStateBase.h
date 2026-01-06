#pragma once

#include "RendererProxy.h"

class GameStateBase
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

    virtual void update(float delta) = 0;
    virtual void render() = 0;
public:
    GameStateBase(RendererProxy& renderer) : renderer_(renderer) {}
    virtual~GameStateBase() = default;
protected:
    RendererProxy& renderer_;
};