#include "game.hpp"


Game2048::Game2048()
{
    srand(time(0));
}

qint64 Game2048::getCurScore()
{
    return game_field.getCurrentScore();
}

qint64 Game2048::getHighScore()
{
    return game_field.getBestScore();
}
void Game2048::moveDown()
{
//    if (game_field.hasMoves_Y() || game_field.hasMoves_X() || game_field.hasFreeCell())
//    {
        bool was_move = game_field.move(MOVES::DOWN);
        if (game_field.hasFreeCell() && was_move)
        {
            game_field.addRandomTile();
        }
//    }
}
void Game2048::moveLeft()
{
//    if (game_field.hasMoves_X() || game_field.hasMoves_Y() || game_field.hasFreeCell())
//    {
        bool was_move = game_field.move(MOVES::LEFT);
        if (game_field.hasFreeCell() && was_move)
        {
            game_field.addRandomTile();
        }
//    }
}
void Game2048::moveRight()
{
//    if (game_field.hasMoves_X() || game_field.hasMoves_Y() || game_field.hasFreeCell())
//    {
        bool was_move = game_field.move(MOVES::RIGHT);
        if (game_field.hasFreeCell() && was_move)
        {
            game_field.addRandomTile();
        }
//    }
}
void Game2048::moveUp()
{
//    if (game_field.hasMoves_Y() || game_field.hasMoves_X() || game_field.hasFreeCell())
//    {
        bool was_move = game_field.move(MOVES::UP);
        if (game_field.hasFreeCell() && was_move)
        {
            game_field.addRandomTile();
        }
//    }
}

bool Game2048::gameOver()
{
    if(!game_field.hasMoves_X() && !game_field.hasMoves_Y() && !game_field.hasFreeCell())
    {
        return true;
    }
    return false;
}

bool Game2048::gameWin()
{
    return game_field.has2048InField();
}
void Game2048::reset()
{
    game_field.reset();
    game_field.addRandomTile();
    game_field.addRandomTile();
}
void Game2048::undoStep()
{
    game_field.undoStep();
}

void Game2048::show()
{
    game_field.show();
}

int* Game2048::getBoard()
{
    return game_field.getBoard();
}


//char* Game2048::printField(){
//    return game_field.printField();
//}
