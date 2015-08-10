#include "Moves.h"

Moves::Moves()
{
}

void Moves::push(Position position)
{
    moves.push_back(position);
}

Position Moves::pop()
{
    if(isEmpty()) return MAX_POSITION_NUM;

    Position front = moves.front();
    moves.pop_front();
    return front;
}

size_t Moves::size() const
{
    return moves.size();
}

void Moves::clear()
{
    moves.clear();
}

bool Moves::isEmpty() const
{
    return moves.empty();
}

bool Moves::contains(Position p) const
{
    std::list<Position>::const_iterator iter;
    for(iter = moves.begin(); iter != moves.end(); ++iter)
    {
        if(*iter == p) return true;
    }

    return false;
}