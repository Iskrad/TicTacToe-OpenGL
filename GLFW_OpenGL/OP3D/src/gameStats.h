#ifndef GAME_STATS_H
#define GAME_STATS_H

#include <string>
#include <fstream>

class GameStats {
private:
    std::string filename; 
    int blueWins; 
    int redWins; 
    int draws; 

public:
    GameStats(const std::string& filename);

    void loadStats(); //для завантаження та збереження статистики
    void saveStats();

    void incrementBlueWins(); //для збільшення кількості перемог синіх, червоних, нічиїх
    void incrementRedWins();
    void incrementDraws();
};

#endif 
