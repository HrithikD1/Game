// menu.h
#pragma once

#include <SDL2/SDL.h>

enum GameState { MENU, GAMEPLAY, QUIT };

GameState menu();
GameState gameplay();
void renderText(const std::string &text, int x, int y);  // This was already correct
