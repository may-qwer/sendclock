#include "time.hpp"

Time::Time() int_time(0) {
    str_time = new char[6];
}

Time::Time(const Time& o_time) {
    str_time = new char[6];
    for (int i = 0; i < 6; i++) {
        str_time[i] = o_time.str_time[i];
    }
}

Time& Time::operator=(const Time& o_time) {
    if (this == o_time) {
        return *this;
    }
    return *(new Time(*this));
}

Time::~Time() {
    delete [] str_time;
}

void Time::enter_str_time();

int Time::get_int_time() {
    return int_time;
}

int Time::convert_str_to_int(const char* str) {
    int sum = 0;
    int tmp;
    int tens = 100000;
    for (int i = 0; i < get_len(); i++) {
        tmp = int(str[0]);
        sum += tens*tmp;
        tens /= 10;
    }
    return sum;
}

int Time::get_len() {
    int len = 0;
    while (str_time[len] != 0) {
        len++;
    }
    return len;
}

bool Time::is_correct_str_time() {
    if (get_len() > 6) {
        return false;
    }
    
}
    