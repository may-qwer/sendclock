#include "clock.hpp"
#include <iostream>

using namespace std;

#define H_FIRST_CAVE 1
#define W_FIRST_CAVE 1
#define H_LIM_OF_CAVE 8
#define W_LIM_OF_CAVE 8
#define H_LIM_OF_COORD 17
#define W_LIM_OF_COORD 14

Clock::Clock(const int w, const int h) : w_max_cave(13), done(false) {
    width = w;
    height = h;
    h_cave = H_FIRST_CAVE;
    w_cave = W_FIRST_CAVE;
    mtx = new char*[height];
    for (int i = 0; i < height; i++) {
        mtx[i] = new char[width];
    }
    set_mxt();
    set_send();
}

Clock::Clock(const Clock& o_clock) {
    width = o_clock.width;
    height = o_clock.height;
    h_cave = o_clock.h_cave;
    w_cave = o_clock.w_cave;
    w_max_cave = o_clock.w_max_cave;
    done = o_clock.done;
    mtx = new char*[height];
    for (int i = 0; i < height; i++) {
        mtx[i] = new char[width];
    }
    for (int i = 0; i < height; i ++) {
        for (int j = 0; j < width; j ++) {
            mtx[i][j] = o_clock.mtx[i][j];
        }
    }
}

Clock& Clock::operator=(const Clock& o_clock) {
    if (this == &o_clock) {
        return *this;
    }
    return *(new Clock(*this));
}

Clock::~Clock() {
    for(int i = 0; i < width; i++) {
        delete [] mtx[i];
    }
    delete [] mtx;
    // delete mtx;
}

void Clock::set_mxt() {
    int grid_index = -1;
    int sum = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i == 0) || (i == height-1)) {
                mtx[i][j] = '#';
            } else if ((i == height/2-1) || (i == height/2)) {
                if (j == (width-1)/2) {
                    mtx[i][j] = '#';
                } else {
                    mtx[i][j] = ' ';
                }
            } else {
                if ((j == grid_index) || (j == width-grid_index-1)) {
                    mtx[i][j] = '#';
                    continue;
                } else {
                    mtx[i][j] = ' ';
                }
            }
            
        }
        grid_index += sum;
        if (grid_index == height/2-1) {
            grid_index = 7;
            sum = -1;
        }
    }
}

void Clock::set_send() {
    int w_lim = 14;
    for (int i = 1; i < 8; i++) {
        for (int j = i; j < w_lim ; j++) {
            mtx[i][j] = '*';
        }
        w_lim--;
    }
}

void Clock::show() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << mtx[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Clock::move_next_cave() {
    mtx[H_LIM_OF_COORD - h_cave][W_LIM_OF_COORD - w_cave] = mtx[h_cave][w_cave];
    mtx[h_cave][w_cave] = ' ';
    w_cave++;
    if (w_cave > w_max_cave) {
        h_cave++;
        w_max_cave--;
        w_cave = h_cave;
        if ((h_cave == H_LIM_OF_CAVE) && (w_cave == W_LIM_OF_CAVE)) {
            done = true;
        }
    }
}

bool Clock::is_done() {
    return done;
}

