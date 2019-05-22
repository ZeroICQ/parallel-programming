#include <ncurses.h>
#include "Game.h"

Game::Game() {
    initscr();			/* Start curses mode 		  */
    printw("Hello World !!!");	/* Print Hello World		  */
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
}

Game::~Game() {
    endwin();
}
