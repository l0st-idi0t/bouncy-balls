#include <SDL2/SDL.h>
#include <iostream>
#include "ball.hpp"

#define WIDTH 640
#define HEIGHT 480

//global variables
bool running = true;

void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

void cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        logSDLError(std::cout, "SDL_Init");
    }

    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {
        logSDLError(std::cout, "SDL_CreateWindowAndRenderer");
    }

    SDL_SetWindowTitle(window, "bouncy balls");

    // while (running) {
    //     continue;
    // }

    cleanup(window, renderer);
    return 0;
}