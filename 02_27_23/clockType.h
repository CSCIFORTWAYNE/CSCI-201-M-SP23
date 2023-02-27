#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cmath>
#include "clockExcept.h"

enum timeOfDayType
{
    AM,
    PM
};
const std::string timeOfDayStr[] = {"AM", "PM"};

class clockType
{
public:
    clockType(int, int, int, timeOfDayType);
    clockType();
    void setTime(int, int, int, timeOfDayType);
    void getTime(int &, int &, int &, timeOfDayType &) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &) const;
    int operator-(const clockType &);
    clockType &operator+(int secToAdd); // clock + int
    bool operator==(const clockType &rightOp) const;
    bool operator!=(const clockType &rightOp) const;
    bool operator<(const clockType &rightOp) const;
    bool operator<=(const clockType &rightOp) const;
    // add operator overloads for > and >=
    clockType operator++();
    clockType operator++(int);
    clockType operator--();
    clockType operator--(int);
    friend clockType &operator+(int secToAdd, clockType &rightOp); // allows for int + clock
    friend std::ostream &operator<<(std::ostream &, const clockType &);
    friend std::istream &operator>>(std::istream &, clockType &);

private:
    int hr;
    int min;
    int sec;
    timeOfDayType timeOfDay;
};

#endif
