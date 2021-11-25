#ifndef TIELFIELD_HPP
#define TIELFIELD_HPP

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QLabel>
#include <QRectF>
#include <QPalette>
#include <QColor>
#include "core/game.hpp"
//#include <utility>
//#include <QVector>
//using std::pair;

class TielField : public QWidget
{
    Q_OBJECT
//private:
//    QPointF calculatePosition(int position) const;

//    int tileSide = 125;
//    int margin = 20;
//    int slideSteps = 30;
//    int arrangeSteps = 5;
//    int timerInterval = 5;

    /*
    struct Coords{
        const int x;
        const int y;
        Coords(int,int);
    };*/
    QGraphicsScene scene;
//    QGraphicsItem tiel;
    QPainter paint;
    QLabel text[16];
//    Coords position[16];

    const int cord[4][4] ={
        {0,  1,  2,  3},
        {4,  5,  6,  7},
        {8,  9,  10, 11},
        {12, 13, 14, 15}
    };
public:
    explicit TielField(QWidget *parent = nullptr);
    void changeText(int* begin, int size);
    void draw(QLabel* q, qint32& t);
signals:

public slots:
};

#endif // TIELFIELD_HPP
