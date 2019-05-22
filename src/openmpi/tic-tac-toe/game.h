#pragma once

#include <ncurses.h>
#include <iostream>
#include "screens.h"

namespace ttt {
class Game {
public:
    Game();
    ~Game();

    void tick(int key);
    bool isExit() { return isExit_; }

private:
    bool isExit_ = false;
    BaseScreen
};

} // namespace ttt