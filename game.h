#ifndef GAME_H
#define GAME_H

#include <vector>

class Game
{
public:
    Game();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void restartGame();
    bool gameOver();
    bool gameWin();
    int  getSize();
    int  getCell(int i, int j);
    int  getScore();
    int  getHighScore();

private:
    std::vector< std::vector<int> > array;
    int size;
    int score;
    int high_score;
    void generate();
    void setHighScore();
    void addScore(int _score);
};

#endif // GAME_H
