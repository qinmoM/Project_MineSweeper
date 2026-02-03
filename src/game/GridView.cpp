#include "GridView.h"

GridView::GridView(int rows, int cols, int numMines)
{
    if (rows * cols <= numMines)
        throw std::invalid_argument("Too many mines for grid size. | GridView::GridView");

    field_ = std::make_unique<MineField>(rows, cols);
    regenerateMines(numMines);
}

void GridView::regenerateMines(int numMines)
{
    field_->reset();
    field_->setNumMines(numMines);
    for (int i = 0; i < field_->getNumMines(); )
    {
        int index = rand() % (field_->getRows() * field_->getCols());
        int row = index / field_->getCols();
        int col = index % field_->getCols();
        if (!field_->getCell(row, col).isMine_)
        {
            field_->getCell(row, col).isMine_ = true;
            ++i;
        }
    }
    field_->flushNearbyNum();
}

void GridView::reveal(int row, int col)
{
    if (row < 0 || row >= field_->getRows() || col < 0 || col >= field_->getCols() || field_->getCell(row, col).isRevealed_ || gameOver_)
        return;

    field_->getCell(row, col).isRevealed_ = true;

    if (field_->getCell(row, col).isMine_)
    {
        gameOver_ = true;
        return;
    }

    revealCount_ += 1;

    if (0 == field_->getCell(row, col).numMinesNearby_)
    {
        reveal(row - 1, col - 1);
        reveal(row - 1, col);
        reveal(row - 1, col + 1);
        reveal(row, col - 1);
        reveal(row, col + 1);
        reveal(row + 1, col - 1);
        reveal(row + 1, col);
        reveal(row + 1, col + 1);
    }
}

bool GridView::isGameWin() const
{
    return !gameOver_ && field_->getRows() * field_->getCols() - field_->getNumMines() == revealCount_;
}

bool GridView::isGameOver() const
{
    return gameOver_;
}

int GridView::getRevealCount() const
{
    return revealCount_;
}

const Cell& GridView::getCell(int row, int col) const
{
    return field_->getCell(row, col);
}

const MineField& GridView::getField() const
{
    return *field_;
}