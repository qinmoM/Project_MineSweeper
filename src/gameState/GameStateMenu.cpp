#include "GameStateMenu.h"

GameStateMenu::GameStateMenu(GameStateContext& context)
        : GameStateBase(context)
{
    ;
}

void GameStateMenu::enter()
{
    std::function<bool(const ButtonBase& button, const Base::Point pos)> imageButton_contains_null =
        [](const ButtonBase& button, const Base::Point pos) -> bool { return false; }
    ;
    
    std::function<void(ButtonBase& button, HandleInputSemantic& handle, float delta)> imageButton_update_null =
        [](ButtonBase& button, HandleInputSemantic& handle, float delta) -> void { ; }
    ;

    std::shared_ptr<FontBase> font = context_.renderer.loadFont("../res/font/Flavors/Flavors-Regular.ttf", 250);
    Text text(font);
    text.setText("Mine Sweeper\n                  `");
    text.setSize(250.0f);
    text.setSpacing(-2.0f);
    text.setRotation(-5.0f);
    Base::Point textPos = { 270.0f, 230.0f };
    text.setPosition(textPos);
    button_.push_back(
        std::make_shared<ButtonText>(
            text,
            textPos,
            []() -> void { ; },
            imageButton_contains_null,
            imageButton_update_null
        )
    );

    std::function<bool(const ButtonBase& button, const Base::Point pos)> imageButton_contains_radius150 =
        [this](const ButtonBase& button, const Base::Point pos) -> bool
        {
            float radius = 125.0f;
            Base::Point buttonPos = button.getPosition();
            float dx = buttonPos.x - pos.x;
            float dy = buttonPos.y - pos.y;
            return dx * dx + dy * dy <= radius * radius;
        }
    ;
    std::function<void(ButtonBase& button, HandleInputSemantic& handle, float delta)> imageButton_update_colorExchanged =
        [this](ButtonBase& button, HandleInputSemantic& handle, float delta) -> void
        {
            ButtonImage& buttonImage = static_cast<ButtonImage&>(button);
            Sprite& sprite = buttonImage.getSprite();
            if (button.contains(handle.mousePosition()) && Base::Color{255, 255, 255, 255} == sprite.getColor())
                sprite.setColor(Base::Color{150, 150, 150, 255});
            else if (!button.contains(handle.mousePosition()) && Base::Color{150, 150, 150, 255} == sprite.getColor())
                sprite.setColor(Base::Color{255, 255, 255, 255});
        }
    ;

    std::shared_ptr<TextureBase> texture = context_.renderer.loadTexture("../res/image/return_ashen.png");
    context_.blackboard.set("button.return_ashen", texture);
    Sprite sprite(texture);
    sprite.setOrigin({ 500.0f, 500.0f });
    sprite.setScale(Base::Point{ 0.25f, 0.25f });
    Base::Point point{ 450.0f, 720.0f };
    sprite.setPosition(point);
    button_.push_back(
        std::make_shared<ButtonImage>(
            sprite,
            point,
            [this]() -> void { context_.stateManager.requestQuit(); },
            imageButton_contains_radius150,
            imageButton_update_colorExchanged
        )
    );

    std::shared_ptr<TextureBase> texture2 = context_.renderer.loadTexture("../res/image/pauseOpen_ashen.png");
    Sprite sprite2(texture2);
    sprite2.setOrigin({ 500.0f, 500.0f });
    sprite2.setScale(Base::Point{ 0.25f, 0.25f });
    Base::Point point2{ 800.0f, 720.0f };
    sprite2.setPosition(point2);
    button_.push_back(
        std::make_shared<ButtonImage>(
            sprite2,
            point2,
            [this]() -> void { context_.stateManager.pushState("Match"); },
            imageButton_contains_radius150,
            imageButton_update_colorExchanged
        )
    );

    std::shared_ptr<TextureBase> texture3 = context_.renderer.loadTexture("../res/image/option_ashen.png");
    Sprite sprite3(texture3);
    sprite3.setOrigin({ 500.0f, 500.0f });
    sprite3.setScale(Base::Point{ 0.25f, 0.25f });
    Base::Point point3{ 1150.0f, 720.0f };
    sprite3.setPosition(point3);
    button_.push_back(
        std::make_shared<ButtonImage>(
            sprite3,
            point3,
            [this]() -> void { context_.stateManager.pushState("Setting"); },
            imageButton_contains_radius150,
            imageButton_update_colorExchanged
        )
    );
}

void GameStateMenu::exit()
{
    ;
}


void GameStateMenu::update(float delta)
{
    for (auto& button : button_)
    {
        if (context_.handleInput.mouseClicked(Base::MouseButton::Left) && button->contains(context_.handleInput.mousePosition()))
            context_.stateManager.addTask(button->getCallback());

        button->update(context_.handleInput, delta);
    }
}

void GameStateMenu::render()
{
    for (auto& button : button_)
        button->render(context_.renderer);
}
