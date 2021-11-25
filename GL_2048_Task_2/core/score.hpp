#ifndef GL_SCORE_H
#define GL_SCORE_H
#include <fstream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <QtCore>
#include <iostream>
// #include <stdlib.h>

using std::ifstream;
using std::ofstream;

class Score
{
    ifstream if_file;
    ofstream of_file;

    bool was_readed;
    const char* SCORE_PATH = "score.txt";
    qint64 current_score;
    qint64 best_score;
    qint64 readed_best_score;


public:
    qint64 getBestScore() const;
    qint64 getCurrentScore() const;
    void addPoints(const qint64& points);
    void saveBestScore();

    Score();
    ~Score();

private:
    void readBestScore();
};

#endif
