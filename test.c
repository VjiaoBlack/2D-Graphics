#include "test.h"


void draw() {

    draw_rect(screen,xo,yo,100,100,pixel(200,100,100));

    draw_line(screen,100,100,200,167,pixel(200,200,200));
    draw_line(screen,200,167,133,267,pixel(200,200,200));
    draw_line(screen,133,267,33,200,pixel(200,200,200));
    draw_line(screen,33,200,100,100,pixel(200,200,200));



    draw_circle(screen,300,300,50,pixel(150,210,100));

    fill_triangle(screen,300,150,325,250,275,350,pixel(80,160,40));
    draw_triangle(screen,350,200,375,400,325,300,pixel(100,200,50));




}

int main(int argv, char* argc[]) {
    init();
    mspf = 1000 / FPS;
    xo = 0;
    yo = 0;

    open_window(800,640);
    SDL_WM_GrabInput(SDL_GRAB_ON);
    SDL_ShowCursor(1);

    struct timeval start, current;

    gettimeofday(&start, NULL);
    gettimeofday(&current, NULL);


    while ((current.tv_sec  - start.tv_sec ) < 2) {

        gettimeofday(&current, NULL);

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        draw();
        SDL_Flip(screen);


        xo++;
        yo++;
        // SDL_Delay(mspf);
    }




    close_window();
    quit(0);
    return 0; // quiets warnings. quit() exits already.
}

