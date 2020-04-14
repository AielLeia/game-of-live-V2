#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include "live.h"
#include "render_manager.h"
#include "updater_manager.h"
#include "event_manager.h"
#include "event_keyboard_manager.h" 

int main (int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to load the video subsystem: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Window *win = SDL_CreateWindow(
        "Game of live",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_W,
        SCREEN_H,
        SDL_WINDOW_SHOWN
    );
    if (win == NULL) {
        SDL_Log("Failed to open the main window: %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(
        win,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if (ren == NULL) {
        SDL_Log("Loading the redering faile: %s", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_Event e;
    QuitState quit = { .quit = FALSE, .start = FALSE };
    GameOfLive game;
    for (int i = 0; i < N * N; i++) game.board[i] = DEAD;

    while (!quit.quit) {
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit.quit = TRUE;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                mouse_clicked(
                    &game,
                    e.button.y / CELL_H,
                    e.button.x / CELL_W
                );
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_s) {
                    quit.start = !quit.start;
                } else {
                    for (int i = 0; i < N * N; i++) game.board[i] = DEAD;
                    quit.start = FALSE;
                    keyboard_pressed(
                        &game, &e.key.keysym.sym
                    );
                }
            }
        }

        if (quit.start) {
            update( &game );
            SDL_Delay( 100 );
        }
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderClear(ren);
        render(ren, &game);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}