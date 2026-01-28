#pragma once

#include "raylib.h"
#include "RendererBase.h"
#include "TextureRaylib.h"
#include "FontRaylib.h"
#include <cmath>

class RendererRaylib final : public RendererBase
{
public:
    static RendererBase& getInstance();
public:
    void windowInit(int width, int height, const std::string& str) override;
    void windowClose() override;
    bool windowExists() override;
    bool windowFocused() override;

    int getWidth() const override;
    int getHeight() const override;

    void FPSset(int fps) override;
    void FPSDelay() override;
    int FPSget() override;
    int FPSsetValueGet() override;
    float FPSgetFrameTime() override;

    void drawingBegin() override;
    void drawingEnd() override;

    void clearBackground(const Base::Color& color) override;

    void drawLine(int startX, int startY, int endX, int endY, int thick, const Base::Color& color) override;
    void drawLineAngle(int startX, int startY, float angle, float length, int thick, const Base::Color& color);
    void drawRectangle(int posX, int posY, int width, int height, int thick, const Base::Color& color) override;
    void drawRectangleRound(int posX, int posY, int width, int height, float roundness, int thick, const Base::Color& color) override;
    void drawCircle(int posX, int posY, float innerRadius, float outerRadius, const Base::Color& color) override;

    void drawRectangleFill(int posX, int posY, int width, int height, const Base::Color& color) override;
    void drawRectangleRoundFill(int posX, int posY, int width, int height, float roundness, const Base::Color& color) override;
    void drawCircleFill(int posX, int posY, float radius, const Base::Color& color) override;

    std::shared_ptr<TextureBase> loadTexture(const std::string& path) override;
    void drawTexture(int posX, int posY, float scaleX, float scaleY, const std::shared_ptr<TextureBase>& texture, const Base::Color& color = {255, 255, 255, 255}) override;
    void drawSprite(const Sprite& sprite) override;

    std::shared_ptr<FontBase> loadFont(const std::string& path, int size) override;
    void drawFont(int posX, int posY, int size, const std::string& text, const std::shared_ptr<FontBase>& font, const Base::Color& color = {0, 0, 0, 255}) override;
    void drawText(const Text& text) override;
public:
    RendererRaylib& operator=(const RendererRaylib& renderer) = delete;
    RendererRaylib(const RendererRaylib& renderer) = delete;
private:
    RendererRaylib() = default;
    ~RendererRaylib() = default;
private:
    int FPSmax_ = 0;
};