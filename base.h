#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Function to render text as a texture
SDL_Texture *renderText(const char *message, const char *fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

// Function to load an image as a texture
SDL_Texture *loadTexture(const char *path, SDL_Renderer *renderer);

// Dummy function to illustrate rendering rectangles (to be implemented)
void drawRect();
