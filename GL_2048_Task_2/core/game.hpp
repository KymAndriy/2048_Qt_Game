#ifndef GL_GAME_H
#define GL_GAME_H
#include "field.hpp"
#include <stdlib.h>
#include <QtCore>

class Game2048
{
    Field game_field;
public:
    Game2048();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

//    QChar
    char* printField();
    qint64 getHighScore();
    qint64 getCurScore();
    qint32* getBoard();
    void undoStep();
    void reset();
    void show();
    bool gameWin();
    bool gameOver();
};

#endif
