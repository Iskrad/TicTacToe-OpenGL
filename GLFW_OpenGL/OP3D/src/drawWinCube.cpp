#include "drawWinCube.h"

void drawWinCube(int winner) {
    glPushMatrix();

    if (winner == -1) {
        glColor3f(0.5f, 0.0f, 0.0f); // Темно червоний колір для хрестика
    }
    else if (winner == 1) {
        glColor3f(0.0f, 0.0f, 0.5f); // Темно синій колір для нолика
    }
    else {
        glColor3f(0.3f, 0.3f, 0.3f); // Темно сірий колір для нічиєї
    }

    glScalef(2.0f, 2.0f, 2.0f); // збільшую розмір куба
    drawCube(10.0f); // куб розміром 10.0f

    glPopMatrix(); 
}
