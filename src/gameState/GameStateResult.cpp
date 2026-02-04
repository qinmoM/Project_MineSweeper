#include "GameStateResult.h"

GameStateResult::GameStateResult(GameStateContext& context)
    : GameStateBase(context)
{
    bool* result = context_.blackboard.tryGet<bool>("GameStateMatch.gameResult");
    if (result)
        isGameWin_ = *result;
    else
        isGameWin_ = false;

    int* reveal = context_.blackboard.tryGet<int>("GameStateMatch.revealedCount");
    if (reveal)
        revealCount_ = *reveal;
    else
        revealCount_ = 0;

    int* needReveal = context_.blackboard.tryGet<int>("GameStateMatch.needRevealedCount");
    if (needReveal)
        needRevealCount_ = *needReveal;
    else
        needRevealCount_ = 1;

    context_.blackboard.remove("GameStateMatch.gameResult");
    context_.blackboard.remove("GameStateMatch.revealedCount");
    context_.blackboard.remove("GameStateMatch.needRevealedCount");
}

void GameStateResult::enter()
{
    width_ = context_.renderer.getWidth() * 0.65f;
    height_ = context_.renderer.getHeight() * 0.65f;

    std::function<bool(const ButtonBase& button, const Base::Point pos)> imageButton_contains =
        [this](const ButtonBase& button, const Base::Point pos) -> bool
        {
            float radius = 85.0f;
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

    std::shared_ptr<TextureBase>* temp = context_.blackboard.tryGet<std::shared_ptr<TextureBase>>("button.return_ashen");
    if (!temp)
        throw std::runtime_error("Texture not found in blackboard. | GameStateResult::enter()");
    std::shared_ptr<TextureBase> texture = *temp;
    Sprite sprite(texture);
    sprite.setOrigin({ 500.0f, 500.0f });
    sprite.setScale(Base::Point{ 0.17f, 0.17f });
    Base::Point point{ 800.0f, 720.0f };
    sprite.setPosition(point);
    button_.push_back(
        std::make_shared<ButtonImage>(
            sprite,
            point,
            [this]() -> void {
                GameStateManager& context = context_.stateManager;
                context.popState();
                context.popState();
            },
            imageButton_contains,
            imageButton_update_colorExchanged
        )
    );

    fonts_.push_back(context_.renderer.loadFont("../res/font/Sniglet/Sniglet-Regular.ttf", 112));
}

void GameStateResult::exit()
{
    ;
}



void GameStateResult::update(float delta)
{
    for (auto& button : button_)
    {
        if (context_.handleInput.mouseClicked(Base::MouseButton::Left) && button->contains(context_.handleInput.mousePosition()))
            context_.stateManager.addTask(button->getCallback());

        button->update(context_.handleInput, delta);
    }
}

void GameStateResult::render()
{
    context_.renderer.drawRectangleFill(0, 0, context_.renderer.getWidth(), context_.renderer.getHeight(), Base::Color{ 105, 105, 105, 180 });

    context_.renderer.drawRectangleRoundFill((context_.renderer.getWidth() - width_) / 2, (context_.renderer.getHeight() - height_) / 2, width_, height_, 0.07f, Base::Color{ 210, 210, 210, 255 });
    context_.renderer.drawRectangleRound((context_.renderer.getWidth() - width_) / 2, (context_.renderer.getHeight() - height_) / 2, width_, height_, 0.07f, 4, Base::Color{ 40, 40, 40, 155 });

    for (auto& button : button_)
        button->render(context_.renderer);

    std::string text;
    if (isGameWin_)
        text = "Win!";
    else
        text = "Lose!";
    std::string text2 = "Completion Rate:   " + std::to_string(revealCount_ * 100 / needRevealCount_) + "%";
    context_.renderer.drawFont(710, 290, 112, text, fonts_[0], Base::Color{ 0, 0, 0, 255 });
    context_.renderer.drawFont(570, 450, 56, text2, fonts_[0], Base::Color{ 30, 30, 30, 255 });
}
