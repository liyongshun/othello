#ifndef _OTHELLO_CPP_OTHELLO_H_
#define _OTHELLO_CPP_OTHELLO_H_

#include "Board.h"
#include "Moves.h"

typedef Position (*Move)(Position);

struct Othello
{
    void findMoves(Position);
    const Moves& getMoves(Position) const;
    void turn();

private:
    bool moveOn(Position curr, Position moves);
    void doTurn(Position curr, Position moves);
    void find(Position, Move firstStep, Move secondStep);
private:
    Board board;
    Moves moves[MAX_POSITION_NUM];
    Moves turns[MAX_POSITION_NUM];
};

#endif
