//
// Created by shawnunili on 2019/3/25.
//

#ifndef CPP_TOOLS_TIME_CAL_H
#define CPP_TOOLS_TIME_CAL_H

#include <ctime>

namespace xct {
    // 将mysql date_time字符串转为时间戳
    time_t stringToDatetime(const char* strTime);
    // 将时间戳转化为年月日
    void datetimeToString(time_t time);

    void test_time();
}
#endif  // CPP_TOOLS_TIME_CAL_H
