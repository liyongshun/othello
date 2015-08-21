#include "Othello.h"
#include "Direction.h"

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
	Moves movesOriginalPosition[MAX_POSITION_NUM];

	void clearMovesOriginalPosition()
	{
		for(int i = a1; i < MAX_POSITION_NUM; ++i)
		{
			movesOriginalPosition[i].clear();
		}
	}
}

void Othello::find(Position p, const Removable& move)
{
    if( ! board.isOccupied(p)) return;

    Position next = p;
    do
    {
        next =  move.move(next);
    }while(hasNext(p, next));

    if( ! board.onBoard(next)) return;

    if( ! board.isOccupied(next) && next != move.move(p))
    {
    	availableMoves.push(next);
    	movesOriginalPosition[next].push(p);
    }
}

const Moves& Othello::getAvailableMoves(Position p)
{
	availableMoves.clear();

	find(p, _up);
	find(p, _down);
	find(p, _left);
	find(p, _right);
	find(p, _left_up);
	find(p, _left_down);
	find(p, _right_up);
	find(p, _right_down);

	return availableMoves;
}

namespace
{
	Moves allMoves;
}

const Moves& Othello::thinkMoves(Disc disc)
{
	allMoves.clear();
	clearMovesOriginalPosition();
	for(int i = a1; i < MAX_POSITION_NUM; ++i)
	{
		Position p = static_cast<Position>(i);
		if(board.at(p) == disc)
		{
			allMoves = allMoves + getAvailableMoves(p);
		}
	}

	return allMoves;
}

namespace
{
	bool isReachable(Position from, Position to, const Removable& move)
	{
		for(int i = a1; i < MAX_POSITION_NUM; ++i)
		{
			from = move.move(from);
			if(from == to) return true;
		}

		return false;
	}
}

void Othello::doTurn(Position from, Position to, const Removable& move)
{
	if(isReachable(from, to, move))
	{
		Position next = from;
		while(next != to)
		{
			next = move.move(next);
			board.trueOver(next);
		}
	}
}

void Othello::turn(Position original, Position moves)
{
	doTurn(original, moves, _up);
	doTurn(original, moves, _down);
	doTurn(original, moves, _left);
	doTurn(original, moves, _right);
	doTurn(original, moves, _left_up);
	doTurn(original, moves, _left_down);
	doTurn(original, moves, _right_up);
	doTurn(original, moves, _right_down);
}

const Board& Othello::capture(Position movePosition)
{
	lastBoard = board;
	while( ! movesOriginalPosition[movePosition].isEmpty())
	{
		Position originalPosition = movesOriginalPosition[movePosition].pop();
		board.place(movePosition, board.at(originalPosition));
		turn(originalPosition, movePosition);
	}

	return board;
}

const Board& Othello::retract()
{
	board = lastBoard;
	return board;
}

const Board& Othello::getBoard() const
{
	return board;
}
