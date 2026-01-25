#pragma once

#include "ISerialization.h"
#include "jsonFile.h"

class JsonSerialization final : public ISerialization
{
public:
    void beginObject(const std::string& path) override;
    void endObject() override;
    void flush() override;

    void value(const std::string& key, bool& value) override;
    void value(const std::string& key, char& value) override;
    void value(const std::string& key, short& value) override;
    void value(const std::string& key, unsigned short& value) override;
    void value(const std::string& key, int& value) override;
    void value(const std::string& key, unsigned int& value) override;
    void value(const std::string& key, long& value) override;
    void value(const std::string& key, unsigned long& value) override;
    void value(const std::string& key, long long& value) override;
    void value(const std::string& key, unsigned long long& value) override;
    void value(const std::string& key, float& value) override;
    void value(const std::string& key, double& value) override;
    void value(const std::string& key, std::string& value) override;
private:
    std::unordered_map<std::string, nlohmann::json> buffers_;
    std::string currentPath_;
    nlohmann::json currentObject_;
};
