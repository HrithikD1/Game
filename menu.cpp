#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "base.cpp"

void renderMenu(SDL_Renderer *renderer)
{
    SDL_Color color = {0, 0, 0};

    // Load and render background
    SDL_Texture *player = loadTexture("Assets/Graphics/player2.jpg", renderer);
    if (player)
    {

        SDL_Rect player_rect;
        player_rect.x = 620;
        player_rect.y = 320;

        int playerW = 0;
        int playerH = 0;
        SDL_QueryTexture(player, NULL, NULL, &playerW, &playerH);
        player_rect.w = playerW; // width of the text
        player_rect.h = playerH;
        SDL_RenderCopy(renderer, player, NULL, &player_rect);
        SDL_DestroyTexture(player); // Free background texture
    }
    else
    {
        printf("Failed to load play_btn texture!\n");
    }

    // Create the texture using renderText
    SDL_Texture *textTexture = renderText("Hello, SDL!", "font.ttf", color, 48, renderer);
    if (textTexture)
    {
        // Create an SDL_Rect to define the position and size of the text
        SDL_Rect textRect;
        textRect.x = 620; // x position
        textRect.y = 50;  // y position

        // Query the texture to get its width and height
        int texW = 0;
        int texH = 0;
        SDL_QueryTexture(textTexture, NULL, NULL, &texW, &texH);
        textRect.w = texW; // width of the text
        textRect.h = texH; // height of the text

        // Render the text texture to the screen at the specified position
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        // Destroy the texture when done
        SDL_DestroyTexture(textTexture);
    }
    else
    {
        printf("Failed to create text texture!\n");
    }
}
