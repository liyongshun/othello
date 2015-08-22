#include "Board.h"
#include <iostream>

Board::Board()
{
    init();
}

Board& Board::operator=(const Board& board)
{
	::memmove(discs, board.discs, sizeof(discs));
	return *this;
}

Board::Board(const Disc* board)
{
	if(board == 0) return;

	for(int i = a1; i < MAX_POSITION_NUM; ++i)
	{
		discs[i] = board[i];
	}
}

void Board::init()
{
    for(int i = a1; i < MAX_POSITION_NUM; ++i)
    {
        discs[i] = _;
    }

    discs[e4] = B;
    discs[d5] = B;
    discs[d4] = W;
    discs[e5] = W;
}

namespace
{
    Disc nullDisc = _;
}

Disc Board::at(Position p) const
{
    if( ! onBoard(p)) return nullDisc;

    return discs[p];
}

namespace
{
    char to_c(Disc disc)
    {
        switch(disc)
        {
            case _: return '_';
            case B: return 'B';
            case W: return 'W';
            default: return 'V';
        }
    }
}

void Board::print() const
{
	std::cout <<  "\n" << "a b c d e f g h" << std::endl;

	enum { COLUMN_NUM = 8 };
	for(int i = a1; i < MAX_POSITION_NUM; ++i)
    {
        if(i % COLUMN_NUM == 0 && i != 0)
        {
            std::cout << " " << i/COLUMN_NUM << "\n";
        }
        std::cout << to_c(discs[i]) << " ";
    }

    std::cout << " " << COLUMN_NUM << "\n";
}

void Board::trueOver(Position p)
{
	if( ! isOccupied(p)) return;

	discs[p] = (at(p) == B) ? W : B;
}

void Board::place(Position p, Disc disc)
{
	if( ! onBoard(p)) return;

	discs[p] = disc;
}

bool Board::isOccupied(Position p) const
{
	if( ! onBoard(p)) return false;

	return discs[p] == B || discs[p] == W;
}

bool Board::onBoard(Position p)
{
	return p >= a1 && p <= h8;
}

bool Board::operator==(const Board& rsh) const
{
    for(int i = a1; i < MAX_POSITION_NUM; ++i)
    {
    	if(discs[i] != rsh.discs[i]) return false;
    }

    return true;
}

