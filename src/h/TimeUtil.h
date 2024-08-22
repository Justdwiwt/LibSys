#ifndef LIBSYS_TIMEUTIL_H
#define LIBSYS_TIMEUTIL_H

#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <string>

#pragma once
using namespace std;

class TimeUtil {
public:
    TimeUtil();

    virtual ~TimeUtil();

    static void TimeToString(time_t time1, char *szTime);

    __attribute__((unused)) static time_t StringToTime(char *szTime);

    static string AddMonth(time_t &tTime);
};

#endif //LIBSYS_TIMEUTIL_H
