// menu.cpp
#include "menu.h"
#include "base.h"
#include <string>

int score = 0;

GameState menu()
{
    SDL_Texture *playButton = loadTexture("Assets/Graphics/play_btn.png");

    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                return QUIT;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);

                // Assuming button is placed at (200, 200) with size 240x60
                if (x > 200 && x < 440 && y > 200 && y < 260)
                {
                    return GAMEPLAY;
                }
            }
        }

        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
        SDL_RenderClear(gRenderer);

        SDL_Rect renderQuad = {200, 200, 240, 60};
        SDL_RenderCopy(gRenderer, playButton, NULL, &renderQuad);

        SDL_RenderPresent(gRenderer);
    }

    SDL_DestroyTexture(playButton);
    return GAMEPLAY;
}

GameState gameplay()
{
    SDL_Texture *sprite = loadTexture("Assets/Graphics/player2.jpg");
    SDL_Texture *exit_btn = loadTexture("Assets/Graphics/exit_btn.jpg");
    int textSize = 32;
    float groundlevel = 400.0f;
    float spriteX = 100.0f; // Initial x position
    float spriteY = 100.0f; // Initial y position

    float velocityY = 0.0f; // Initial vertical velocity
    float gravity = 0.05f;  // Gravity force, adjust as needed

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                return QUIT;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);

                // Assuming button is placed at (200, 200) with size 240x60
                if (x > 640 && x < 440 && y > 0 && y < 60)
                {
                    quit = true;
                }
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    score++;
                    velocityY = -2.0f;
                }
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_SPACE && spriteY == groundlevel)
                {
                    score++;
                    velocityY = -2.0f; // Adjust this value for jump height
                }
            }
        }

        velocityY += gravity;
        spriteY += velocityY;

        if (spriteY >= 400)
        {
            spriteY = groundlevel;
            velocityY = 0;
        }

        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
        SDL_RenderClear(gRenderer);

        SDL_Rect renderQuad = {(int)spriteX, (int)spriteY, 200, 50};
        SDL_RenderCopy(gRenderer, sprite, NULL, &renderQuad);

        SDL_Rect exit_rect = {640, 0, 240, 60};
        SDL_RenderCopy(gRenderer, exit_btn, NULL, &exit_rect);

        renderText("Score: " + std::to_string(score), textSize, textSize);

        SDL_RenderPresent(gRenderer);
    }

    SDL_DestroyTexture(sprite);
    return MENU;
}

void renderText(const std::string &text, int x, int y)
{
    SDL_Color textColor = {0, 0, 0, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, text.c_str(), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);

    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_Rect renderQuad = {x, y, textWidth, textHeight};

    SDL_RenderCopy(gRenderer, textTexture, NULL, &renderQuad);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}
