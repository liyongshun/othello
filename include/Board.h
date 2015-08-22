#ifndef _OTHELLO_BOARD_H_
#define _OTHELLO_BOARD_H_

#include "Position.h"

struct Board
{
    Board();
    Board(const Disc*);
    void trueOver(Position);
    void place(Position, Disc);
    Board& operator=(const Board&);

    Disc at(Position) const;
    bool isOccupied(Position) const;
    bool operator==(const Board& rsh) const;
    void print() const;

    static bool onBoard(Position);

private:
    void init();

private:
    Disc discs[MAX_POSITION_NUM];
};

#endif
