#include "JsonSerialization.h"



void JsonSerialization::beginObject(const std::string& path)
{
    if (path.empty())
        throw std::invalid_argument("path cannot be empty! | JsonSerialization::beginObject");

    if (saving_)
        currentPath_ = path;
    else
        if (!jsonFile(path).read(currentObject_))
            throw std::runtime_error("Failed to read from file! | JsonSerialization::beginObject");
}

void JsonSerialization::endObject()
{
    currentPath_.clear();
    currentObject_.clear();
}

void JsonSerialization::flush()
{
    jsonHandle handle;
    for (auto& [path, buffer] : buffers_)
        if (!handle.write(path, buffer))
            throw std::runtime_error("Failed to write from file! | JsonSerialization::flush");

    buffers_.clear();
}



void JsonSerialization::value(const std::string& key, bool& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, char& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, short& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, unsigned short& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, int& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, unsigned int& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, long& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, unsigned long& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, long long& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, unsigned long long& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, float& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, double& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}

void JsonSerialization::value(const std::string& key, std::string& value)
{
    if (saving_)
        buffers_[currentPath_][key] = value;
    else
        value = currentObject_.value(key, value);
}
