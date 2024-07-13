#include "resetGame.h"

void resetGame() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            boardState[i][j] = 0;
            cellFilled[i][j] = false;
        }
    }
    currentPlayer = -1;
    selectedCubeX = 0;
    selectedCubeY = 0;
}
