#include "board.h"

void drawBoard() {
    glPushMatrix();

    const float boardWidth = 1.2f; 
    const float boardHeight = 1.2f;
    const float boardThickness = 0.2f; 

    glColor3f(0.4f, 0.2f, 0.0f); // темно-коричневий

    glBegin(GL_QUADS);
    // Верхня частина дошки
    glVertex3f(-boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(-boardWidth / 2, boardHeight / 2, 0.0f);

    // Нижня частина дошки
    glVertex3f(-boardWidth / 2, -boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, -boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(-boardWidth / 2, boardHeight / 2, -boardThickness);

    // Ліва частина дошки 
    glVertex3f(-boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(-boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(-boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(-boardWidth / 2, -boardHeight / 2, -boardThickness);

    // Права частина дошки 
    glVertex3f(boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, -boardHeight / 2, -boardThickness);

    // Верхня частина дошки 
    glVertex3f(-boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, -boardHeight / 2, -boardThickness);
    glVertex3f(-boardWidth / 2, -boardHeight / 2, -boardThickness);

    // Нижня частина дошки 
    glVertex3f(-boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(-boardWidth / 2, boardHeight / 2, -boardThickness);

    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // тонкі білі грані
    glBegin(GL_LINES);
    // Верхня грань
    glVertex3f(-boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(-boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(-boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(-boardWidth / 2, -boardHeight / 2, 0.0f);

    // Нижня грань
    glVertex3f(-boardWidth / 2, -boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, -boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, -boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(-boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(-boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(-boardWidth / 2, -boardHeight / 2, -boardThickness);

    // Бокові грані
    glVertex3f(-boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(-boardWidth / 2, -boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, -boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, -boardHeight / 2, -boardThickness);
    glVertex3f(boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(boardWidth / 2, boardHeight / 2, -boardThickness);
    glVertex3f(-boardWidth / 2, boardHeight / 2, 0.0f);
    glVertex3f(-boardWidth / 2, boardHeight / 2, -boardThickness);

    glEnd();

    glPopMatrix(); 
}
