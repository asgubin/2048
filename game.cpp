#include <cstdlib>
#include <time.h>

#include "game.h"

Game::Game()
{
    size = 4;

    for (int i = 0; i < size; i++) {
        std::vector<int> temp;

        for (int j = 0; j < size; j++)
            temp.push_back(0);

        array.push_back(temp);
    }

    score = 0;
    high_score = 0;

    generate();
    generate();
}

void Game::restartGame()
{
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++)
            array[i][j] = 0;
    }

        score = 0;

        generate();
        generate();
}

void Game::generate()
{
    srand((unsigned)time(NULL));

     int x = rand() % size;
     int y = rand() % size;

     while(array[x][y] != 0) {
         x = rand() % size;
         y = rand() % size;
     }

     array[x][y] = 2;
}

int Game::getSize()
{
    return size;
}

int Game::getCell(int i, int j)
{
    return array[i][j];
}

void Game::moveUp()
{
    bool move_event = false;

    for (int k = 0; k < size; k++) {

        for (int i = 0; i < size; i++) {

            //Если текущий эл-т равен 0
            if (array[i][k] == 0) {

                //найдем первый не 0 эл-т
                for (int j = i + 1; j < size; j++) {

                    //если не 0 эл-т есть
                    if (array[j][k] != 0) {

                        //меняем местами с текущим
                        array[i][k] = array [j][k];
                        array[j][k] = 0;
                        move_event = true;

                        //и продолжаем поиск следующего не 0 эл-та
                        for (int m = j + 1; m < size; m++) {

                            //если такой эт-т есть
                            if (array[m][k] != 0) {

                                //и он равен текущему
                                if (array[i][k] == array[m][k]) {
                                    array[i][k] *= 2;
                                    addScore(array[i][k]);
                                    array[m][k] = 0;
                                }

                                break;
                            }
                        }

                        break;
                    }

                }
            }
            //Если текущий элемент не равен нулю
            else {

                //найдем первый не 0
                for (int j = i + 1; j < size; j++) {

                    if (array[j][k] != 0) {

                        if (array[i][k] == array[j][k]) {
                            array[i][k] *= 2;
                            addScore(array[i][k]);
                            array[j][k] = 0;
                            move_event = true;
                        }

                        break;
                    }
                }
            }
        }
    }

    if(move_event) {
        generate();
    }
}

void Game::moveDown()
{
    bool move_event = false;

    for (int k = 0; k < size; k++) {

        for (int i = size -1 ; i >= 0; --i) {

            //Если текущий эл-т равен 0
            if (array[i][k] == 0) {

                //найдем первый не 0 эл-т
                for (int j = i - 1; j >= 0; --j) {

                    //если не 0 эл-т есть
                    if (array[j][k] != 0) {

                        //меняем местами с текущим
                        array[i][k] = array [j][k];
                        array[j][k] = 0;
                        move_event = true;

                        //и продолжаем поиск следующего не 0 эл-та
                        for (int m = j - 1; m >= 0; --m) {

                            //если такой эт-т есть
                            if (array[m][k] != 0) {

                                //и он равен текущему
                                if (array[i][k] == array[m][k]) {
                                    array[i][k] *= 2;
                                    addScore(array[i][k]);
                                    array[m][k] = 0;
                                }

                                break;
                            }
                        }

                        break;
                    }

                }
            }
            //Если текущий элемент не равен нулю
            else {

                //найдем первый не 0
                for (int j = i - 1; j >= 0; --j) {

                    if (array[j][k] != 0) {

                        if (array[i][k] == array[j][k]) {
                            array[i][k] *= 2;
                            addScore(array[i][k]);
                            array[j][k] = 0;
                            move_event = true;
                        }

                        break;
                    }
                }
            }
        }
    }

    if(move_event) {
        generate();
    }
}

void Game::moveLeft()
{
    bool move_event = false;

    for (int k = 0; k < size; k++) {

        for (int i = 0; i < size; i++) {

            if (array[k][i] == 0) {

                for (int j = i + 1; j < size; j++) {

                    if (array[k][j] != 0) {

                        array[k][i] = array [k][j];
                        array[k][j] = 0;
                        move_event = true;

                        for (int m = j + 1; m < size; m++) {

                            if (array[k][m] != 0) {

                                if (array[k][i] == array[k][m]) {
                                    array[k][i] *= 2;
                                    addScore(array[k][i]);
                                    array[k][m] = 0;
                                }

                                break;
                            }
                        }

                        break;
                    }

                }
            }

            else {

                for (int j = i + 1; j < size; j++) {

                    if (array[k][j] != 0) {

                        if (array[k][i] == array[k][j]) {
                            array[k][i] *= 2;
                            addScore(array[k][i]);
                            array[k][j] = 0;
                            move_event = true;
                        }

                        break;
                    }
                }
            }
        }
    }

    if(move_event) {
        generate();
    }
}

void Game::moveRight()
{
    bool move_event = false;

    for (int k = 0; k < size; k++) {

        for (int i = size - 1; i >= 0; --i) {

            if (array[k][i] == 0) {

                for (int j = i - 1; j >= 0; --j) {

                    if (array[k][j] != 0) {

                        array[k][i] = array [k][j];
                        array[k][j] = 0;
                        move_event = true;

                        for (int m = j - 1; m >= 0; --m) {

                            if (array[k][m] != 0) {

                                if (array[k][i] == array[k][m]) {
                                    array[k][i] *= 2;
                                    addScore(array[k][i]);
                                    array[k][m] = 0;
                                }

                                break;
                            }
                        }

                        break;
                    }

                }
            }

            else {

                for (int j = i - 1; j >= 0; --j) {

                    if (array[k][j] != 0) {

                        if (array[k][i] == array[k][j]) {
                            array[k][i] *= 2;
                            addScore(array[k][i]);
                            array[k][j] = 0;
                            move_event = true;
                        }

                        break;
                    }
                }
            }
        }
    }

    if(move_event) {
        generate();
    }
}

void Game::addScore(int _score)
{
    score += _score;
}

int Game::getScore()
{
    return score;
}

void Game::setHighScore()
{
    if (score > high_score)
        high_score = score;
}

int Game::getHighScore()
{
    setHighScore();
    return high_score;
}

bool Game::gameOver()
{
    //Ищем свободные ячейки
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            if (array[i][j] == 0)
                return false;
    }

    //Проверяем на равенство двух соседних ячеек
    //По вертикали
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++)
            if (array[i][j] == array[i][j+1])
                return false;
     }

    //По горизонтали
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++)
            if (array[i][j] == array[i+1][j])
                return false;
    }

    return true;
}

bool Game::gameWin()
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            if (array[i][j] == 2048)
                return true;
    }

    return false;
}
