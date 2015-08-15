#include "Othello.h"

namespace
{
    enum { ROW = 8, COLUMN = 8 };

    bool isValid(Position p)
    {
        return p >= a1 && p <= h8;
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

    Position leftUp(Position p)
    {
        return left(up(p));
    }

    Position leftDown(Position p)
    {
        return left(down(p));
    }

    Position rightUp(Position p)
    {
        return right(up(p));
    }

    Position rightDown(Position p)
    {
        return right(down(p));
    }
}

Othello::Othello()
{
}

void Othello::refreshBoard(const Board& board)
{
	this->board = board;
}

bool Othello::hasNext(Position curr, Position moves) const
{
    return board.isOccupied(moves) && board.at(moves) != board.at(curr);
}

namespace
{
	Moves availableMoves;
}

void Othello::find(Position p, Action move)
{
    if( ! board.isOccupied(p)) return;

    Position next = p;
    do
    {
        next =  move(next);
    }while(hasNext(p, next));

    if( ! isValid(next)) return;

    if( ! board.isOccupied(next) && next != move(p))
    {
    	availableMoves.push(next);
    }
}

const Moves& Othello::getAvailableMoves(Position p)
{
	availableMoves.clear();

	find(p, up);
	find(p, down);
	find(p, left);
	find(p, right);
	find(p, leftUp);
	find(p, leftDown);
	find(p, rightUp);
	find(p, rightDown);

	return availableMoves;
}

namespace
{
	Moves allMoves;
}

const Moves& Othello::getAllAvailableMoves(Disc disc)
{
	for(int i = a1; i < MAX_POSITION_NUM; ++i)
	{
		Position p = static_cast<Position>(i);
		if(board.at(p) == disc) allMoves = allMoves + getAvailableMoves(p);
	}

	return allMoves;
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

    bool onARightDiagonal(Position min, Position max)
    {
         return (max-min) % (COLUMN+1) == 0; 
    }

    bool onALeftDiagonal(Position min, Position max)
	{
		 return (max-min) % (COLUMN-1) == 0;
	}
}

void Othello::doTurn(Position curr, Position moves)
{
    Position max = __max(curr, moves);
    Position min = __min(curr, moves);

    int step = 0;
    if(onARow(min, max)) step = 1;
    if(onAColumn(min, max)) step = COLUMN;
    if(onALeftDiagonal(min, max)) step = COLUMN - 1;
    if(onARightDiagonal(min, max)) step = COLUMN + 1;

    for(int i = min+step; i < max; i=i+step)
    {
        Position p = static_cast<Position>(i);
        board.trueOver(p);
    }
}

const Board& Othello::capture(Position original, Position move)
{
	board.place(move, board.at(original));
	doTurn(original, move);
	return board;
}

const Board& Othello::retract(Position original, Position move)
{
	doTurn(original, move);
	board.place(move, _);
	return board;
}

const Board& Othello::getBoard() const
{
	return board;
}
