#ifndef CLOCK_H
#define CLOCK_H

class Clock {
private:
    char** mtx;
    int width;
    int height;
    int h_cave;
    int w_cave;
    int w_max_cave;
    bool done;

    void set_mxt();

    void set_send();

public:
    Clock(const int w, const int h);

    Clock(const Clock& o_clock);

    Clock& operator=(const Clock& o_clock);

    virtual ~Clock();

    void show();

    bool is_done();

    void move_next_cave();
};

#endif