#pragma once

#include <ncurses.h>
#include <map>
#include "game_board.h"

namespace ttt {

enum class GameScreen { MAIN_MENU, GAME_SERVER, GAME_CLIENT, GAME_BOT };

class BaseScreen {
public:
    bool isRequestExit() const { return isRequestExit_; }
    // nullable
    BaseScreen* getChangeScreen() const { return changeScreen_; }

    virtual GameScreen getScreenType() const = 0;
    virtual void handleInput(int key, bool forceDraw = false) = 0;

protected:
    bool isRequestExit_ = false;
    BaseScreen* changeScreen_ = nullptr;
};

class MainMenuScreen : public BaseScreen {
public:
    enum MenuChoice {
        START_VS_HUMAN_SERVER,
        START_VS_HUMAN_CLIENT,
        START_VS_BOT,
        EXIT,
        LENGTH
    };

    GameScreen getScreenType() const override { return GameScreen::MAIN_MENU; }
    void handleInput(int key, bool forceDraw) override;

private:
    std::map<MenuChoice, std::string> choicesStrings_ {
        {START_VS_HUMAN_SERVER, "Start server"},
        {START_VS_HUMAN_CLIENT, "Connect to server"},
        {START_VS_BOT, "Versus B0t"},
        {EXIT, "Exit"}
    };

    MenuChoice currChoice_ = static_cast<MenuChoice>(0);

    void draw();
    void advanceChoice();
    void retardChoice();
    void changeScreen();
};


enum class Player { PLAYER_SERVER, PLAYER_CLIENT, PLAYER_BOT};

class ServerScreen : public BaseScreen {
public:
    ServerScreen();
    GameScreen getScreenType() const override { return GameScreen::GAME_SERVER; }

    void handleInput(int key, bool forceDraw) override;

private:
    GameBoard gameBoard;
    Player currentPlayer_;

};

} //namespace tt