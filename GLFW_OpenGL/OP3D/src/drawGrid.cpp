#include "drawGrid.h"

void drawGrid() {
    glPushMatrix();

    // Розмір і кількість кубиків у сітці
    const int gridSize = 3;
    const float cubeSize = 0.3f;
    const float spacing = 0.1f; // відступи між кубиками


    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            glPushMatrix(); 
            glTranslatef((i - 1) * (cubeSize + spacing), (1 - j) * (cubeSize + spacing), cubeSize / 2); 

            // червоний або синій куб в залежності від стану клітинки
            if (cellFilled[i][j]) {
                glTranslatef(0.0f, 0.0f, cubeSize / 150); //піднімаю куб над дошкою
                if (boardState[i][j] == -1) {
                    glColor3f(1.0f, 0.0f, 0.0f); // Червоний колір для хрестика
                }
                else if (boardState[i][j] == 1) {
                    glColor3f(0.0f, 0.0f, 1.0f); 
                }
                drawCube(cubeSize * 0.7f); // зменьшую розмір куба на 30%
            }
            else {
                if (i == selectedCubeX && j == selectedCubeY) { //перевірк - чи вибраний поточний кубик
                    // колір контуру на зелений
                    glColor3f(0.0f, 1.0f, 0.0f);
                }
                else {
                    glColor3f(1.0f, 1.0f, 1.0f);      // в іншому випадку залишаємо білий колір контуру
                }

                //контур куба
                glBegin(GL_LINE_LOOP);
                glVertex3f(-cubeSize / 2, -cubeSize / 2, -cubeSize / 2);
                glVertex3f(cubeSize / 2, -cubeSize / 2, -cubeSize / 2);
                glVertex3f(cubeSize / 2, cubeSize / 2, -cubeSize / 2);
                glVertex3f(-cubeSize / 2, cubeSize / 2, -cubeSize / 2);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glVertex3f(-cubeSize / 2, -cubeSize / 2, cubeSize / 2);
                glVertex3f(-cubeSize / 2, cubeSize / 2, cubeSize / 2);
                glVertex3f(cubeSize / 2, cubeSize / 2, cubeSize / 2);
                glVertex3f(cubeSize / 2, -cubeSize / 2, cubeSize / 2);
                glEnd();
                glBegin(GL_LINES);
                glVertex3f(-cubeSize / 2, -cubeSize / 2, -cubeSize / 2);
                glVertex3f(-cubeSize / 2, -cubeSize / 2, cubeSize / 2);
                glVertex3f(cubeSize / 2, -cubeSize / 2, -cubeSize / 2);
                glVertex3f(cubeSize / 2, -cubeSize / 2, cubeSize / 2);
                glVertex3f(cubeSize / 2, cubeSize / 2, -cubeSize / 2);
                glVertex3f(cubeSize / 2, cubeSize / 2, cubeSize / 2);
                glVertex3f(-cubeSize / 2, cubeSize / 2, -cubeSize / 2);
                glVertex3f(-cubeSize / 2, cubeSize / 2, cubeSize / 2);
                glEnd();
            }

            //біла сітка  
            glColor3f(1.0f, 1.0f, 1.0f); // білий колір для сітки
            if (i == selectedCubeX && j == selectedCubeY) {
                glColor3f(0.0f, 1.0f, 0.0f); // якщо вибраний, змінюємо колір контуру на зелений
            }
            glBegin(GL_LINES);
            glVertex3f(-cubeSize / 2, -cubeSize / 2, -cubeSize / 2);
            glVertex3f(cubeSize / 2, -cubeSize / 2, -cubeSize / 2);
            glVertex3f(cubeSize / 2, -cubeSize / 2, -cubeSize / 2);
            glVertex3f(cubeSize / 2, cubeSize / 2, -cubeSize / 2);
            glVertex3f(cubeSize / 2, cubeSize / 2, -cubeSize / 2);
            glVertex3f(-cubeSize / 2, cubeSize / 2, -cubeSize / 2);
            glVertex3f(-cubeSize / 2, cubeSize / 2, -cubeSize / 2);
            glVertex3f(-cubeSize / 2, -cubeSize / 2, -cubeSize / 2);
            glEnd();

            glPopMatrix(); 
        }
    }
    glPopMatrix(); 
    int winner = checkWin(); 
    bool isDraw = checkDraw(); 

    if (winner != 0 || isDraw) {
        drawWinCube(winner); // великий куб - перемоги чи нічиєї
        return; 
    }
}

