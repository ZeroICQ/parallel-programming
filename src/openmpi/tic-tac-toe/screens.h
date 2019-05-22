#pragma once

#include <ncurses.h>
#include <map>

namespace ttt {

enum class GameScreen { MAIN_MENU, GAME };

class BaseScreen {
public:
    bool isRequestExit() const { return isRequestExit_; }
    virtual GameScreen getScreenType() const = 0;
    virtual void handleInput(int key, bool forceDraw = false) = 0;

protected:
    bool isRequestExit_ = false;

};

class MainMenuScreen : public BaseScreen {
public:
    enum MenuChoice { START_VS_BOT, EXIT, LENGTH };

    GameScreen getScreenType() const override { return GameScreen::MAIN_MENU; }
    void handleInput(int key, bool forceDraw) override;

private:
    std::map<MenuChoice, std::string> choicesStrings_ {
        {START_VS_BOT, "Versus B0t"},
        {EXIT, "Exit"}
    };

    MenuChoice currChoice_ = static_cast<MenuChoice>(0);

    void draw();
    void advanceChoice();
    void retardChoice();


};

} //namespace tt