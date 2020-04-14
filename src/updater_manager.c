#include "updater_manager.h"

State update_cell( const GameOfLive *gol, const int row, const int column ) {
    int nb = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        if (i >= 0 && i < N) {
            for (int j = column - 1; j <= column + 1; j++) {
                if (j >= 0 && j < N) {
                    if (i != row || j != column) {
                        if (gol->board[i * N + j] == ALIVE) {
                            nb++;
                        }
                    }
                }
            }
        }
    }

    if (gol->board[row * N + column] == ALIVE) {
        if (nb == 2 || nb == 3) {
            return ALIVE;
        } else {
            return DEAD;
        }
    } else {
        if (nb == 3) {
            return ALIVE;
        } else {
            return DEAD;
        }
    }
}

void update_board( GameOfLive *temp, const GameOfLive *gol ) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp->board[i * N + j] = update_cell(gol, i, j);
        }
    }
}

void copy( GameOfLive *dest, const GameOfLive *src ) {
    for (int i = 0; i < N * N; i++) {
        dest->board[i] = src->board[i];
    }
}

void update( GameOfLive *gol ) {
    static GameOfLive temp = { .board = {DEAD} };
    copy(&temp, gol);
    update_board( &temp, gol );
    copy(gol, &temp);
}