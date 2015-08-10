#ifndef _OTHELLO_MOVES_H_
#define _OTHELLO_MOVES_H_

#include <list>
#include "Board.h"

struct Moves
{
    Moves();

    void push(Position);
    Position pop();
    size_t size() const;
    bool isEmpty() const;
    bool contains(Position) const;
    void clear();

private:
    std::list<Position> moves;
};

#endif
