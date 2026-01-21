#include "GameStateMenu.h"
#include <iostream>

GameStateMenu::GameStateMenu(GameStateContext context)
        : GameStateBase(context)
{
    ;
}

void GameStateMenu::enter()
{
    // textures_.push_back(renderer_->loadTexture("../res/image/pauseOpen_ashen.png"));
    // SetMouseCursor(MOUSE_CURSOR_RESIZE_ALL);
    // IsWindowFocused()
    // std::shared_ptr<EventMouse> event1 = std::make_shared<EventMouse>(
    //     [this]() -> bool
    //     {
    //         return this->handleInput_->mouseDown(Base::MouseButton::Left);
    //     },
    //     nullptr, 1.0f
    // );
    // std::shared_ptr<EventMouse> event2 = std::make_shared<EventMouse>(
    //     [this]() -> bool
    //     {
    //         return handleInput_->mouseReleased(Base::MouseButton::Left);
    //     },
    //     event1, 0.0f
    // );
    // handleInput_->addEvent(event2);
    std::shared_ptr<TextureBase> texture = context_.renderer->loadTexture("../res/image/return_ashen.png");
    Sprite sprite(texture);
    sprite.setScale(Base::Point{0.2f, 0.2f});
    button_.push_back(std::make_shared<ButtonImage>(
        sprite,
        Base::Point{ 100, 100 },
        [this]() -> void
        {
            std::cout << "Button clicked" << std::endl;
        },
        [this](const ButtonBase& button, const Base::Point pos) -> bool
        {
            Base::Point buttonPos = button.getPosition();
            float dx = buttonPos.x - pos.x;
            float dy = buttonPos.y - pos.y;
            return dx * dx + dy * dy <= 100.0f * 100.0f;
        }
    ));
    // ButtonImage button(
    //     sprite,
    //     { 100, 100 },
    //     [this]() -> void
    //     {
    //         context_.stateManager->pushState("Menu");
    //     },
    //     [this](const ButtonBase& button, const Base::Point pos) -> bool
    //     {
    //         Base::Point buttonPos = button.getPosition();
    //         float dx = buttonPos.x - pos.x;
    //         float dy = buttonPos.y - pos.y;
    //         return dx * dx + dy * dy <= 100.0f * 100.0f;
    //     }
    // );
}

void GameStateMenu::exit()
{
    ;
}


void GameStateMenu::update(float delta)
{
    for (auto& button : button_)
        if (context_.handleInput->mouseClicked(Base::MouseButton::Left) && button->contains(context_.handleInput->mousePosition()))
            button->getCallback()();
}

void GameStateMenu::render()
{
    for (auto& button : button_)
        button->render(*context_.renderer);
}
