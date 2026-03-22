#pragma once

#include "GameStateManager.h"
#include "ButtonImage.h"

class GameStateHelp : public GameStateBase
{
public:
    virtual void enter() override;
    virtual void exit() override;

    virtual void update(float delta) override;
    virtual void render() override;

public:
    GameStateHelp(GameStateContext &context, const std::string& stateName);
    virtual ~GameStateHelp() = default;

private:
    std::vector<std::shared_ptr<FontBase>> fonts_;
};