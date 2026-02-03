#pragma once

#include "GameStateBase.h"
#include <functional>
#include <stdexcept>
#include <vector>
#include <map>

class GameStateManager
{
public:
    using stateType = std::unique_ptr<GameStateBase>;
    using Creator = std::function<stateType()>;
public:
    struct Task
    {
        Task(const std::function<void()>& task, float frameDelay) : task_(task), frameDelay_(frameDelay) { }

        std::function<void()> task_;
        float frameDelay_;
    };
public:
    void registerState(std::string stateName, Creator creator);
    void unregisterState(std::string stateName);

    void pushState(std::string newState);
    void popState();
    void clearState();

    void addTask(const std::function<void()>& task, float priority = 0.5f, float frameDelay = 0.0f);
    void clearTask();

    void requestQuit();
    bool shouldQuit() const;
protected:
    std::vector<stateType> stateStack_;
    std::multimap<float, Task> tasksQueue_;
    std::unordered_map<std::string, Creator> registerCreators_;
    bool requestQuit_ = false;
    friend class GameManager;
};