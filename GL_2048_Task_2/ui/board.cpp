#include "ui/board.hpp"
#include "ui_mainwindow.h"
//#include <QString>

Board::Board(QWidget *parent) : QWidget(parent), a_l(this)//,
{
    this->resize(820,620);
    this->t_field.setParent(this);
    this->t_field.move(0,10);
    t_field.changeText(game.getBoard(),16);
    this->a_l.move(610,10);
    this->a_l.setGame(&game);
    this->a_l.setTielField(&t_field);
     a_l.setBestScore(QString::number(game.getHighScore()));
     game_end.resize(300,200);
     game_end_text.setParent(&game_end);
}

void Board::keyPressEvent(QKeyEvent *event)
{

    switch(event->key()) {
//       case Qt::Key_Up:
       case Qt::Key_W:
            game.moveUp();
            t_field.changeText(game.getBoard(),16);
        break;

//       case Qt::Key_Left:
       case Qt::Key_A:
        game.moveLeft();
        t_field.changeText(game.getBoard(),16);
        break;

//       case Qt::Key_Down:
       case Qt::Key_S:
            game.moveDown();
            t_field.changeText(game.getBoard(),16);
        break;
//       case Qt::Key_Right:
       case Qt::Key_D:
        game.moveRight();
            t_field.changeText(game.getBoard(),16);
        break;
    }
    a_l.setBestScore(QString::number(game.getHighScore()));
    a_l.setCurrentScore(QString::number(game.getCurScore()));

    if(game.gameWin())
    {
        QString win("You win!\n Your Score: ");
        win.push_back(QString::number(game.getCurScore()));
        game_end_text.setText(win);
        game_end.show();
    }
    if(game.gameOver())
    {

        QString lose("You lose =(\n Your Score: ");
        lose.push_back(QString::number(game.getCurScore()));
        lose.push_back('\n');
//        lose.push_back(game.printField());
        game_end_text.setText(lose);
        game_end.show();
    }
}
