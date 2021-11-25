#ifndef ALIGTHMENTLAYOUT_HPP
#define ALIGTHMENTLAYOUT_HPP

#include <QWidget>

#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QVBoxLayout>
#include <QPalette>
#include <QSpacerItem>
#include "core/game.hpp"
#include "tielfield.hpp"
#include <QKeyEvent>

class AligthmentLayout : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout h_aline;
    QPushButton reset;
    QLabel current_score_text;
    QLabel current_score_value;
    QLabel best_score_value;
    QPushButton undo_step;
//      QGraphicsView graphicsView;
    QLabel best_score_text;
    Game2048* game;
    TielField* tf;
public:
    explicit AligthmentLayout(QWidget *parent = nullptr);
    void setGame(Game2048* g);
    void setTielField(TielField* t);

    void setBestScore(QString sc);
    void setCurrentScore(QString sc);

signals:

private slots:

    void resetGame();
    void undoGameStep();
};

#endif // ALIGTHMENTLAYOUT_HPP
