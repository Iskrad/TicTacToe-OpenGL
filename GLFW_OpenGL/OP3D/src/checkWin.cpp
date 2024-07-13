#include "checkWin.h"

int checkWin() {
    for (int i = 0; i < 3; ++i) {//по горизонталі
        if (boardState[i][0] != 0 && boardState[i][0] == boardState[i][1] && boardState[i][1] == boardState[i][2]) {
            return boardState[i][0]; // Повертаємо переможця
        }
    }

    for (int j = 0; j < 3; ++j) {// Перевірка по вертикалі
        if (boardState[0][j] != 0 && boardState[0][j] == boardState[1][j] && boardState[1][j] == boardState[2][j]) {
            return boardState[0][j]; 
        }
    }

    // Перевірка по діагоналям
    if (boardState[0][0] != 0 && boardState[0][0] == boardState[1][1] && boardState[1][1] == boardState[2][2]) {
        return boardState[0][0]; 
    }
    if (boardState[0][2] != 0 && boardState[0][2] == boardState[1][1] && boardState[1][1] == boardState[2][0]) {
        return boardState[0][2]; 
    }

    return 0; // немає переможця
}
