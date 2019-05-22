#pragma once

namespace ttt {

enum class GameScreen { MAIN_MENU, GAME };

class BaseScreen {
public:
    bool isRequestExit() const { return isRequestExit_; }

    virtual GameScreen getScreenType() const = 0;

    virtual void handleInput(int key) = 0;

protected:
    bool isRequestExit_ = false;

};

class MainMenuScreen : public BaseScreen {
public:
    GameScreen getScreenType() const override { return GameScreen::MAIN_MENU; }
    void handleInput(int key) override;
};

} //namespace tt