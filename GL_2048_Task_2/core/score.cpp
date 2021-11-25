#include "score.hpp"

// #include <exception>

Score::Score()
{
    if_file.open(SCORE_PATH, std::fstream::in | std::fstream::out | std::fstream::app);
    of_file.open(SCORE_PATH, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!if_file && !of_file)
    {
        std::cerr << "File open problem";
    }
    was_readed = false;
    best_score = 0;
    current_score = 0;
    readed_best_score = 0;
    readBestScore();
}

Score::~Score()
{
    saveBestScore();
    if_file.close();
    of_file.close();
}

void Score::addPoints(const qint64 &points)
{
    current_score += points;
}

long long Score::getBestScore() const
{
    if(current_score > best_score)
    {
        return current_score;
    }
    return best_score;
}

long long Score::getCurrentScore() const
{
    return current_score;
}

void Score::readBestScore()
{
    std::string s;
    if(!was_readed){
        if(if_file.is_open())
        {
            while(!if_file.eof())
            {
                if_file >> s;
                std::stringstream to_long(s);
                to_long >> readed_best_score;
                if(readed_best_score > best_score)
                {
                    best_score = readed_best_score;
                }
            }
        }
        was_readed = true;
        best_score = readed_best_score;
    }
}

void Score::saveBestScore()
{
    if(readed_best_score < current_score && best_score < current_score)
    {
        if (of_file.is_open())
        {
            of_file << current_score << std::endl; 
        }
    }    
}
