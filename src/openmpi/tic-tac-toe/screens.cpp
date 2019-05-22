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
