#include <iostream>
#include <string>
#include <algorithm>
#include "clockType.h"


void resetStream();


int main()
{
    int hr, min, sec;
    timeOfDayType t = AM;
    clockType clock(3, 11, 00, PM);
    clock.printTime();
    clockType clock2;
    clock2.printTime();
    clock2.setTime(2, 30, 0, PM);
    clock2.printTime();
    clock.getTime(hr, min, sec, t);
    std::cout << "Hour: " << hr << std::endl;
    std::cout << "Minutes: " << min << std::endl;
    std::cout << "Seconds: " << sec << std::endl;
    std::cout << "AM/PM: " << timeOfDayStr[t] << std::endl;
    clockType myClocks[10];
    

    std::string s = "HELLO";
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::getline(std::cin >> std::ws, s);

    return 0;
}

void resetStream()
{

}


