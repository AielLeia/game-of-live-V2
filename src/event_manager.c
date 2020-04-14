#include <stdio.h>

#include "event_manager.h"

void mouse_clicked( GameOfLive *gol, const int row, const int column ) {
    if (gol->board[row * N + column] == ALIVE)  gol->board[row * N + column] = DEAD;
    else                                        gol->board[row * N + column] = ALIVE;
}