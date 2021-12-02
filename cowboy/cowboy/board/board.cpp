#include "board.h"

board board::instance;

board::board()
{
}

board &board::get()
{
    return instance;
}
