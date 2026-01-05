#pragma once

class GameStateBase
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

    virtual void update(float delta) = 0;
    virtual void render() = 0;
public:
    ~GameStateBase() = default;
};