#include "game.h"

ttt::Game::Game() {
    initscr();			/* Start curses mode 		  */
    keypad(stdscr, true);
    noecho();
    halfdelay(1);
//    todo: remove
    MainMenuScreen mm;


}

ttt::Game::~Game() {
    endwin();
}

void ttt::Game::tick(int key) {

}
