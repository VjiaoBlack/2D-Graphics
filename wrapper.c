#include "wrapper.h"

Uint32 get_pixel(SDL_Surface *surface, int x, int y) {
    int bpp = 4;
    Uint32 *p = (Uint32 *)surface->pixels + y * surface->pitch + x * bpp;
    return *p;
}

void put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel) {
    int bpp = 4;
    Uint32 *p = (Uint32 *)surface->pixels + y * surface->pitch + x * bpp;
    *p = pixel;
    return;
}

void init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    return;
}

void open_window(int width, int height) {
    screen = SDL_SetVideoMode(width, height, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL) {
        printf("Couldn't set screen mode %d x %d: %s\n", width, height, SDL_GetError());
        quit(1);
    }
    return;
}

void close_window() {
    SDL_FreeSurface(screen); // how to check if screen is initialized
    exit(0);
    return;
}

void quit(int code) {
    SDL_Quit();
    exit(1);
    return;
}
