#include "GameManager.h"

GameManager::GameManager(RendererBase& renderer, std::shared_ptr<HandleInputBase> handleInput)
    : context_(std::make_shared<RendererProxy>(renderer), std::make_shared<HandleInputSemantic>(handleInput), std::make_shared<GameStateManager>())
{
    init();
}

void GameManager::init()
{
    context_.stateManager->pushState("Menu");
    context_.stateManager->stateStack_.back()->enter();
}




void GameManager::update(float delta)
{
    // update input io
    context_.handleInput->update(delta);

    // update game state
    if (!context_.stateManager->stateStack_.empty())
        context_.stateManager->stateStack_.back()->update(delta);
}

void GameManager::render()
{
    for (GameStateManager::stateType& state : context_.stateManager->stateStack_)
        state->render();
}