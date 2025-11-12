#include <iostream>
#include <chrono>
#include <thread>
#include "classes/clock.hpp"
#include "classes/time.hpp"

using namespace std;

#define WIDTH 15
#define HEIGHT 18
#define COUNT_OF_CAVES 49

int main() {

    int time = 10;// sec
    int time_dilay = int(time*1000/COUNT_OF_CAVES);
    Clock cl(WIDTH, HEIGHT);
    while (!cl.is_done()) {
        this_thread::sleep_for(chrono::milliseconds(time_dilay));
        cl.move_next_cave();
        cl.show();
    }
    return 0;
}