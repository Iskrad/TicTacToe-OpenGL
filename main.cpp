#include <glfw3.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include "gameBoard.h"
#include "GameStats.h"

const GLint WIDTH = 1280, HEIGHT = 720;

// кути повороту куба
GLfloat angleX = 0.0f; 
GLfloat angleY = 0.0f;

int selectedCubeX = 0;
int selectedCubeY = 0;
int currentPlayer = -1;

void drawBoard();

void resetGameWithDelay(GLFWwindow* window);

void drawCube(float size);

void drawWinCube(int winner);

int checkWin();

bool checkDraw();

GameStats gameStats("stats.txt");

void resetGame();

void boardRotation(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        std::cout << "|| [ESC] Гру завершено! ||" << std::endl;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    
    if (key == GLFW_KEY_UP && action == GLFW_PRESS) { // обробка руху камери вгору, вниз, вліво та вправо
        angleX += 10.0f;
    }
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        angleX -= 10.0f;
    }
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
        angleY -= 10.0f;
    }
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
        angleY += 10.0f;
    }
    
    if (key == GLFW_KEY_W && action == GLFW_PRESS) { // обробка переміщення обраного куба вгору, вниз, вліво та вправо
        selectedCubeY = (selectedCubeY - 1 + 3) % 3;
    }
    else if (key == GLFW_KEY_S && action == GLFW_PRESS) {
        selectedCubeY = (selectedCubeY + 1) % 3;
    }
    else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        selectedCubeX = (selectedCubeX - 1 + 3) % 3;
    }
    else if (key == GLFW_KEY_D && action == GLFW_PRESS) {
        selectedCubeX = (selectedCubeX + 1) % 3;
    }
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS) {     // обробка встановлення крестика або нолика
        if (!cellFilled[selectedCubeX][selectedCubeY]) {
            boardState[selectedCubeX][selectedCubeY] = currentPlayer;
            cellFilled[selectedCubeX][selectedCubeY] = true;
            currentPlayer *= -1;

            if (currentPlayer == 1) {
                std::cout << "[X] Хрестик поставлено!" << std::endl;
            }
            else {
                std::cout << "[O] Нулик поставлено!" << std::endl;
            }
            int winner = checkWin();
            if (winner == 1) {
                std::cout << "|| [O] Нулики перемогли! [O] ||" << std::endl;
                gameStats.incrementBlueWins(); // збільшуємо рахунок перемог нулів
                resetGameWithDelay(window); // Скидання гри з затримкою
            }
            else if (winner == -1) {
                std::cout << "|| [X] Хрестики перемогли! [X] ||" << std::endl;
                gameStats.incrementRedWins(); // крестиків
                resetGameWithDelay(window); 
            }
            if (checkDraw()) {
                std::cout << "|| Нічия! ||" << std::endl;
                gameStats.incrementDraws(); // нічиїх
                resetGameWithDelay(window); 
            }
        }
    }
}

void drawGrid();

void drawScene() {
    drawBoard(); // дошка
    drawGrid(); // кубики
}

void resetGameWithDelay(GLFWwindow* window) {
    drawScene();
    glfwSwapBuffers(window);

    std::this_thread::sleep_for(std::chrono::seconds(1));    // затримка 1 сек

    resetGame(); 
}



int main() {
    if (!glfwInit()) { // Ініціалізація GLFW
        std::cerr << "Помилка при ініціалізації GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Хрестики-Нулики", nullptr, nullptr); 
    if (!window) {
        std::cerr << "Помилка при створенні вікна GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, boardRotation);

    glfwSwapInterval(1); // (30 FPS)

    // основний цикл
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищення буфера кольору та глибини
        glEnable(GL_DEPTH_TEST);

        glMatrixMode(GL_PROJECTION); // встановлення матриці проекції та моделі-виду
        glLoadIdentity();
        float aspect = static_cast<float>(WIDTH) / static_cast<float>(HEIGHT); // обчислення аспектного співвідношення вікна
        glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, 1.0, 100.0);

        glMatrixMode(GL_MODELVIEW); 
        glLoadIdentity();

        glTranslatef(0.0f, 0.0f, -2.0f);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);

        drawScene(); // малюємо сцену
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window); // очищення та завершення програми
    glfwTerminate();
    return 0;
}


