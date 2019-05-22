#pragma once

#include <ncurses.h>

namespace ttt {

enum class Tag { CROSS, CIRCLE, EMPTY };

class GameBoard {
public:
    GameBoard();
    Tag cells_[3][3];
    void draw();

    // 1=right, -1=left
    void moveCursorHorizontal(int direction);
    // 1=down, -1=up
    void moveCursorVertical(int direction);

private:
    static const auto cellSize_ = 5;
    void getCellTopLeftCorner(int y, int x, int& resy, int& resx);

    int curSelectedX_ = 1;
    int curSelectedY_ = 1;
};


} // namespace ttt
