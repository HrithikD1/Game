// main.cpp
#include "base.cpp"
#include "menu.cpp"
#include <iostream>

int main(int argc, char* args[]) {
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        return -1;
    }

    if (!loadMedia()) {
        std::cout << "Failed to load media!" << std::endl;
        return -1;
    }

    GameState currentState = MENU;  // FIXED: Added the enum type

    while (currentState != QUIT) {  // FIXED: Loop for handling game state
        switch (currentState) {
            case MENU:
                currentState = menu();  // FIXED: Call the correct menu function
                break;
            case GAMEPLAY:
                currentState = gameplay();  // FIXED: Call the correct gameplay function
                break;
            default:
                currentState = QUIT;  // Ensure we exit the loop in case of unexpected state
                break;
        }
    }

    close();  // Cleanup resources
    return 0;
}
