#pragma once

#include "raylib.h"
#include "RendererBase.h"
#include "TextureRaylib.h"
#include "FontRaylib.h"
#include <cmath>

class RendererRaylib : public RendererBase
{
public:
    static RendererBase& getInstance();
public:
    virtual void windowInit(int width, int height, const std::string& str) override;
    virtual void windowClose() override;
    virtual bool windowExists() override;

    virtual void FPSset(int fps) override;
    virtual void FPSDelay() override;
    virtual int FPSget() override;
    virtual int FPSsetValueGet() override;
    virtual float FPSgetFrameTime() override;

    virtual void drawingBegin() override;
    virtual void drawingEnd() override;

    virtual void clearBackground(const Base::ColorBase& color) override;

    virtual void drawLine(int startX, int startY, int endX, int endY, int thick, const Base::ColorBase& color) override;
    virtual void drawLineAngle(int startX, int startY, float angle, float length, int thick, const Base::ColorBase& color);
    virtual void drawRectangle(int posX, int posY, int width, int height, int thick, const Base::ColorBase& color) override;
    virtual void drawRectangleRound(int posX, int posY, int width, int height, float roundness, int thick, const Base::ColorBase& color) override;
    virtual void drawCircle(int posX, int posY, float innerRadius, float outerRadius, const Base::ColorBase& color) override;

    virtual void drawRectangleFill(int posX, int posY, int width, int height, const Base::ColorBase& color) override;
    virtual void drawRectangleRoundFill(int posX, int posY, int width, int height, float roundness, const Base::ColorBase& color) override;
    virtual void drawCircleFill(int posX, int posY, float radius, const Base::ColorBase& color) override;

    virtual std::shared_ptr<TextureBase> loadTexture(const std::string& path) override;
    virtual void drawTexture(int posX, int posY, float scaleX, float scaleY, const std::shared_ptr<TextureBase>& texture, const Base::ColorBase& color = {255, 255, 255, 255}) override;

    virtual std::shared_ptr<FontBase> loadFont(const std::string& path) override;
    virtual void drawText(int posX, int posY, int size, const std::string& text, const std::shared_ptr<FontBase>& font, const Base::ColorBase& color) override;
public:
    RendererRaylib& operator=(const RendererRaylib& renderer) = delete;
    RendererRaylib(const RendererRaylib& renderer) = delete;
private:
    RendererRaylib() = default;
    ~RendererRaylib() = default;
private:
    int FPSmax_ = 0;
};