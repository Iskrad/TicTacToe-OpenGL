#ifndef DRAW_GRID_H
#define DRAW_GRID_H

#include <glfw3.h>
#include "gameBoard.h"
#include "drawCube.h" 
#include "checkDraw.h"
#include "checkWin.h"
#include "drawWinCube.h"

extern int selectedCubeX; 
extern int selectedCubeY; 

void drawGrid();

#endif 
