#include "Move.h"

#include <cassert>

#include "../Constants.h"


Move::Move(int _from, int _to) : from(_from),to(_to)
{
    assert (_from >= 0 && _from < CELLS && _to >= 0 && _to < CELLS);
}

int Move::getFrom() const
{
    return from;
}

int Move::getTo() const
{
    return to;
}
