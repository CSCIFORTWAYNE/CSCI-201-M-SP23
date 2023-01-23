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
    if(h > 12 || h < 1)
    {
        std::cout << "The hour supplied is invalid.  The hour will be set to 12." << std::endl;
        h = 12;
    }
    if(m > 59 || m < 0)
    {
        std::cout << "The minutes supplied are invalid. The minutes will be set to 0." << std::endl;
        m = 0;
    }
    if(s > 59 || s < 0)
    {
        std::cout << "The seconds supplied are invalid. The seconds will be set to 0." << std::endl;
        s = 0;
    }
    hr = h;
    min = m;
    sec = s;
    timeOfDay = t;
    
}

void clockType::getTime(int &h, int &m, int &s, timeOfDayType& t) const
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
