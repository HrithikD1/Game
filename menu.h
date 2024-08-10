#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "base.h"

// Function to render all menu-related sprites
void renderMenu(SDL_Renderer* renderer);

// Function to handle menu-specific events
void handleMenuEvent(SDL_Event& e, bool &quit);

#endif // MENU_H
