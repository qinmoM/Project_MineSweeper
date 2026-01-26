#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <unordered_map>
#include <stdexcept>

class ISerialization
{
public:
    inline bool isSavingMode() const { return saving_; };
    inline void setSavingMode() { saving_ = true; };
    inline void setLoadingMode() { saving_ = false; };

    virtual void beginObject(const std::string& path) = 0;
    virtual void endObject() = 0;
    virtual void flush() = 0;

    virtual void value(const std::string& key, bool& value) = 0;
    virtual void value(const std::string& key, char& value) = 0;
    virtual void value(const std::string& key, short& value) = 0;
    virtual void value(const std::string& key, unsigned short& value) = 0;
    virtual void value(const std::string& key, int& value) = 0;
    virtual void value(const std::string& key, unsigned int& value) = 0;
    virtual void value(const std::string& key, long& value) = 0;
    virtual void value(const std::string& key, unsigned long& value) = 0;
    virtual void value(const std::string& key, long long& value) = 0;
    virtual void value(const std::string& key, unsigned long long& value) = 0;
    virtual void value(const std::string& key, float& value) = 0;
    virtual void value(const std::string& key, double& value) = 0;
    virtual void value(const std::string& key, std::string& value) = 0;
public:
    virtual ~ISerialization() = default;
protected:
    bool saving_ = true;
};