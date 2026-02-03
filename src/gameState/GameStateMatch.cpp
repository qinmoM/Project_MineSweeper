#include "GameStateMatch.h"

GameStateMatch::GameStateMatch(GameStateContext& context)
    : GameStateBase(context), gridView_(nullptr), pos_({ 0.0f, 0.0f }), size_({ 0.0f, 0.0f })
{
    pos_ = { 100.0f, 230.0f };
    size_ = { 1400.0f, 800.0f };
    wait_ = false;
}

void GameStateMatch::enter()
{
    srand(time(nullptr));
    gridView_ = std::make_unique<GridView>(
        context_.configSystem.gameSetting().rows_,
        context_.configSystem.gameSetting().cols_,
        mineCount()
    );

    font_.push_back(
        context_.renderer.loadFont("../res/font/Sniglet/Sniglet-Regular.ttf", fontSize())
    );

    std::shared_ptr<TextureBase> texture = context_.renderer.loadTexture("../res/image/return_ashen.png");
    Sprite sprite(texture);
    sprite.setOrigin({ 500.0f, 500.0f });
    sprite.setScale(Base::Point{ 0.15f, 0.15f });
    Base::Point point{ 100.0f, 100.0f };
    sprite.setPosition(point);
    button_.push_back(std::make_shared<ButtonImage>(
        sprite,
        point,
        [this]() -> void
        {
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
    ));
}

void GameStateMatch::exit()
{
    ;
}

void GameStateMatch::update(float delta)
{
    if (wait_)
        return;

    for (auto& button : button_)
    {
        if (context_.handleInput.mouseClicked(Base::MouseButton::Left) && button->contains(context_.handleInput.mousePosition()))
            context_.stateManager.addTask(button->getCallback());
        
        button->update(context_.handleInput, delta);
    }

    Base::Point mousePos = context_.handleInput.mousePosition() - pos_;
    const MineField& field = gridView_->getField();
    int rows = field.getRows();
    int cols = field.getCols();
    float cellwidth = size_.x / cols;
    float cellheight = size_.y / rows;
    if (context_.handleInput.mouseClicked(Base::MouseButton::Left) && mousePos.x >= 0 && mousePos.x <= size_.x && mousePos.y >= 0 && mousePos.y <= size_.y)
        gridView_->reveal(mousePos.y / cellheight, mousePos.x / cellwidth);

    if (gridView_->isGameOver())
    {
        wait_ = true;
        context_.stateManager.addTask([this]() -> void { context_.stateManager.pushState("Result"); }, 0.1f, 1.5f);
        context_.blackboard.set("GameStateMatch.gameResult", gridView_->isGameWin());
        context_.blackboard.set("GameStateMatch.revealedCount", gridView_->getRevealCount());
        context_.blackboard.set("GameStateMatch.needRevealedCount", gridView_->getField().getRows() * gridView_->getField().getCols() - mineCount());
    }
    if (gridView_->isGameWin())
    {
        wait_ = true;
        context_.stateManager.addTask([this]() -> void { context_.stateManager.pushState("Result"); }, 0.1f);
        context_.blackboard.set("GameStateMatch.gameResult", gridView_->isGameWin());
        context_.blackboard.set("GameStateMatch.revealedCount", gridView_->getRevealCount());
        context_.blackboard.set("GameStateMatch.needRevealedCount", gridView_->getField().getRows() * gridView_->getField().getCols() - mineCount());
    }
}

void GameStateMatch::render()
{
    context_.renderer.drawRectangleFill(0, 0, context_.renderer.getWidth(), context_.renderer.getHeight(), Base::Color{ 230, 230, 230, 255 });

    context_.renderer.drawRectangleRoundFill(pos_.x - 20, pos_.y - 20, size_.x + 40, size_.y + 40, 0.04f, Base::Color{ 140, 180, 190, 255 });
    context_.renderer.drawRectangleFill(pos_.x, pos_.y, size_.x, size_.y, Base::Color{ 255, 255, 255, 255 });

    const MineField& field = gridView_->getField();
    int rows = field.getRows();
    int cols = field.getCols();
    float cellwidth = size_.x / cols;
    float cellheight = size_.y / rows;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (!gridView_->getCell(i, j).isRevealed_)
                context_.renderer.drawRectangleFill(pos_.x + j * cellwidth, pos_.y + i * cellheight, cellwidth, cellheight, Base::Color{ 180, 220, 230, 255 });
            else
            {
                if (gridView_->getCell(i, j).isMine_)
                    context_.renderer.drawRectangleFill(pos_.x + j * cellwidth, pos_.y + i * cellheight, cellwidth, cellheight, Base::Color{ 220, 0, 0, 255 });
                else if (gridView_->getCell(i, j).numMinesNearby_)
                {
                    Text text(font_[0]);
                    text.setText(std::to_string(gridView_->getCell(i, j).numMinesNearby_));
                    text.setSize(fontSize());
                    text.setSpacing(0.0f);
                    Base::Point temp = text.getBounderies();
                    text.setOrigin({ temp.x / 2, temp.y / 2 });
                    text.setColor(fontColor(gridView_->getCell(i, j).numMinesNearby_));
                    text.setPosition({ pos_.x + j * cellwidth + cellwidth / 2, pos_.y + i * cellheight + cellheight / 2 });
                    context_.renderer.drawText(text);
                }
            }
        }
    }

    context_.renderer.drawRectangle(pos_.x, pos_.y, size_.x, size_.y, 2, Base::Color{ 0, 0, 0, 255 });
    for (int i = 1; i < rows; ++i)
        context_.renderer.drawLine(pos_.x, pos_.y + i * cellheight, pos_.x + size_.x, pos_.y + i * cellheight, 2, Base::Color{ 0, 0, 0, 255 });
    for (int i = 1; i < cols; ++i)
        context_.renderer.drawLine(pos_.x + i * cellwidth, pos_.y, pos_.x + i * cellwidth, pos_.y + size_.y, 2, Base::Color{ 0, 0, 0, 255 });

    for (auto& button : button_)
        button->render(context_.renderer);

    context_.renderer.drawFont(600, 80, 56, "Till Beat:     " + std::to_string(rows * cols - mineCount() - gridView_->getRevealCount()), font_[0], Base::Color{ 0, 0, 0, 255 });
}



float GameStateMatch::fontSize() const
{
    if (context_.configSystem.gameSetting().rows_ == 9 && context_.configSystem.gameSetting().cols_ == 15)
        return 56.0f;

    return 56.0f;
}

int GameStateMatch::mineCount() const
{
    if (context_.configSystem.gameSetting().rows_ == 9 && context_.configSystem.gameSetting().cols_ == 15)
        return 20;

    return 10;
}

Base::Color GameStateMatch::fontColor(int num) const
{
    switch (num)
    {
    case 1:
        return Base::Color{ 0, 0, 0, 255 };
    case 2:
        return Base::Color{ 0, 170, 0, 255 };
    case 3:
        return Base::Color{ 0, 170, 190, 255 };
    case 4:
        return Base::Color{ 190, 155, 10, 255 };
    case 5:
        return Base::Color{ 0, 100, 230, 255 };
    case 6:
        return Base::Color{ 205, 0, 205, 255 };
    case 7:
        return Base::Color{ 120, 15, 155, 255 };
    case 8:
        return Base::Color{ 225, 0, 0, 255 };
    }
    return Base::Color{ 0, 0, 0, 255 };
}
