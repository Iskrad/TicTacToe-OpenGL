#ifndef RESET_GAME_H
#define RESET_GAME_H

#include <vector>
#include "gameBoard.h"
#include "glfw3.h"

extern int currentPlayer; //Оголошення поточного гравця
extern int selectedCubeX; //Оголошення змінної обраного куба за X
extern int selectedCubeY; //Оголошення змінної обраного куба за Y

void resetGame();

#endif 
