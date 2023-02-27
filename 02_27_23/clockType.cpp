#include "clockType.h"

clockType::clockType(int h, int m, int s, timeOfDayType t)
{
    setTime(h, m, s, t);
}

clockType::clockType()
{
    hr = 12;
    min = 0;
    sec = 0;
    timeOfDay = AM;
}

void clockType::setTime(int h, int m, int s, timeOfDayType t)
{
    if (h > 12 || h < 1)
    {
        clockHrExcept e;
        throw e;
    }
    if (m > 59 || m < 0)
    {
        throw std::invalid_argument("The minutes supplied are invalid.");
    }
    if (s > 59 || s < 0)
    {
        throw std::invalid_argument("The seconds supplied are invalid.");
    }
    hr = h;
    min = m;
    sec = s;
    timeOfDay = t;
}

void clockType::getTime(int &h, int &m, int &s, timeOfDayType &t) const
{
    h = hr;
    m = min;
    s = sec;
    t = timeOfDay;
}

void clockType::printTime() const
{
    std::cout << hr << ":" << min << ":" << sec << " " << timeOfDayStr[timeOfDay] << std::endl;
}
void clockType::incrementSeconds()
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
        incrementMinutes();
    }
}
void clockType::incrementMinutes()
{
    min++;
    if (min == 60)
    {
        min = 0;
        incrementHours();
    }
}
void clockType::incrementHours()
{
    hr++;
    if (hr == 13)
    {
        hr == 1;
        // timeOfDay = (timeOfDay == AM)? PM : AM;
        if (timeOfDay == AM)
        {
            timeOfDay = PM;
        }
        else
        {
            timeOfDay = AM;
        }
    }
}
bool clockType::equalTime(const clockType &c) const
{
    bool eq;
    eq = c.hr == hr;
    eq = eq && c.min == min;
    eq = eq && c.sec == sec;
    eq = eq && c.timeOfDay == timeOfDay;
    return eq;

    // return c.hr == hr && c.min == min && c.sec == sec && c.timeOfDay == timeOfDay;
}

int clockType::operator-(const clockType &clockToSub)
{
    int myHr = this->hr;
    int othHr = clockToSub.hr;
    if (this->timeOfDay == PM)
        myHr = myHr + 12;
    if (clockToSub.timeOfDay == PM)
        othHr = othHr + 12;
    int diffHr = abs(myHr - othHr);

    int diffMin = abs(this->min - clockToSub.min);
    int diffSec = abs(this->sec - clockToSub.sec);
    diffMin = diffMin + diffHr * 60;
    diffSec = diffSec + diffMin * 60;
    return diffSec;
}

clockType &clockType::operator+(int secToAdd)
{
    for (int i = 0; i < secToAdd; i++)
    {
        this->incrementSeconds();
    }
    return *this;
}

bool clockType::operator==(const clockType &rightOp) const
{
    return this->equalTime(rightOp);
}

bool clockType::operator!=(const clockType &rightOp) const
{
    return !(*this == rightOp);
}

bool clockType::operator<(const clockType &rightOp) const
{
    if (this->timeOfDay < rightOp.timeOfDay)
        return true;
    else if (this->timeOfDay > rightOp.timeOfDay)
        return false;
    else if (this->hr < rightOp.hr)
        return true;
    else if (this->hr > rightOp.hr)
        return false;
    else if (this->min < rightOp.min)
        return true;
    else if (this->min > rightOp.min)
        return false;
    else if (this->sec < rightOp.sec)
        return true;
    else
        return false;

    return false;
}

bool clockType::operator<=(const clockType &rightOp) const
{
    return *this < rightOp || *this == rightOp;
}

// friend function
clockType &operator+(int secToAdd, clockType &rightOp)
{
    return rightOp + secToAdd;
}
