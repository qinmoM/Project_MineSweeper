#pragma once

struct Cell
{
    short numMinesNearby_;
    bool isMine_;
    bool isRevealed_;
};