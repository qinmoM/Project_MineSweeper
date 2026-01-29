#pragma once

#include "MineField.h"
#include <ctime>
#include <random>
#include <memory>

class GridView
{
public:
    void regenerateMines(int numMines);
    void reveal(int row, int col);
    bool isGameWin() const;
    bool isGameOver() const;
    int getRevealCount() const;
    const Cell& getCell(int row, int col) const;
    const MineField& getField() const;
public:
    GridView(int rows, int cols, int numMines);
protected:
    std::unique_ptr<MineField> field_;
    int revealCount_ = 0;
    bool gameOver_ = false;
};