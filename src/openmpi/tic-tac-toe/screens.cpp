#include "screens.h"


void ttt::MainMenuScreen::handleInput(int key, bool forceDraw) {
    if (key == ERR && !forceDraw)
        return;

    switch (key) {
        case 'w':
        case KEY_UP:
            retardChoice();
            break;

        case 's':
        case KEY_DOWN:
            advanceChoice();
            break;

        case KEY_ENTER:
        case 10:
            changeScreen();
            break;

        default:
            break;
    }

    draw();
}

void ttt::MainMenuScreen::advanceChoice() {
    int choiceOrder = currChoice_;
    choiceOrder++;
    if (choiceOrder >= MenuChoice::LENGTH)
        choiceOrder = 0;

    currChoice_ = static_cast<MenuChoice>(choiceOrder);
}

void ttt::MainMenuScreen::retardChoice() {
    int choiceOrder = currChoice_;
    choiceOrder--;

    if (choiceOrder < 0)
        choiceOrder = MenuChoice::LENGTH - 1;

    currChoice_ = static_cast<MenuChoice>(choiceOrder);
}

void ttt::MainMenuScreen::draw() {
    clear();

    int y, x;
    getmaxyx(stdscr, y, x);
    auto yCenter = y / 2;
    auto xCenter = x / 2;

    // todo: evaluate once
    size_t maxMenuStringLength = 0;
    for (auto& choicesString : choicesStrings_) {
        maxMenuStringLength = std::max(maxMenuStringLength, choicesString.second.length());
    }

    auto yStartDraw = yCenter - MenuChoice::LENGTH / 2;
    auto xStartDraw = xCenter - maxMenuStringLength / 2;

    int c = 0;
    for (auto& choicesString : choicesStrings_) {

        if (c == currChoice_)
            attron(A_STANDOUT);
        else
            attroff(A_STANDOUT);

        mvprintw(yStartDraw, xStartDraw, choicesString.second.c_str());
        yStartDraw++;
        c++;
    }
}

void ttt::MainMenuScreen::changeScreen() {
    switch (currChoice_) {
        case START_VS_HUMAN_SERVER:
            changeScreen_ = new ServerScreen();
            break;

        case EXIT:
            isRequestExit_ = true;
            break;

        default:
            break;
    }
}

void ttt::ServerScreen::handleInput(int key, bool forceDraw) {
    if (key == ERR && !forceDraw)
        return;

    switch (key) {
        case 'w':
        case KEY_UP:
            gameBoard.moveCursorVertical(-1);
            break;

        case 'd':
        case KEY_RIGHT:
            gameBoard.moveCursorHorizontal(1);
            break;

        case 's':
        case KEY_DOWN:
            gameBoard.moveCursorVertical(1);
            break;

        case 'a':
        case KEY_LEFT:
            gameBoard.moveCursorHorizontal(-1);
            break;

        case KEY_ENTER:
        case 10:
            break;

        default:
            break;
    }

    clear();
    gameBoard.draw();
}

ttt::ServerScreen::ServerScreen() : BaseScreen() {
    currentPlayer_ = static_cast<Player>(rand() % 2);

}
