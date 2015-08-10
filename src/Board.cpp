#include "Board.h"
#include <iostream>

Board::Board()
{
    init();
}

void Board::init()
{
    for(int i = a1; i < MAX_POSITION_NUM; ++i)
    {
        discs[i] = V;
    }

    discs[e4] = B;
    discs[d5] = B;
    discs[d4] = W;
    discs[e5] = W;
}

namespace
{
    Disc nullDisc = V;
}

Disc& Board::at(Position position)
{
    if(position < a1 || position > h8) return nullDisc;

    return discs[position];
}

namespace
{
    char to_c(Disc disc)
    {
        switch(disc)
        {
            case V: return 'V';
            case B: return 'B';
            case W: return 'W';
            default: return 'V';
        }
    }
}

void Board::print() const
{
    for(int i = a1; i < MAX_POSITION_NUM; ++i)
    {
        if(i % 8 == 0) 
            std::cout << "\n";

        std::cout << to_c(discs[i]) << ",";
    }

    std::cout << "\n";
}

void Board::turn(Position p)
{
    if( DiscUtil::isBlackDisc(at(p)) ) 
    {
        discs[p] = W;
        return;
    }

    if( DiscUtil::isWhiteDisc(at(p)) ) 
    {
        discs[p] = B;
    }
}

void Board::reset()
{
    init();
}