#include "graphics.h"

void bresenham(int* base, int* step, int* acc, int* delta, int lim, int inc) {
    (*acc) += *delta;
    (*base)++;
    if (*acc > lim) {
        (*step) += inc;
        *acc -= lim;
    }
}

void fill_rect(SDL_Surface* surface, int x, int y, int w, int h, Uint32 pixel) {
    int r;
    int c;
    for (c = 0; c < w; c++) {
        for (r = 0; r < h; r++) {
            put_pixel(screen,c+x,r+y,pixel);
        }
    }
}

void draw_rect(SDL_Surface* surface, int x, int y, int w, int h, Uint32 pixel) {
    draw_line(surface, x, y, x+w, y, pixel);
    draw_line(surface, x+w, y, x+w, y+h, pixel);
    draw_line(surface, x+w, y+h, x, y+h, pixel);
    draw_line(surface, x, y+h, x, y, pixel);
}

void draw_line(SDL_Surface* surface, int x1, int y1, int x2, int y2, Uint32 pixel) {
    int dx = abs(x2 - x1) + 1;
    int dy = abs(y2 - y1) + 1;
    int delta, acc, x, y, lim;


    if (dx >= dy) { // |slope| <= 1, drawing left to right
        delta = dy;
        acc = delta / 2;
        lim = dx;
        if (x2 > x1) { // right
            if (y2 >= y1) { // down
                x = x1;
                y = y1;
                while (x <= x2) {
                    put_pixel(screen, x, y, pixel);

                    bresenham(&x, &y, &acc, &delta, lim, 1);
                }
            } else { // up
                x = x1;
                y = y1;
                while (x <= x2) {
                    put_pixel(screen, x, y, pixel);
                    bresenham(&x, &y, &acc, &delta, lim, -1);
                }
            }
        } else {
            draw_line(surface, x2, y2, x1, y1, pixel);
        }
    } else { // |slope| >= 1, drawing top to bottom
        delta = dx;
        acc = delta / 2;
        lim = dy;
        if (y2 > y1) { // down
            if (x2 >= x1) { // to the right
                x = x1;
                y = y1;
                while (y < y2) {
                    put_pixel(screen, x, y, pixel);

                    bresenham(&y, &x, &acc, &delta, lim, 1);
                }
            } else { // left
                x = x1;
                y = y1;
                while (y <= y2) {
                    put_pixel(screen, x, y, pixel);
                    bresenham(&y, &x, &acc, &delta, lim, -1);
                }
            }
        } else {
            draw_line(surface, x2, y2, x1, y1, pixel);
        }
    }
}

void draw_triangle(SDL_Surface* surface, int x1, int y1, int x2, int y2, int x3, int y3, Uint32 pixel) {
    draw_line(screen,x1,y1,x2,y2,pixel);
    draw_line(screen,x2,y2,x3,y3,pixel);
    draw_line(screen,x3,y3,x1,y1,pixel);
}

void fill_triangle(SDL_Surface* surface, int x1, int y1, int x2, int y2, int x3, int y3, Uint32 pixel) {
    // go from vertex to left and vertex to right, bresenhamming that, and drawing horizontal lines.
    // when you hit one of the base points, bresenham across the (slanted) base, drawing horizontal lines
    //      (conitnuing with the other bresenham)

    int xi, xf, y; // these correspond to the points that iterate over the edges.


    // organize points
    int vx, vy, lx, ly, rx, ry;


    if (y1 >= y2 && y1 >= y3) {
        vy = y1;
        vx = x1;
        if (x2 >= x3) {
            rx = x2;
            ry = y2;
            lx = x3;
            ly = y3;
        } else {
            rx = x3;
            ry = y3;
            lx = x2;
            ly = y2;
        }
    } else if (y2 >= y1 && y2 >= y3) {
        vy = y2;
        vx = x2;
        if (x1 >= x3) {
            rx = x1;
            ry = y1;
            lx = x3;
            ly = y3;
        } else {
            rx = x3;
            ry = y3;
            lx = x1;
            ly = y1;
        }
    } else if (y3 >= y2 && y3 >= y1) {
        vy = y3;
        vx = x3;
        if (x1 >= x2) {
            rx = x1;
            ry = y1;
            lx = x2;
            ly = y2;
        } else {
            rx = x2;
            ry = y2;
            lx = x1;
            ly = y1;
        }
    } else {
        printf("gggggg\n");
    }

    // note: vertex is at the physical bottom of the triangle
    int accl, deltal, liml, *basel, *stepl, incl, accr, deltar, limr, *baser, *stepr, incr, accb, deltab, limb, *baseb, *stepb, incb;

    // void bresenham(int* base, int* step, int* acc, int* delta, int lim, int inc) base increments every time.

    if (ly > ry) { // R: v -> r, L: v -> l -> r

        // assign helper variables


        if ( vx > rx ) {
            incr = 1;
        } else {
            incr = -1;
        }

        if ( (vy - ry) >= incr * (vx - rx) ) { // more rise than run
            deltar = incr * (vx - rx);
            accr = deltar / 2;
            limr = vy - ry;
            baser = &y;
            stepr = &x; // goes up down, steps on x.
        } else { // more run than rise
            deltar = vy - ry;
            accr = deltar / 2;
            limr = incr * (vx - rx);
            baser = &x;
            stepr = &x;
        }



        while (y > yl) {

        }

        while (y > yr) {

        }


    } else { // R: v -> r -> l, L: v -> l










    }









}

void draw_circle(SDL_Surface* surface, int mx, int my, int r, Uint32 pixel) {
    int x = 0, y = r; // starting from the top, going x+ and y-

    while (x <= y) {
        put_pixel(surface, mx+x, my+y, pixel); // I
        put_pixel(surface, mx+y, my+x, pixel); // II
        put_pixel(surface, mx+y, my-x, pixel); // III
        put_pixel(surface, mx+x, my-y, pixel); // IV
        put_pixel(surface, mx-x, my+y, pixel); // V
        put_pixel(surface, mx-y, my+x, pixel); // VI
        put_pixel(surface, mx-y, my-x, pixel); // VII
        put_pixel(surface, mx-x, my-y, pixel); // VIII

        if ( ((x)*(++x) + y*y) > (r*r) + r ) {
            --y;
        }
    }

}

void swap(int* x, int* y) {
    int holder = *x;
    *x = *y;
    *y = holder;
}
