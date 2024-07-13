#include "gameBoard.h"

//ініціалізація порожньої ігрової дошки
std::vector<std::vector<int>> boardState(3, std::vector<int>(3, 0));

//ініціалізація прапорів, що позначають заповненість комірок
std::vector<std::vector<bool>> cellFilled(3, std::vector<bool>(3, false));
