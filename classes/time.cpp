#include "time.hpp"
#include <iostream>
#include <cmath>

using namespace std;

#define MSG_TO_BIG_TIME "You enter to big time. It should be less than 999999. Try again: "
#define MGS_UNCORRECT_ENTER "Your enter isn't correct. Try again: "
#define STR_MAX_LIM 57
#define STR_MIN_LIM 48
#define CONST_ASCII 48

Time::Time() : int_time(0) {
    str_time = new char[6];
}

Time::Time(const Time& o_time) {
    str_time = new char[6];
    for (int i = 0; i < 6; i++) {
        str_time[i] = o_time.str_time[i];
    }
}

Time& Time::operator=(const Time& o_time) {
    if (this == &o_time) {
        return *this;
    }
    return *(new Time(*this));
}

Time::~Time() {
    delete [] str_time;
}

void Time::enter_str_time(const char* msg)  {
    cout << msg << endl;
    cin >> str_time;
    if (get_len() > 6) {
        enter_str_time(MSG_TO_BIG_TIME);
        return;
    }
    for (int i = 0; i < get_len(); i++) {
        if ((int(str_time[i]) < STR_MIN_LIM) || (int(str_time[i]) > STR_MAX_LIM)) {
            enter_str_time(MGS_UNCORRECT_ENTER);
            return;
        }
    }
}

int Time::get_int_time() {
    return convert_str_to_int();
}

int Time::convert_str_to_int() {
    int sum = 0;
    int tmp;
    int tens = pow(10, get_len() - 1);
    for (int i = 0; i < get_len(); i++) {
        tmp = int(str_time[i]) - CONST_ASCII;
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
