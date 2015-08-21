#ifndef _OTHELLO_MOVES_H_
#define _OTHELLO_MOVES_H_

#include <list>
#include "Position.h"

struct Moves
{
    Moves(std::initializer_list<Position> list = {});

    void push(Position);
    Position pop();
    void clear();
    Moves& operator+(const Moves&);

    bool isEmpty() const;
    bool operator==(const Moves&) const;

    void print() const;
    size_t size() const;
private:
    bool contains(Position) const;
private:
    std::list<Position> moves;
};

#endif
