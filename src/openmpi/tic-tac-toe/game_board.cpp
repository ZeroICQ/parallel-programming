#include <algorithm>
#include "game_board.h"

ttt::GameBoard::GameBoard() {
    for (auto y = 0; y < 3; y++)
        for (auto x = 0; x < 3; x++)
            cells_[y][x] = Tag::EMPTY;


}

void ttt::GameBoard::draw() {
    int y, x;
    getmaxyx(stdscr, y, x);
    auto yCenter = y / 2;
    auto xCenter = x / 2;

    auto gameBoardSize = cellSize_ * 3 + 2;
    auto xStartDraw = xCenter - ((cellSize_ / 2) + 1 + cellSize_);
    auto yStartDraw = yCenter - ((cellSize_ / 2) + 1 + cellSize_);


    mvhline(yStartDraw + cellSize_, xStartDraw, '#', gameBoardSize);
    mvhline(yStartDraw + 2 * cellSize_ + 1, xStartDraw, '#', gameBoardSize);

    mvvline(yStartDraw, xStartDraw + cellSize_, '#', gameBoardSize);
    mvvline(yStartDraw, xStartDraw + 2 * cellSize_ + 1, '#', gameBoardSize);

    // highlight selected cell
    int selectedX, selectedY;
    getCellTopLeftCorner(curSelectedY_, curSelectedX_, selectedY, selectedX);


    for (auto line = selectedY; line < selectedY + cellSize_; line++) {
        for (auto col = selectedX; col < selectedX + cellSize_ ; col++) {
            auto charInCell = mvinch(line, col) & A_CHARTEXT;
            mvaddch(line, col, charInCell | COLOR_PAIR(2));
        }
    }

}

void ttt::GameBoard::getCellTopLeftCorner(int cy, int cx, int &resy, int &resx) {
    int y, x;
    getmaxyx(stdscr, y, x);
    auto yCenter = y / 2;
    auto xCenter = x / 2;

    auto xStartDraw = xCenter - ((cellSize_ / 2) + 1 + cellSize_);
    auto yStartDraw = yCenter - ((cellSize_ / 2) + 1 + cellSize_);

    resy = yStartDraw + cy * cellSize_ + cy;
    resx = xStartDraw + cx * cellSize_ + cx;
}

void ttt::GameBoard::moveCursorHorizontal(int direction) {
    curSelectedX_ += direction;
    curSelectedX_ = std::min(curSelectedX_, 2);
    curSelectedX_ = std::max(curSelectedX_, 0);
}

void ttt::GameBoard::moveCursorVertical(int direction) {
    curSelectedY_ += direction;
    curSelectedY_ = std::min(curSelectedY_, 2);
    curSelectedY_ = std::max(curSelectedY_, 0);
}
