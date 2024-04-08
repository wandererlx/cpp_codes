//
// Created by shawnunili on 2019/3/25.
//
#include <cstdio>
#include <string>
#include <iostream>
#include "time_cal.h"

time_t xct::stringToDatetime(const char* strTime) {
    if (NULL == strTime) {
        return 0;
    }
    tm tm_;
    int year, month, day, hour, minute, second;
    sscanf(strTime, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    tm_.tm_year = year - 1900;
    tm_.tm_mon = month - 1;
    tm_.tm_mday = day;
    tm_.tm_hour = hour;
    tm_.tm_min = minute;
    tm_.tm_sec = second;
    tm_.tm_isdst = 0;

    time_t t_ = mktime(&tm_); //已经减了8个时区
    return t_; //秒时间
}

void xct::datetimeToString(time_t time) {
    char s[100];
    char s2[3];
    time_t t = time + 28800;//8h 时区差
    struct tm* p;
    p = gmtime(&t);
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", p);
    strftime(s2, sizeof(s2), "%H", p);
    std::string hour(s2);
    // std::cout << hour << std::endl;
    printf(s);
}

void xct::test_time() {
    char s[100];
    time_t t;
    t = 1554898777;  // s
    datetimeToString(t);
//    printf("%ld: %s\n", t, s);
//    printf("%s", ctime(&t));
//    time_t t2 = t + 28800;
//    printf("%s", asctime(gmtime(&t2)));
    // printf("%s: %lld\n", s, StringToDatetime(s));
}
