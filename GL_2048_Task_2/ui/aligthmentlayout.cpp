#include "aligthmentlayout.hpp"
#include <stdlib.h>
AligthmentLayout::AligthmentLayout(QWidget *parent) : QWidget(parent)
{
    QFont h("Arial",16);
    QFont val("Arial",14);
    QPalette pal = this->palette();

       // set black background
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();
    this->setFixedHeight(600);
    this->setFixedWidth(190);


//  QVBox container add and setup Labels and Buttons
    h_aline.addSpacerItem(new QSpacerItem(190,50));
    h_aline.addWidget(&best_score_text);
    h_aline.setAlignment(&best_score_text,Qt::AlignCenter);

    h_aline.addWidget(&best_score_value);
    h_aline.setAlignment(&best_score_value,Qt::AlignCenter);
    h_aline.addSpacerItem(new QSpacerItem(190,60));

    h_aline.addWidget(&current_score_text);
    h_aline.setAlignment(&current_score_text,Qt::AlignCenter);

    h_aline.addWidget(&current_score_value);
    h_aline.setAlignment(&current_score_value,Qt::AlignCenter);
    h_aline.addSpacerItem(new QSpacerItem(190,60));

    h_aline.addWidget(&undo_step);
    h_aline.setAlignment(&undo_step,Qt::AlignCenter);
    h_aline.addSpacerItem(new QSpacerItem(190,10));

    h_aline.addWidget(&reset);
    h_aline.setAlignment(&reset,Qt::AlignCenter);
    h_aline.addSpacerItem(new QSpacerItem(190,60));
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    undo_step.setParent(this);
    reset.setParent(this);
    best_score_text.setParent(this);
    best_score_value.setParent(this);
    current_score_value.setParent(this);
    current_score_text.setParent(this);

    this->move(0,0);

//undo step
    this->undo_step.setMinimumSize(90,25);
    this->undo_step.setMaximumSize(90,25);
    this->undo_step.setText("Undo Step");

//reset
    this->reset.setMinimumSize(90,25);
    this->reset.setMaximumSize(90,25);
    this->reset.setText("Reset");

//best score Text
    this->best_score_text.setFont(h);
    this->best_score_text.setAlignment(Qt::AlignCenter);
    this->best_score_text.setMinimumSize(110,25);
    this->best_score_text.setMaximumSize(110,25);
    this->best_score_text.setText("Best Score");

//best score Value
    this->best_score_value.setFont(val);
    this->best_score_value.setText("0");
    this->best_score_value.setMinimumSize(120,25);
    this->best_score_value.setMaximumSize(120,25);
    this->best_score_value.setAlignment(Qt::AlignCenter);

//current score Text
    this->current_score_text.setFont(h);
    this->current_score_text.setMinimumSize(140,20);
    this->current_score_text.setMaximumSize(140,20);
    this->current_score_text.setAlignment(Qt::AlignCenter);
    this->current_score_text.setText("Current Score");

//current score Value
    this->current_score_value.setFont(val);
    this->current_score_value.setMinimumSize(120,25);
    this->current_score_value.setMaximumSize(120,25);
    this->current_score_value.setText("0");
    this->current_score_value.setAlignment(Qt::AlignCenter);
    this->setLayout(&h_aline);
    connect(&reset,SIGNAL(released()),this,SLOT(resetGame()));
    connect(&undo_step,SIGNAL(released()),this,SLOT(undoGameStep()));
//temp
//    srand(time(NULL));
}

void AligthmentLayout::setBestScore(QString sc)
{
    best_score_value.setText(sc);
}
void AligthmentLayout::setCurrentScore(QString sc){
    current_score_value.setText(sc);
}

void AligthmentLayout::setGame(Game2048 *g)
{
    this->game = g;
}
void AligthmentLayout::setTielField(TielField *t)
{
    this->tf = t;
}
//TielField

void AligthmentLayout::resetGame()
{
    game->reset();
    tf->changeText(game->getBoard(),16);
//temp
//    this->best_score_value.setText(QString::number(rand()%1000000));
}

void AligthmentLayout::undoGameStep()
{
    game->undoStep();
    tf->changeText(game->getBoard(),16);

//temp
//    this->current_score_value.setText(QString::number(rand()%1000000));
}


