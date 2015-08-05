#include "Board.h"
#include <iostream>

Board::Board()
{
    init();
}

void Board::init()
{
    for(int i = a1; i < MAX_NUM; ++i)
    {
        grids[i] = V;
    }

    at(e4) = B;
    at(d5) = B;
    at(d4) = W;
    at(e5) = W;
}

Grid& Board::at(Position position)
{
    return grids[position];
}

namespace
{
    char to_c(Grid grid)
    {
        switch(grid)
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
    for(int i = a1; i < MAX_NUM; ++i)
    {
        if(i % 8 == 0) 
            std::cout << "\n";

        std::cout << to_c(grids[i]) << ",";
    }
}

void Board::turn(Position position)
{
    if(at(position) == B) 
    {
        at(position) = W;
        return;
    }

    if(at(position) == W) 
    {
        at(position) = B;
    }
}