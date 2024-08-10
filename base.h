#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Function to render text as a texture
SDL_Texture *renderText(const char *message, const char *fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer) {
    // Load the font
    TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
    if (font == NULL) {
        printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
        return NULL;
    }

    // Create a surface with the text
    SDL_Surface *surface = TTF_RenderText_Solid(font, message, color);
    if (surface == NULL) {
        printf("Unable to render text surface! TTF_Error: %s\n", TTF_GetError());
        TTF_CloseFont(font);
        return NULL;
    }

    // Create a texture from the surface
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); // Free the surface as we now have the texture
    TTF_CloseFont(font); // Close the font as it is no longer needed

    if (texture == NULL) {
        printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
    }

    return texture;
}

// Function to load an image as a texture
SDL_Texture *loadTexture(const char *path, SDL_Renderer *renderer) {
    // Load the image file
    SDL_Texture *texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL) {
        printf("Unable to create texture from %s! SDL_Error: %s\n", path, SDL_GetError());
    }
    return texture;
}

// Dummy function to illustrate rendering rectangles (to be implemented)
void drawRect() {
    // Function body
}
