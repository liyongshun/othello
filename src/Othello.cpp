#include "Othello.h"
#include <iostream>

namespace
{
    enum { ROW = 8, COLUMN = 8 };

    bool isValid(Position p)
    {
        return p >= a1 && p < MAX_POSITION_NUM;
    }

    Position up(Position p)
    {
        return static_cast<Position>(p - ROW);
    }

    Position down(Position p)
    {
        return static_cast<Position>(p + ROW);
    }

    Position left(Position p)
    {
        return static_cast<Position>(p - 1);
    }

    Position right(Position p)
    {
        return static_cast<Position>(p + 1);
    }

    Position nothingTodo(Position p)
    {
        return p;
    }
}

bool Othello::moveOn(Position currP, Position movesP)
{
    Disc disc = board.at(currP);

    return DiscUtil::isOccupied(board.at(movesP)) &&
           board.at(movesP) != disc;
}

void Othello::find(Position p, Move firstStep, Move secondStep)
{
    if( ! DiscUtil::isOccupied(board.at(p))) return;

    Position next = p;
    do
    {
        next =  firstStep(secondStep(next));
    }while(moveOn(p, next));

    if( ! isValid(next)) return;

    if(DiscUtil::isVacant(board.at(next)) && next != firstStep(secondStep(p)))
    {
        moves[p].push(next);
    }
}

void Othello::findMoves(Position p)
{
	find(p, up, nothingTodo);
	find(p, down, nothingTodo);
	find(p, left, nothingTodo);
	find(p,right, nothingTodo);
	find(p,left, up);
	find(p,left, down);
	find(p,right, up);
	find(p,right, down);
}

const Moves& Othello::getMoves(Position p) const
{
    return moves[p];
}

namespace
{
    #define __min(a, b) ( (a)<(b)? (a):(b) )
    #define __max(a, b) ( (a)>(b)? (a):(b) )

    bool onARow(Position a, Position b)
    {
        return a/COLUMN == b/COLUMN; 
    }

    bool onAColumn(Position a, Position b)
    {
        return a%COLUMN == b%COLUMN;
    }

    bool onADiagonal(Position min, Position max)
    {
         return (max-min) % (COLUMN+1) == 0; 
    }
}

void Othello::doTurn(Position curr, Position moves)
{
    Position max = __max(curr, moves);
    Position min = __min(curr, moves);

    int step = 0;
    if(onARow(min, max)) step = 1;
    if(onAColumn(min, max)) step = COLUMN;
    if(onADiagonal(min, max)) step = COLUMN + 1;

    for(int i = min+step; i < max; i=i+step)
    {
        Position p = static_cast<Position>(i);
        board.turn(p);
    }
}

void Othello::turn()
{
    for(int i = a1; i < MAX_POSITION_NUM; ++i)
    {
        while( ! moves[i].isEmpty())
        {
            Position currP = static_cast<Position>(i);
            Position move = moves[i].pop();
            board.at(move) = board.at(currP);

            doTurn(currP, move);

            board.print();
            board.reset();
        }
    }
}
