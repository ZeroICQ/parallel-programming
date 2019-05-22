#include "game.h"

ttt::Game::Game() : curScreen_(new MainMenuScreen()) {
    initscr();              /* Start curses mode        */
    start_color();
    init_pair(2, COLOR_WHITE, COLOR_GREEN);

    keypad(stdscr, true);
    noecho();
    curs_set(0);
    halfdelay(1);
    clear();
    curScreen_->handleInput(ERR, true);
}

ttt::Game::~Game() {
    endwin();
}

void ttt::Game::tick(int key) {
    //todo: forceDraw on recreating screen
    curScreen_->handleInput(key);
    isExit_ = curScreen_->isRequestExit();
    refresh();
    if (isExit_)
        return;

    if (curScreen_->getChangeScreen() != nullptr) {
        curScreen_.reset(curScreen_->getChangeScreen());
        curScreen_->handleInput(ERR, true);
    }
}
