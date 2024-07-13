#include "gameBoard.h" 

bool checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!cellFilled[i][j]) {
                return false; // знайдена порожня клітинка, гру не закінчено
            }
        }
    }
    return true; // усі клітинки заповнені, нічия
}
