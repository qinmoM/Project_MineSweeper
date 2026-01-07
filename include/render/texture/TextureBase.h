#pragma once

class TextureBase
{
public:
    virtual ~TextureBase() = default;

    TextureBase(const TextureBase& other) = delete;
    TextureBase& operator=(const TextureBase& other) = delete;
protected:
    TextureBase() = default;
};