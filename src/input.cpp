#include <iostream>
#include <string>

#include "common.h"
#include "i18n.h"
#include "utility.inl"

// return number of grids to be erased
int inputDifficulty()
{
    cls();

    std::string cmd;
    int need_erase_grids = 0;
    while (true)
    {
        message(I18n::Instance().Get(I18n::Key::ASK_DIFFICULTY));

        std::cin >> cmd;

        try
        {
            Difficulty difficulty = static_cast<Difficulty>(std::stoi(cmd));
            switch (difficulty)
            {
            case Difficulty::EASY:
                need_erase_grids = 20;
                break;
            case Difficulty::NORMAL:
                need_erase_grids = 35;
                break;
            case Difficulty::HARD:
                need_erase_grids = 50;
                break;
            }
        }
        catch(...) 
        {
            need_erase_grids = 0;
        }

        if (need_erase_grids > 0)
            break;

        message(I18n::Instance().Get(I18n::Key::INPUT_ERROR));
    }

    return need_erase_grids;
}

KeyMode inputKeyMode() {
  std::string mode;
  do {
    message(I18n::Instance().Get(I18n::Key::ASK_KEY_MAP));

    std::cin >> mode;

    try {
      KeyMode kmd = static_cast<KeyMode>(std::stoi(mode));
      return kmd;
    } catch (...) {
    }

    message(I18n::Instance().Get(I18n::Key::INPUT_ERROR));
  } while (true);
}

