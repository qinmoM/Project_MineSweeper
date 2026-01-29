#include "GameManager.h"

GameManager::GameManager(RendererBase& renderer,
    std::unique_ptr<HandleInputBase> handleInput,
    std::unique_ptr<Archive> archive,
    std::unique_ptr<ConfigSystem> configConfig,
    float maxClickTime,
    float maxMoveDistance,
    float minLongPressTime)
    : context_(std::make_unique<RendererProxy>(renderer)
    , std::make_unique<HandleInputSemantic>(
        std::move(handleInput),
        maxClickTime,
        maxMoveDistance,
        minLongPressTime)
    , std::make_unique<GameStateManager>()
    , std::move(archive)
    , std::move(configConfig)
    )
{ }

void GameManager::init(std::string state)
{
    context_.stateManager->pushState(state);
}

void GameManager::registerState(std::string state, GameStateManager::Creator creator)
{
    context_.stateManager->registerState(state, creator);
}




void GameManager::update(float delta)
{
    // update input io
    context_.handleInput->update(delta);

    // update game state
    if (!context_.stateManager->stateStack_.empty())
        context_.stateManager->stateStack_.back()->update(delta);

    // tasks queue
    std::queue<std::function<void()>>& tasks = context_.stateManager->tasksQueue_;
    while (tasks.size())
    {
        tasks.front()();
        tasks.pop();
    }
}

void GameManager::render()
{
    for (GameStateManager::stateType& state : context_.stateManager->stateStack_)
        state->render();
}