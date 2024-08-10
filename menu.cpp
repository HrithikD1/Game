#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "base.cpp"

void renderMenu(SDL_Renderer* renderer) {
    SDL_Color color = {0, 0, 0};

    // Load and render background
    SDL_Texture* background = loadTexture("bkgrnd.png", renderer);
    if (background) {
        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_DestroyTexture(background); // Free background texture
    } else {
        printf("Failed to load background texture!\n");
    }

    // Render title text
    SDL_Texture* title = renderText("Title", "font.ttf", color, 32, renderer);
    if (title) {
        // Define the position and size of the text
        SDL_Rect textRect = {100, 50, 200, 50}; // Example position and size
        SDL_RenderCopy(renderer, title, NULL, &textRect);
        SDL_DestroyTexture(title); // Free title texture
    } else {
        printf("Failed to render title text!\n");
    }
}

