#pragma once

#include "Base.h"
#include "TextureBase.h"
#include "SpriteBase.h"
#include <string>
#include <memory>

class RendererBase
{
public:
    /// @brief create a rendering window
    /// @param str label name of the window
    virtual void windowInit(int width, int height, const std::string& str) = 0;
    /// @brief close this window
    virtual void windowClose() = 0;
    /// @brief draw API can be used if return true
    /// @return true if the window exists
    virtual bool windowExists() = 0;


    /// @brief set the maximum FPS limit
    /// @param fps maximum FPS limit
    /// @note value 0 mean no limit
    virtual void FPSset(int fps) = 0;
    /// @brief under the current FPS limit, wait until the next loop is executed
    virtual void FPSDelay() = 0;
    /// @brief get current FPS
    virtual int FPSget() = 0;
    /// @brief get the maximum FPS limit
    virtual int FPSsetValueGet() = 0;
    /// @brief get the time elapsed since the last frame
    /// @return now to last frame time in seconds
    virtual float FPSgetFrameTime() = 0;


    /// @brief enable the drawing buffer
    virtual void drawingBegin() = 0;
    /// @brief draw and clear the drawing buffer
    virtual void drawingEnd() = 0;


    /// @brief clear background with color
    virtual void clearBackground(const Base::ColorBase& color) = 0;


    /// @brief draw a line with color
    /// @param thick the thickness of the line
    virtual void drawLine(int startX, int startY, int endX, int endY, int thick, const Base::ColorBase& color) = 0;
    /// @brief draw a line from the angle of the starting coordinate
    /// @param angle the same as the rectangular coordinate system
    /// @param length the length of the line
    /// @param thick the thickness of the line
    virtual void drawLineAngle(int startX, int startY, float angle, float length, int thick, const Base::ColorBase& color) = 0;
    /// @brief draw a rectanglular border
    /// @param posX the X-coordinate position in the upper left corner
    /// @param posY the Y-coordinate position in the upper left corner
    /// @param width the width of rectangle
    /// @param height the heigth of rectangle
    /// @param thick the thickness of the border
    virtual void drawRectangle(int posX, int posY, int width, int height, int thick, const Base::ColorBase& color) = 0;
    /// @brief draw a rectangle border with rounded edges
    /// @param posX the X-coordinate position in the upper left corner
    /// @param posY the Y-coordinate position in the upper left corner
    /// @param width the width of rectangle with rounded edges
    /// @param height the heigth of rectangle with rounded edges
    /// @param roundness the ratio of the rounded corner radius to the length of the shorter side of the rectangle
    /// @param thick the thickness of the border
    virtual void drawRectangleRound(int posX, int posY, int width, int height, float roundness, int thick, const Base::ColorBase& color) = 0;
    /// @brief draw a ring
    /// @param posX the X-coordinate of the center of circle
    /// @param posY theY-coordinate of the center of circle
    /// @param innerRadius inner circle raidus
    /// @param outerRadius outer circle raidus
    virtual void drawCircle(int posX, int posY, float innerRadius, float outerRadius, const Base::ColorBase& color) = 0;


    /// @brief draw a color_filled rectangle
    /// @param posX the X-coordinate position in the upper left corner
    /// @param posY the Y-coordinate position in the upper left corner
    /// @param width the width of rectangle
    /// @param height the heigth of rectangle
    virtual void drawRectangleFill(int posX, int posY, int width, int height, const Base::ColorBase& color) = 0;
    /// @brief draw a color_filled rectangle with rounded edges
    /// @param posX the X-coordinate position in the upper left corner
    /// @param posY the Y-coordinate position in the upper left corner
    /// @param width the width of rectangle
    /// @param height the heigth of rectangle
    /// @param roundness the ratio of the rounded corner radius to the length of the shorter side of the rectangle
    virtual void drawRectangleRoundFill(int posX, int posY, int width, int height, float roundness, const Base::ColorBase& color) = 0;
    /// @brief draw a color_filled circle
    /// @param posX the X-coordinate of the center of circle
    /// @param posY theY-coordinate of the center of circle
    /// @param radius the radius of the circle
    virtual void drawCircleFill(int posX, int posY, float radius, const Base::ColorBase& color) = 0;

    /// @brief load a texture from path
    /// @param path image file path
    /// @return a texture object shared pointer
    virtual std::shared_ptr<TextureBase> loadTexture(const std::string& path) = 0;

public:
    virtual ~RendererBase() = default;

public:
    struct TextureToken
    {
    private:
        explicit TextureToken() = default;
        friend class RendererBase;
    };

protected:
    TextureToken getTextureToken();
};