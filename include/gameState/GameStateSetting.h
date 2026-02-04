#pragma once

#include "GameStateManager.h"
#include "ButtonText.h"
#include "ButtonImage.h"

class GameStateSetting : public GameStateBase
{
public:
    virtual void enter() override;
    virtual void exit() override;

    virtual void update(float delta) override;
    virtual void render() override;

public:
    GameStateSetting(GameStateContext &context);
    virtual ~GameStateSetting() = default;

private:
    std::vector<std::shared_ptr<FontBase>> fonts_;
};