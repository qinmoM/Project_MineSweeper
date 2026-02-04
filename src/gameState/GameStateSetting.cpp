#include "GameStateSetting.h"

GameStateSetting::GameStateSetting(GameStateContext &context) : GameStateBase(context) { }



void GameStateSetting::enter()
{
    // init
    fonts_.push_back(context_.renderer.loadFont("../res/font/Sniglet/Sniglet-Regular.ttf", 72));

    // button
    std::shared_ptr<TextureBase>* temp = context_.blackboard.tryGet<std::shared_ptr<TextureBase>>("button.return_ashen");
    if (!temp)
        throw std::runtime_error("Texture not found in blackboard. | GameStateSetting::enter()");
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
            [this]() -> void { context_.stateManager.popState(); },
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

    Text text1(fonts_[0]);
    text1.setSize(72);
    if (context_.configSystem.gameSetting().rows_ == 6 && context_.configSystem.gameSetting().cols_ == 9)
        text1.setColor(Base::Color{ 150, 150, 150, 255 });
    else
        text1.setColor(Base::Color{ 0, 0, 0, 255 });
    Base::Point point1{ 500.0f, 300.0f };
    text1.setPosition(point1);
    text1.setText("6 x 9");
    text1.setSpacing(0.0f);
    Base::Point text1Boundaries = fonts_[0]->getBoundaries(text1.getText(), text1.getSize(), 0);
    button_.push_back(
        std::make_shared<ButtonText>(
            text1,
            point1,
            [this]() -> void
            {
                context_.configSystem.gameSetting().rows_ = 6;
                context_.configSystem.gameSetting().cols_ = 9;
                static_cast<ButtonText*>(button_[1].get())->getText().setColor(Base::Color{ 150, 150, 150, 255 });
                static_cast<ButtonText*>(button_[2].get())->getText().setColor(Base::Color{ 0, 0, 0, 255 });
                static_cast<ButtonText*>(button_[3].get())->getText().setColor(Base::Color{ 0, 0, 0, 255 });
            },
            [this, text1Boundaries](const ButtonBase& button, const Base::Point pos) -> bool { return button.getPosition() <= pos && pos <= button.getPosition() + text1Boundaries; },
            [this](ButtonBase& button, HandleInputSemantic& handle, float delta) -> void { ; }
        )
    );

    Text text2(fonts_[0]);
    text2.setSize(72);
    if (context_.configSystem.gameSetting().rows_ == 9 && context_.configSystem.gameSetting().cols_ == 15)
        text2.setColor(Base::Color{ 150, 150, 150, 255 });
    else
        text2.setColor(Base::Color{ 0, 0, 0, 255 });
    Base::Point point2{ 800.0f, 300.0f };
    text2.setPosition(point2);
    text2.setText("9 x 15");
    text2.setSpacing(0.0f);
    Base::Point text2Boundaries = fonts_[0]->getBoundaries(text2.getText(), text2.getSize(), 0);
    button_.push_back(
        std::make_shared<ButtonText>(
            text2,
            point2,
            [this]() -> void
            {
                context_.configSystem.gameSetting().rows_ = 9;
                context_.configSystem.gameSetting().cols_ = 15;
                static_cast<ButtonText*>(button_[1].get())->getText().setColor(Base::Color{ 0, 0, 0, 255 });
                static_cast<ButtonText*>(button_[2].get())->getText().setColor(Base::Color{ 150, 150, 150, 255 });
                static_cast<ButtonText*>(button_[3].get())->getText().setColor(Base::Color{ 0, 0, 0, 255 });
            },
            [this, text2Boundaries](const ButtonBase& button, const Base::Point pos) -> bool { return button.getPosition() <= pos && pos <= button.getPosition() + text2Boundaries; },
            [this](ButtonBase& button, HandleInputSemantic& handle, float delta) -> void { ; }
        )
    );

    Text text3(fonts_[0]);
    text3.setSize(72);
    if (context_.configSystem.gameSetting().rows_ == 15 && context_.configSystem.gameSetting().cols_ == 20)
        text3.setColor(Base::Color{ 150, 150, 150, 255 });
    else
        text3.setColor(Base::Color{ 0, 0, 0, 255 });
    Base::Point point3{ 1100.0f, 300.0f };
    text3.setPosition(point3);
    text3.setText("15 x 20");
    text3.setSpacing(0.0f);
    Base::Point text3Boundaries = fonts_[0]->getBoundaries(text3.getText(), text3.getSize(), 0);
    button_.push_back(
        std::make_shared<ButtonText>(
            text3,
            point3,
            [this]() -> void
            {
                context_.configSystem.gameSetting().rows_ = 15;
                context_.configSystem.gameSetting().cols_ = 20;
                static_cast<ButtonText*>(button_[1].get())->getText().setColor(Base::Color{ 0, 0, 0, 255 });
                static_cast<ButtonText*>(button_[2].get())->getText().setColor(Base::Color{ 0, 0, 0, 255 });
                static_cast<ButtonText*>(button_[3].get())->getText().setColor(Base::Color{ 150, 150, 150, 255 });
            },
            [this, text3Boundaries](const ButtonBase& button, const Base::Point pos) -> bool { return button.getPosition() <= pos && pos <= button.getPosition() + text3Boundaries; },
            [this](ButtonBase& button, HandleInputSemantic& handle, float delta) -> void { ; }
        )
    );
}

void GameStateSetting::exit()
{
    ;
}



void GameStateSetting::update(float delta)
{
    for (auto& button : button_)
    {
        if (context_.handleInput.mouseClicked(Base::MouseButton::Left) && button->contains(context_.handleInput.mousePosition()))
            context_.stateManager.addTask(button->getCallback());
        
        button->update(context_.handleInput, delta);
    }
}

void GameStateSetting::render()
{
    context_.renderer.drawRectangleFill(0, 0, context_.renderer.getWidth(), context_.renderer.getHeight(), Base::Color{ 230, 230, 230, 255 });

    context_.renderer.drawFont(200, 300, 72, "Model:", fonts_[0], Base::Color{ 0, 0, 0, 255 });
    // context_.renderer.drawFont(200, 500, 72, "Level:", fonts_[0], Base::Color{ 0, 0, 0, 255 });
    // context_.renderer.drawFont(200, 700, 72, "Theme:", fonts_[0], Base::Color{ 0, 0, 0, 255 });

    // button
    for (auto& button : button_)
        button->render(context_.renderer);
}
