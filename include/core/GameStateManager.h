#pragma once

#include "GameStateBase.h"
#include <functional>
#include <stdexcept>
#include <vector>
#include <queue>

class GameStateManager
{
public:
    using stateType = std::unique_ptr<GameStateBase>;
    using Creator = std::function<stateType()>;
public:
    void registerState(std::string stateName, Creator creator);
    void unregisterState(std::string stateName);

    void pushState(std::string newState);
    void popState();
    void clearState();

    void addTask(const std::function<void()>& task);
    void clearTask();

    void requestQuit();
protected:
    std::vector<stateType> stateStack_;
    std::queue<std::function<void()>> tasksQueue_;
    std::unordered_map<std::string, Creator> registerCreators_;
    friend class GameManager;
};