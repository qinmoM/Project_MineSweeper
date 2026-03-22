#include "GameStateHelp.h"

GameStateHelp::GameStateHelp(GameStateContext &context, const std::string& stateName)
    : GameStateBase(context, stateName)
{ }



void GameStateHelp::enter()
{
    // init
    fonts_.push_back(context_.renderer.loadFont("../res/font/Sniglet/Sniglet-Regular.ttf", 72));

    // button
    std::shared_ptr<TextureBase>* temp = context_.blackboard.tryGet<std::shared_ptr<TextureBase>>("button.return_ashen");
    if (!temp)
        throw std::runtime_error("Texture not found in blackboard. | GameStateHelp::enter()");
    std::shared_ptr<TextureBase> texture = *temp;
    Sprite sprite(texture);
    sprite.setOrigin({ 500.0f, 500.0f });
    sprite.setScale(Base::Point{ 0.15f, 0.15f });
    Base::Point point{ 100.0f, 100.0f };
    sprite.setPosition(point);
    button_.push_back(
        std::make_shared<ButtonImage>(
            sprite,
            point,
            [this]() -> void
            {
                context_.audio.playSFX("Button");
                context_.stateManager.popState();
            },
            [this](const ButtonBase& button, const Base::Point pos) -> bool
            {
                const ButtonImage& buttonImage = static_cast<const ButtonImage&>(button);
                float radius = buttonImage.getSprite().getScale().x / 2 * 1000;
                Base::Point buttonPos = button.getPosition();
                float dx = buttonPos.x - pos.x;
                float dy = buttonPos.y - pos.y;
                return dx * dx + dy * dy <= radius * radius;
            },
            [this](ButtonBase& button, HandleInputSemantic& handle, float delta) -> void
            {
                ButtonImage& buttonImage = static_cast<ButtonImage&>(button);
                Sprite& sprite = buttonImage.getSprite();
                if (button.contains(handle.mousePosition()) && Base::Color{255, 255, 255, 255} == sprite.getColor())
                    sprite.setColor(Base::Color{150, 150, 150, 255});
                else if (!button.contains(handle.mousePosition()) && Base::Color{150, 150, 150, 255} == sprite.getColor())
                    sprite.setColor(Base::Color{255, 255, 255, 255});
            }
        )
    );
}

void GameStateHelp::exit()
{
    ;
}



void GameStateHelp::update(float delta)
{
    for (auto& button : button_)
    {
        if (context_.handleInput.mouseClicked(Base::MouseButton::Left) && button->contains(context_.handleInput.mousePosition()))
            context_.stateManager.addTask(button->getCallback());
        
        button->update(context_.handleInput, delta);
    }
}

void GameStateHelp::render()
{
    // background
    context_.renderer.drawRectangleFill(0, 0, context_.renderer.getWidth(), context_.renderer.getHeight(), Base::Color{ 230, 230, 230, 255 });

    // text
    context_.renderer.drawFont(200, 300, 56, "github:   https://github.com/qinmoM/Project_MineSweeper", fonts_[0], Base::Color{ 0, 0, 0, 255 });
    context_.renderer.drawFont(200, 430, 56, "author:   qinmoM", fonts_[0], Base::Color{ 0, 0, 0, 255 });
    context_.renderer.drawFont(200, 560, 56, "e-mail:   qinmo666@outlook.com", fonts_[0], Base::Color{ 0, 0, 0, 255 });
    context_.renderer.drawFont(200, 690, 56, "license:   MIT License Copyright (c) 2026 qinmoM", fonts_[0], Base::Color{ 0, 0, 0, 255 });

    // button
    for (auto& button : button_)
        button->render(context_.renderer);
}
