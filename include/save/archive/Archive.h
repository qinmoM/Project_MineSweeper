#pragma once

#include "ISerialization.h"

class Archive
{
public:
    inline void registerSerializer(std::string name, std::unique_ptr<ISerialization> serializer)
    {
        if (name.empty())
            throw std::invalid_argument("Name cannot be empty! | Archive::registerSerializer");

        if (!serializer)
            throw std::invalid_argument("Serializer cannot be null! | Archive::registerSerializer");

        if (serializers_.find(name) != serializers_.end())
            throw std::invalid_argument("This name has already been registered! | Archive::registerSerializer");

        serializers_[name] = std::move(serializer);
    }

    template<typename T>
    inline void serialize(const std::string& serializerName, const std::string& path, T& obj)
    {
        if (serializers_.find(serializerName) == serializers_.end())
            throw std::invalid_argument("This serializerName has not been registered! | Archive::serialize");

        std::unique_ptr<ISerialization>& serializer = serializers_[serializerName];
        serializer->setSavingMode();
        serializer->beginObject(path);
        obj.serialize(*serializer);
        serializer->endObject();
    }

    template<typename T>
    inline void deserialize(const std::string& serializerName, const std::string& path, T& obj)
    {
        if (serializers_.find(serializerName) == serializers_.end())
            throw std::invalid_argument("This serializerName has not been registered! | Archive::serialize");

        std::unique_ptr<ISerialization>& serializer = serializers_[serializerName];
        serializer->setLoadingMode();
        serializer->beginObject(path);
        obj.serialize(*serializer);
        serializer->endObject();
    }

    inline void flushAll()
    {
        for (auto& [_, serializer] : serializers_)
            serializer->flush();
    }
protected:
    std::unordered_map<std::string, std::unique_ptr<ISerialization>> serializers_;
};