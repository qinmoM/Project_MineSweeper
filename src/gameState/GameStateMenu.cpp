#include "GameStateMenu.h"
#include <iostream>

GameStateMenu::GameStateMenu(GameStateContext& context)
        : GameStateBase(context)
{
    ;
}

void GameStateMenu::enter()
{
    std::shared_ptr<TextureBase> texture = context_.renderer->loadTexture("../res/image/return_ashen.png");
    Sprite sprite(texture);
    sprite.setOrigin({ 500.0f, 500.0f });
    sprite.setScale(Base::Point{ 0.2f, 0.2f });
    Base::Point point{ 200.0f, 200.0f };
    sprite.setPosition(point);
    button_.push_back(std::make_shared<ButtonImage>(
        sprite,
        point,
        [this]() -> void
        {
            std::cout << "Button clicked" << std::endl;
        },
        [this](const ButtonBase& button, const Base::Point pos) -> bool
        {
            const ButtonImage& buttonImage = static_cast<const ButtonImage&>(button);
            float radius = buttonImage.getSprite().getScale().x / 2 * 1000;
            Base::Point buttonPos = button.getPosition();
            float dx = buttonPos.x - pos.x + radius;
            float dy = buttonPos.y - pos.y + radius;
            return dx * dx + dy * dy <= radius * radius;
        },
        [this](ButtonBase& button, HandleInputSemantic& handle, float delta) -> void
        {
            ButtonImage& buttonImage = static_cast<ButtonImage&>(button);
            Sprite& sprite = buttonImage.getSprite();
            if (button.contains(handle.mousePosition()) && Base::Color{255, 255, 255, 255} == sprite.getColor())
                sprite.setColor(Base::Color{100, 100, 100, 255});
            else if (!button.contains(handle.mousePosition()) && Base::Color{100, 100, 100, 255} == sprite.getColor())
                sprite.setColor(Base::Color{255, 255, 255, 255});

            sprite.setRotation(sprite.getRotation() + delta * 50);
        }
    ));
}

void GameStateMenu::exit()
{
    ;
}


void GameStateMenu::update(float delta)
{
    for (auto& button : button_)
    {
        if (context_.handleInput->mouseClicked(Base::MouseButton::Left) && button->contains(context_.handleInput->mousePosition()))
            context_.stateManager->addTask(button->getCallback());
        
        button->update(*context_.handleInput, delta);
    }
}

void GameStateMenu::render()
{
    for (auto& button : button_)
        button->render(*context_.renderer);
}
