#include "test.h"

int main(int argv, char* argc[]) {
    init();
    open_window(800,640);

    clock_t start = clock(), elapsed;

    elapsed = clock();

    while (elapsed - start < 1000000) {
        elapsed = clock();
    }


    close_window();
    quit(0);
    return 0; // quiets warnings. quit() exits already.
}
