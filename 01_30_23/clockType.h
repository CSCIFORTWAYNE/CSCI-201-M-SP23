#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "clockExcept.h"

enum timeOfDayType {AM, PM};
const std::string timeOfDayStr[] = {"AM", "PM"};

class clockType
{
public:
    clockType(int, int, int, timeOfDayType);
    clockType();
    void setTime(int, int, int, timeOfDayType);
    void getTime(int &, int &, int &, timeOfDayType&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &) const;

private:
    int hr;
    int min;
    int sec;
    timeOfDayType timeOfDay;
};

#endif
