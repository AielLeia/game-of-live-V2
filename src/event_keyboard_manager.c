#include <stdlib.h>
#include <time.h>

#include "event_keyboard_manager.h"
#include "config.h"

void set_board( GameOfLive *gol, const State *config, const int l, const int c, const int x, const int y) {
    for (int i = y; i < y + l; i++) {
        for (int j = x; j < x + c; j++) {
            gol->board[i * N + j] = config[(i - y) * c + (j - x)];
        }
    }
}

void random ( GameOfLive *gol ) {
    srand(time(0));
    for (int i = 0; i < N * N; i++) {
        gol->board[i] = (rand() % 2) == 1 ? DEAD : ALIVE; 
    }
}

void keyboard_pressed( GameOfLive *gol, const SDL_Keycode *keycode ) {
    switch (*keycode) {
        case SDLK_a: {
            set_board(
                gol,
                &A[0][0],
                A_L, A_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_c: {
            set_board(
                gol,
                &C[0][0],
                C_L, C_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_v: {
            set_board(
                gol,
                &V[0][0],
                V_L, V_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_b: {
            set_board(
                gol,
                &B[0][0],
                B_L, B_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_m: {
            set_board(
                gol,
                &M[0][0],
                M_L, M_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_l: {
            set_board(
                gol,
                &L[0][0],
                L_L, L_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_k: {
            set_board(
                gol,
                &K[0][0],
                K_L, K_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_j: {
            set_board(
                gol,
                &J[0][0],
                J_L, J_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_h: {
            set_board(
                gol,
                &H[0][0],
                H_L, H_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_g: {
            set_board(
                gol,
                &G[0][0],
                G_L, G_C,
                N / 2, N / 2
            );
            break;
        }
        case SDLK_f: {
            set_board(
                gol,
                &F[0][0],
                F_L, F_C,
                (N / 2) - 30, (N / 2) - 30
            );
            break;
        }
        case SDLK_q: {
            set_board(
                gol,
                &Q[0][0],
                Q_L, Q_C,
                (N / 2) - 30, (N / 2) - 30
            );
            break;
        }
        default: {
            random( gol );
        }
    }
}
