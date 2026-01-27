#pragma once

#include "Cell.h"
#include <vector>
#include <stdexcept>

class MineField
{
public:
    MineField(int rows, int cols);
    void flushNearbyNum();
    void reset();
    void setNumMines(int num);
    int getNumMines() const;
    int getRows() const;
    int getCols() const;
    Cell& getCell(int row, int col);
    const Cell& getCell(int row, int col) const;
protected:
    std::vector<std::vector<Cell>> field_;
    int rows_;
    int cols_;
    int mines_;
private:
    int countMines(int row, int col);
};