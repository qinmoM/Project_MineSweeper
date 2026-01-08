#pragma once

#include "RendererBase.h"

class RendererProxy final
{
public:
    int FPSget();
    int FPSsetValueGet();

    void clearBackground(const Base::Color& color);

    void drawLine(int startX, int startY, int endX, int endY, int thick, const Base::Color& color);
    void drawLineAngle(int startX, int startY, float angle, float length, int thick, const Base::Color& color);
    void drawRectangle(int posX, int posY, int width, int height, int thick, const Base::Color& color);
    void drawRectangleRound(int posX, int posY, int width, int height, float roundness, int thick, const Base::Color& color);
    void drawCircle(int posX, int posY, float innerRadius, float outerRadius, const Base::Color& color);

    void drawRectangleFill(int posX, int posY, int width, int height, const Base::Color& color);
    void drawRectangleRoundFill(int posX, int posY, int width, int height, float roundness, const Base::Color& color);
    void drawCircleFill(int posX, int posY, float radius, const Base::Color& color);

    std::shared_ptr<TextureBase> loadTexture(const std::string& path);
    void drawTexture(int posX, int posY, float scaleX, float scaleY, const std::shared_ptr<TextureBase>& texture, const Base::Color& color = {255, 255, 255, 255});

    std::shared_ptr<FontBase> loadFont(const std::string& path);
    void drawText(int posX, int posY, int size, const std::string& text, const std::shared_ptr<FontBase>& font, const Base::Color& color = {0, 0, 0, 255});

public:
    RendererProxy(RendererBase& renderer) : renderer_(renderer) { }
    ~RendererProxy() = default;
private:
    RendererBase& renderer_;
};