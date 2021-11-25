#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "board.hpp"
//#include "tielfield.hpp"

//namespace Ui {
//class MainWindow;
//}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Board ui_field;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//    void play();
//signals:
//    void reset();
//    void undoStep();

private:

//    virtual void keyPressEvent(QKeyEvent *event);
//    Ui::MainWindow *ui;
//    Game2048 game;

};

#endif // MAINWINDOW_H
