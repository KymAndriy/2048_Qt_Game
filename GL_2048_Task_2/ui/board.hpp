#ifndef FIELD_HPP
#define FIELD_HPP

#include <QWidget>
#include <QLabel>
#include "aligthmentlayout.hpp"

#include "board.hpp"
#include "tielfield.hpp"


class Board : public QWidget
{
    Q_OBJECT
private:
    AligthmentLayout a_l;
    TielField t_field;
    Game2048 game;
    QWidget game_end;
    QLabel game_end_text;



public:
    explicit Board(QWidget *parent = nullptr);

virtual void keyPressEvent(QKeyEvent *event);
};

#endif // FIELD_HPP
