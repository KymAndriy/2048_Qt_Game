#include "tielfield.hpp"


//TielField::Coords::Coords(int x, int y) : x(x), y(y)
//{}

TielField::TielField(QWidget *parent) : QWidget(parent)
{
    QFont h("Arial",20);
    this->setMaximumSize(600,600);
    this->setMinimumSize(600,600);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Background, Qt::white);

    this->setAutoFillBackground(true);
    this->setPalette(pal);
    for(qint32 i = 0; i < 16; i++){
        this->text[i].setText("");
        this->text[i].setAlignment(Qt::AlignCenter);
        this->text[i].setParent(this);
        this->text[i].setMinimumSize(120,120);
        this->text[i].setFont(h);
    }

    // 600x600
    //  20  125     20 125    20 125     20 125     20
    // |    0           0         0          0      |

//          20      165         310         455
    this->text[0].move(20,20);
    this->text[1].move(165,20);
    this->text[2].move(310,20);
    this->text[3].move(455,20);
    this->text[4].move(20,165);
    this->text[5].move(165,165);
    this->text[6].move(310,165);
    this->text[7].move(455,165);
    this->text[8].move(20,310);
    this->text[9].move(165,310);
    this->text[10].move(310,310);
    this->text[11].move(455,310);
    this->text[12].move(20,455);
    this->text[13].move(165,455);
    this->text[14].move(310,455);
    this->text[15].move(455,455);

    this->show();
}

void TielField::changeText(qint32* begin, qint32 size){
    for(qint32 i = 0; i < size; i++)
    {
        qint32 what_num = begin[i];
        draw(&text[i], what_num);
//        this->text[i].setText(QString::number(what_num));
    }
}


void TielField::draw(QLabel* lab, qint32& to_change_num)
{/*
    if (lab->text() == "0") {
        lab->setText("");
        setStyleSheet("QLabel { background: rgb(204,192,179); border-radius: 5px; }");
    } else {
//        setText(QString::number(lab->text()));
        */
    if(to_change_num == 0)
    {
        lab->setText("");
    }else{
        lab->setText(QString::number(to_change_num));
    }

    switch (to_change_num) {
        case 0: {
            lab->setStyleSheet("QLabel { background: rgb(204,192,179); border-radius: 5px; }");
            break;
        }
        case 2: {
            lab->setStyleSheet("QLabel { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 5px; font: 35pt; }");
            break;
        }
        case 4: {
            lab->setStyleSheet("QLabel { background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 5px; font: 35pt; }");
            break;
        }
        case 8: {
            lab->setStyleSheet("QLabel { background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 35pt; }");
            break;
        }
        case 16: {
            lab->setStyleSheet("QLabel { background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 30pt; }");
            break;
        }
        case 32: {
            lab->setStyleSheet("QLabel { background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 30pt; }");
            break;
        }
        case 64: {
            lab->setStyleSheet("QLabel { background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 30pt; }");
            break;
        }
        case 128: {
            lab->setStyleSheet("QLabel { background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 25pt; }");
            break;
        }
        case 256: {
            lab->setStyleSheet("QLabel { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 25pt; }");
            break;
        }
        case 512: {
            lab->setStyleSheet("QLabel { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 25pt; }");
            break;
        }
        case 1024: {
            lab->setStyleSheet("QLabel { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 20pt; }");
            break;
        }
        case 2048: {
            lab->setStyleSheet("QLabel { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 5px; font: 20pt; }");
            break;
        }
        default: {
            lab->setStyleSheet("QLabel { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 5px; font: 20pt; }");
            break;
        }
    }

}
