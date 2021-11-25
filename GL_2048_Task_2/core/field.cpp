#include "field.hpp"
//#include<QDebug>
#include <strstream>


Field::Field()
{
    memset(desk, 0, (FIELD_SIZE_X * FIELD_SIZE_Y) * sizeof(*desk));
    addRandomTile();
    addRandomTile();
}

// void Field::Save()
// {
//     score.saveBestScore();
// }

bool Field::move(MOVES dir)
{
    save.saveStep(desk,FIELD_SQUARE);

    bool moved = false;
    qint32 diff = 0, base = 0, step = 0;

    switch (dir)
    {
    case MOVES::LEFT:
        diff = +1;
        base = 0;
        step = FIELD_SIZE_X;
        break;

    case MOVES::UP:
        diff = FIELD_SIZE_Y;
        base = 0;
        step = 1;
        break;

    case MOVES::RIGHT:
        diff = -1;
        base = FIELD_SQUARE - 1;
        step = -FIELD_SIZE_X;
        break;

    case MOVES::DOWN:
        diff = -FIELD_SIZE_Y;
        base = FIELD_SQUARE - 1;
        step = -1;
        break;
    }

    for (qint32 x = 0; x < FIELD_SIZE_X; x++)
    {
        qint32 to = base, from = (base + diff);

        for (qint32 y = 0; y < FIELD_SIZE_Y - 1; y++)
        {
            if (desk[from] == 0)
            {
                from += diff;
//                moved = true;
                continue;
            }
            if (desk[to] == 0)
            {
                if (desk[from] != 0)
                {
                    desk[to] = desk[from];
                    desk[from] = 0;
                    moved = true;
                }
                from += diff;
            }
            else if (desk[to] == desk[from])
            {
                desk[to] *= 2;
                score.addPoints(desk[to]);
                desk[from] = 0;
                to += diff;
                from += diff;
                moved = true;
            }
            else
            {
                to += diff;
                if (from != to)
                {
                    desk[to] = desk[from];
                    desk[from] = 0;
                    moved = true;
                }
                from += diff;
            }
        }
        base += step;
    }
    return moved;
}

bool Field::has2048InField(){
    for(qint32 i = 0; i < FIELD_SQUARE; i++)
    {
        if(desk[i] == 2048)
        {
            return true;
        }
    }
    return false;
}


//QTextStream& qStdOut()
//{
//    static QTextStream ts( stdout );
//    return ts;
//}

bool Field::hasFreeCell() const
{
    for (qint32 i = 0; i < FIELD_SQUARE; i++)
    {
        if (desk[i] == 0)
        {
            return true;
        }
//        qStdOut() << desk[i] << ", ";
    }
//    qStdOut() << "||||";
    return false;
}

bool Field::hasMoves_X() const
{
    for (qint32 x = 0; x < FIELD_SIZE_Y; x++)
    {
        for (qint32 y = 0; y < FIELD_SIZE_X - 1; y++)
        {
            if (desk[x * FIELD_SIZE_Y + y] == desk[x * FIELD_SIZE_Y + y + 1])
            {
                return true;
            }
        }
    }
    return false;
}

bool Field::hasMoves_Y() const

{
    for (qint32 y = 0; y < FIELD_SIZE_X; y++)
    {
        for (qint32 x = 0; x < FIELD_SIZE_Y - 1; x++)
        {
            if (desk[x * FIELD_SIZE_Y + y] == desk[(x + 1) * FIELD_SIZE_Y + y])
            {
                return true;
            }
        }
    }
    return false;
}

bool Field::undoStep()
{
    if(save.canRestore())
    {
        save.restoreStep(desk,FIELD_SQUARE);
        return true;
    }
    return false;
}

//char* Field::printField(){
//    std::stringstream s;
//    char* ret = new char(16);
//    for (qint32 i = 0; i < FIELD_SQUARE; i++)
//    {
//        s << desk[i];
//    }
//    s >> ret;
//    return ret;
//}


int Field::addRandomTile()
{
    qint32 freeCells = 0;

    for (qint32 i = 0; i < FIELD_SQUARE; i++)
    {
        if (desk[i] == 0)
        {
            freeCells++;
        }
    }
    if (freeCells == 0)
    {
        return 0;
    }

    qint32 rand_pos = rand() % freeCells;
    qint32 index;

    for (index = 0; index < FIELD_SQUARE; index++)
    {
        if (desk[index] == 0)
        {
            if (rand_pos == 0)
            {
                break;
            }
            else
            {
                rand_pos--;
            }
        }
    }

    if ((rand() % 100) > 90)
    {
        desk[index] = 4;
        score.addPoints(4);
    }
    else
    {
        score.addPoints(2);
        desk[index] = 2;
    }

    return desk[index];
}

void Field::reset()
{
    memset(desk, 0, (FIELD_SIZE_X * FIELD_SIZE_Y) * sizeof(*desk));
}

long long Field::getBestScore() const
{
    return score.getBestScore();
}

long long Field::getCurrentScore() const
{
    return score.getCurrentScore();
}

int* Field::getBoard()
{
    return desk;
}
    
void Field::show()
{
    std::cout << "Current score: " << score.getCurrentScore() << "\t Best score: " << score.getBestScore() << std::endl;
    for (qint32 x = 0; x < FIELD_SIZE_X; x++)
    {
        for (qint32 y = 0; y < FIELD_SIZE_Y; y++)
        {
            if (desk[x * FIELD_SIZE_X + y])
            {
                std::cout << std::setw(FIELD_SIZE_X) << desk[x * FIELD_SIZE_X + y];
            }
            else
            {
                std::cout << std::setw(FIELD_SIZE_X) << '.';
            }
        }
        std::cout << std::endl;
    }
}
