#ifndef GL_FIELD_H
#define GL_FIELD_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include "memento.hpp"
#include "score.hpp"
#include <QtCore>



const qint32 FIELD_SIZE_X = 4;
const qint32 FIELD_SIZE_Y = 4;

const qint32 FIELD_SQUARE = FIELD_SIZE_X * FIELD_SIZE_Y;

enum class MOVES { LEFT = 0, RIGHT, UP, DOWN};

class Field {
private:
    
    qint32 desk[FIELD_SIZE_X * FIELD_SIZE_Y];
    Score score;
    Memento save;

public:
    Field();

    bool has2048InField();

//    char* printField();
    bool move(MOVES dir);

    bool hasFreeCell() const;

    bool hasMoves_X() const;

    bool hasMoves_Y() const;
    
    bool undoStep();

    qint32* getBoard();

    qint64 getCurrentScore() const;

    qint64 getBestScore() const;
    
    qint32 addRandomTile();

    void reset();
//temp
    void show();
};


#endif
