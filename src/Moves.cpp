#include "Moves.h"
#include <iostream>

Moves::Moves(std::initializer_list<Position> list)
{
	for(auto iter = list.begin(); iter != list.end(); ++iter)
	{
		push(*iter);
	}
}

void Moves::push(Position position)
{
	if(contains(position)) return;

	moves.push_back(position);
}

Moves& Moves::operator+(const Moves& rhs)
{
	for(auto iter = rhs.moves.begin(); iter != rhs.moves.end(); ++iter)
	{
		push(*iter);
	}

	return *this;
}

Position Moves::pop()
{
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

bool Moves::operator==(const Moves& rsh) const
{
	if(size() != rsh.size()) return false;

	for(auto iter = rsh.moves.begin(); iter != rsh.moves.end(); ++iter)
	{
		if( ! contains(*iter)) return false;
	}

	return true;
}
