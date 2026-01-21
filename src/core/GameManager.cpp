#include "GameManager.h"

GameManager::GameManager(RendererBase& renderer, std::shared_ptr<HandleInputBase> handleInput, std::string state)
    : context_(std::make_shared<RendererProxy>(renderer), std::make_shared<HandleInputSemantic>(handleInput), std::make_shared<GameStateManager>())
{
    init(state);
}

void GameManager::init(std::string state)
{
    context_.stateManager->registerState(
        "Menu", [this]() -> GameStateManager::stateType { return std::make_unique<GameStateMenu>(context_); }
    );

    context_.stateManager->pushState(state);
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