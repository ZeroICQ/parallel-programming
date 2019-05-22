#include "game.h"

ttt::Game::Game() : curScreen_(new MainMenuScreen()) {
    initscr();              /* Start curses mode        */
    keypad(stdscr, true);
    noecho();
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
}
