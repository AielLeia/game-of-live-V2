#ifndef EVENT_KEYBOARD_MANAGER_H
#define EVENT_KEYBOARD_MANAGER_H

#include "live.h"
#include <SDL.h>

extern void keyboard_pressed( GameOfLive *gol, const SDL_Keycode *keycode );

#endif