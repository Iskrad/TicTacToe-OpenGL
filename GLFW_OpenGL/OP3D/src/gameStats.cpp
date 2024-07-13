#include "gameStats.h"

GameStats::GameStats(const std::string& filename) : filename(filename), blueWins(0), redWins(0), draws(0) {
    loadStats(); // завантажуємо статистику з файлу
}

void GameStats::loadStats() {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("BlueWins:") != std::string::npos) {
                blueWins = std::stoi(line.substr(line.find(":") + 1));
            }
            else if (line.find("RedWins:") != std::string::npos) {
                redWins = std::stoi(line.substr(line.find(":") + 1));
            }
            else if (line.find("Draws:") != std::string::npos) {
                draws = std::stoi(line.substr(line.find(":") + 1));
            }
        }
        file.close();
    }
}

void GameStats::saveStats() {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "BlueWins: " << blueWins << std::endl;
        file << "RedWins: " << redWins << std::endl;
        file << "Draws: " << draws << std::endl;
        file.close();
    }
}

void GameStats::incrementBlueWins() {
    blueWins++;
    saveStats(); //зберігання у файлу стати
}

void GameStats::incrementRedWins() {
    redWins++;
    saveStats(); 
}

void GameStats::incrementDraws() {
    draws++;
    saveStats(); 
}
