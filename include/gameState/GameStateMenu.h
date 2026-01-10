#include "GameStateBase.h"

class GameStateMenu : public GameStateBase
{
public:
    virtual void enter() override;
    virtual void exit() override;

    virtual void update(float delta) override;
    virtual void render() override;
public:
    GameStateMenu(std::shared_ptr<RendererProxy> rendererProxy, std::shared_ptr<HandleInputBase> handleInput) : GameStateBase(rendererProxy, handleInput) { };
    virtual ~GameStateMenu() = default;
};