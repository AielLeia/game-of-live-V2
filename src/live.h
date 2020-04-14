#ifndef _LIVE_H_
#define _LIVE_H_

#define N           100

#define SCREEN_W    800
#define SCREEN_H    600

#define CELL_W      ((SCREEN_W) / (N))
#define CELL_H      ((SCREEN_H) / (N))

#define TRUE        1
#define FALSE       0

typedef enum _State {
    DEAD, ALIVE
} State;

typedef struct _QuitState {
    unsigned quit:1;
    unsigned start:1;
} QuitState;

typedef struct _GameOfLive {
    State board[N * N];
} GameOfLive;

#endif