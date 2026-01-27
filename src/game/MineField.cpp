#include "MineField.h"

MineField::MineField(int rows, int cols) : rows_(rows), cols_(cols), mines_(0)
{
    field_ = std::vector<std::vector<Cell>>(rows + 2, std::vector<Cell>(cols + 2, Cell{ 0, false, false }));
}

void MineField::flushNearbyNum()
{
    for (int i = 1; i < rows_ - 1; ++i)
    {
        for (int j = 1; j < cols_ - 1; ++j)
            field_[i][j].numMinesNearby_ = countMines(i, j);
    }
}

void MineField::reset()
{
    for (int i = 1; i < rows_ - 1; ++i)
    {
        for (int j = 1; j < cols_ - 1; ++j)
        {
            field_[i][j].isMine_ = false;
            field_[i][j].isRevealed_ = false;
            field_[i][j].numMinesNearby_ = 0;
        }
    }
}

void MineField::setNumMines(int num)
{
    mines_ = num;
}

int MineField::getNumMines() const
{
    return mines_;
}

int MineField::getRows() const
{
    return rows_;
}

int MineField::getCols() const
{
    return cols_;
}

Cell& MineField::getCell(int row, int col)
{
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
        throw std::out_of_range("Cell index out of range. | MineField::getCell");

    return field_[row + 1][col + 1];
}

const Cell& MineField::getCell(int row, int col) const
{
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
        throw std::out_of_range("Cell index out of range. | MineField::getCell const");

    return field_[row + 1][col + 1];
}

int MineField::countMines(int row, int col)
{
    return field_[row - 1][col - 1].isMine_
         + field_[row - 1][col    ].isMine_
         + field_[row - 1][col + 1].isMine_
         + field_[row    ][col - 1].isMine_
         + field_[row    ][col + 1].isMine_
         + field_[row + 1][col - 1].isMine_
         + field_[row + 1][col    ].isMine_
         + field_[row + 1][col + 1].isMine_;
}