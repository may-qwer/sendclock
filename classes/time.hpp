#ifndef TIME_H
#define TIME_H

class Time {
private:
    char* str_time;
    int int_time;

    int convert_str_to_int(const char* str);

    int get_len();

    bool is_correct_str_time();

public:
    Time();

    Time(const Time& o_time);

    Time& operator=(const Time& o_time);

    virtual ~Time();

    void enter_str_time();

    int get_int_time();
};

#endif