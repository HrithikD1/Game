#include "menu.h"
#include "base.h"

void renderMenu(SDL_Renderer *renderer) {
    SDL_Color color = {0, 0, 0};

    // Load and render player image
    SDL_Texture *player = loadTexture("Assets/Graphics/player2.jpg", renderer);
    if (player) {
        SDL_Rect player_rect;
        player_rect.x = 620;
        player_rect.y = 320;

        int playerW = 0, playerH = 0;
        SDL_QueryTexture(player, NULL, NULL, &playerW, &playerH);
        player_rect.w = playerW; // width of the player image
        player_rect.h = playerH; // height of the player image

        SDL_RenderCopy(renderer, player, NULL, &player_rect);
        SDL_DestroyTexture(player); // Free player texture
    } else {
        printf("Failed to load player texture!\n");
    }

    // Render title text
    SDL_Texture *textTexture = renderText("Hello, SDL!", "font.ttf", color, 48, renderer);
    if (textTexture) {
        SDL_Rect textRect;
        textRect.x = 620; // x position
        textRect.y = 50;  // y position

        int texW = 0, texH = 0;
        SDL_QueryTexture(textTexture, NULL, NULL, &texW, &texH);
        textRect.w = texW; // width of the text
        textRect.h = texH; // height of the text

        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_DestroyTexture(textTexture); // Free text texture
    } else {
        printf("Failed to create title text texture!\n");
    }

    // Render enter text
    SDL_Texture *enterText = renderText("Press space to start!", "font.ttf", color, 48, renderer);
    if (enterText) {
        SDL_Rect text_Rect;
        text_Rect.x = 620; // x position
        text_Rect.y = 320; // y position

        int tex1W = 0, tex1H = 0;
        SDL_QueryTexture(enterText, NULL, NULL, &tex1W, &tex1H);
        text_Rect.w = tex1W; // width of the text
        text_Rect.h = tex1H; // height of the text

        SDL_RenderCopy(renderer, enterText, NULL, &text_Rect);
        SDL_DestroyTexture(enterText); // Free enter text texture
    } else {
        printf("Failed to create enter text texture!\n");
    }
}

void handleMenuEvent(SDL_Event &e, bool &quit) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_RETURN: // Enter key
                std::cout << "Enter pressed!" << std::endl;
                e.type = SDL_QUIT;
                break;
            case SDLK_ESCAPE: // Escape key to quit
                quit = true;
                break;
            default:
                std::cout << "Key pressed: " << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
                break;
        }
    }
}
