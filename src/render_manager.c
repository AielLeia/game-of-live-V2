#include "render_manager.h"

const SDL_Color DEAD_COLOR  =   { .r = 255, .g = 255, .b = 255, .a = 255 };
const SDL_Color ALIVE_COLOR =   { .r = 0,   .g = 0,   .b = 0,   .a = 0 };

void cell( SDL_Renderer *renderer, const int row, const int column, const SDL_Color *color) {
    SDL_SetRenderDrawColor(
        renderer,
        color->r,
        color->g,
        color->b,
        color->a
    );
    
    SDL_Rect rect = {
        .x = row * CELL_W,
        .y = column * CELL_H,
        .w = CELL_W,
        .h = CELL_H
    };

    SDL_RenderFillRect(
        renderer,
        &rect
    );
}

void render_cell( SDL_Renderer *renderer, const State state, const int row, const int column ) {
    if (state == ALIVE) {
        cell(renderer, row, column, &ALIVE_COLOR);
    } else if (state == DEAD) {
        cell(renderer, row, column, &DEAD_COLOR);
    }
}

void render_grid( SDL_Renderer *renderer ) {
    SDL_SetRenderDrawColor(
        renderer,
        198, 236, 255, 255
    );

    for (int i = 1; i < N; i++) {
        //  Vertical line
        SDL_RenderDrawLine(
            renderer,
            i * CELL_W, 0,
            i * CELL_W, SCREEN_H
        );

        // Horizontal line
        SDL_RenderDrawLine(
            renderer,
            0,        i * CELL_H,
            SCREEN_W, i * CELL_H
        );
    }
}

void render( SDL_Renderer *renderer, const GameOfLive *gol ) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            render_cell(renderer, gol->board[i * N + j], j, i);
        }
    }
    render_grid( renderer );
}