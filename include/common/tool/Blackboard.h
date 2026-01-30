#pragma once

#include <unordered_map>
#include <string>
#include <any>
#include <stdexcept>

class Blackboard final
{
public:
    inline bool exists(const std::string& key) const
    {
        return data_.find(key) != data_.end();
    }

    template<typename T>
    inline void set(const std::string& key, T&& value)
    {
        data_[key] = std::forward<T>(value);
    }

    template<typename T>
    inline T* tryGet(const std::string& key)
    {
        std::unordered_map<std::string, std::any>::iterator it = data_.find(key);

        if (it == data_.end())
            return nullptr;

        return std::any_cast<T>(&(it->second));
    }

    template<typename T>
    inline const T* tryGet(const std::string& key) const
    {
        std::unordered_map<std::string, std::any>::iterator it = data_.find(key);

        if (it == data_.end())
            return nullptr;

        return std::any_cast<T>(&(it->second));
    }

    inline void remove(const std::string& key)
    {
        data_.erase(key);
    }

    inline void clear()
    {
        data_.clear();
    }
private:
    std::unordered_map<std::string, std::any> data_;
};