#include "SDL.h"

SDL_Surface* screen;

Uint32 get_pixel(SDL_Surface *surface, int x, int y);

void put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

void init();

void open_window(int,int);

void close_window();

void quit(int);
