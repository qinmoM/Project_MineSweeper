#include "GameManager.h"

GameManager::GameManager(RendererBase& renderer, std::shared_ptr<HandleInputBase> handleInput)
    : rendererProxy_(std::make_shared<RendererProxy>(renderer))
    , handleInput_(std::make_shared<HandleInputSemantic>(handleInput))
{
    init();
}

void GameManager::init()
{
    stateManager_->pushState("Menu");
    stateManager_->stateStack_.back()->enter();
}




void GameManager::update(float delta)
{
    // update input io
    handleInput_->update(delta);

    // update game state
    if (!stateManager_->stateStack_.empty())
        stateManager_->stateStack_.back()->update(delta);
}

void GameManager::render()
{
    for (GameStateManager::stateType& state : stateManager_->stateStack_)
        state->render();
}