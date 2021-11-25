#include "ui/mainwindow.h"
//#include "ui_mainwindow.h"
//#include "core/game.hpp"
#include <iostream>
#include <QString>
#include <QKeyEvent>
#include "core/game.hpp"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui_field.setParent(this);
    ui_field.move(10,0);
    this->resize(820,620);
    this->setMinimumSize(820,620);
    this->setMaximumSize(820,620);


}

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//    switch(event->key()) {
//       case Qt::Key_Up:
//       case Qt::Key_W:
//            game.moveUp();
//            t_field.changeText(game.getBoard(),16);
//        break;

//       case Qt::Key_Left:
//       case Qt::Key_A:
//        game.moveLeft();
//        t_field.changeText(game.getBoard(),16);
//        break;

//       case Qt::Key_Down:
//       case Qt::Key_S:
//            game.moveDown();
//            t_field.changeText(game.getBoard(),16);
//        break;
//       case Qt::Key_Right:
//       case Qt::Key_D:
//        game.moveRight();
//            t_field.changeText(game.getBoard(),16);
//        break;
//    }
//}
MainWindow::~MainWindow()
{
//    delete ui;
}
