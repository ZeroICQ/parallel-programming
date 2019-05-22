#include <vector>
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

        case START_VS_HUMAN_CLIENT:
            changeScreen_ = new ClientScreen();
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

    if (!isConnected) {
        printMessages({"waiting for client to connect", (std::string) port_name});
        return;
    }

    switch (key) {
        case 'w':
        case KEY_UP:
            gameBoard_.moveCursorVertical(-1);
            break;

        case 'd':
        case KEY_RIGHT:
            gameBoard_.moveCursorHorizontal(1);
            break;

        case 's':
        case KEY_DOWN:
            gameBoard_.moveCursorVertical(1);
            break;

        case 'a':
        case KEY_LEFT:
            gameBoard_.moveCursorHorizontal(-1);
            break;

        case KEY_ENTER:
        case 10:
            break;

        default:
            break;
    }

    clear();
    gameBoard_.draw();
}

ttt::ServerScreen::ServerScreen() : HumanScreen() {
    currentPlayer_ = static_cast<Player>(rand() % 2);
    MPI_Open_port(MPI_INFO_NULL, port_name);

}

void ttt::HumanScreen::printMessages(const std::vector<std::string> &messages) {
    clear();

    int y, x;
    getmaxyx(stdscr, y, x);
    auto yCenter = y / 2;
    auto xCenter = x / 2;

    size_t maxMessageLength = 0;
    for (auto& message : messages) {
        maxMessageLength = std::max(maxMessageLength, message.length());
    }

    auto yStartDraw = yCenter - messages.size() / 2;
    auto xStartDraw = xCenter - maxMessageLength / 2;

    for (auto& message : messages) {
        mvprintw(yStartDraw, xStartDraw, message.c_str());
        yStartDraw++;
    }

}

void ttt::ClientScreen::handleInput(int key, bool forceDraw) {
    if (key == ERR && !forceDraw)
        return;

    if (!isConnected) {
        printMessages({"Port:", ""});
        echo();
        curs_set(1);
        nocbreak();

        getstr(port_name);

        noecho();
        curs_set(0);
        halfdelay(1);
        return;
    }

    switch (key) {
        case 'w':
        case KEY_UP:
            gameBoard_.moveCursorVertical(-1);
            break;

        case 'd':
        case KEY_RIGHT:
            gameBoard_.moveCursorHorizontal(1);
            break;

        case 's':
        case KEY_DOWN:
            gameBoard_.moveCursorVertical(1);
            break;

        case 'a':
        case KEY_LEFT:
            gameBoard_.moveCursorHorizontal(-1);
            break;

        case KEY_ENTER:
        case 10:
            break;

        default:
            break;
    }

    clear();
    gameBoard_.draw();
}
