#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include "clockType.h"
#include "clockExcept.h"

void resetStream();
int inputInt(std::string);

int main()
{
    int hr, min, sec;
    timeOfDayType t = AM;
    clockType clock;
    clock.setTime(1, 00, 00, PM);
    clockType clock2;
    clock2.setTime(11, 34, 00, AM);
    int x = 7;
    int y = 3;
    std::cout << x - y << std::endl;
    std::cout << "The difference between the clocks: " << clock - clock2 << " seconds" << std::endl;
    clock2 = clock2 + 600;
    clock2 = 600 + clock2;
    std::cout << clock2 << std::endl;
    if (clock2 < clock)
        std::cout << "Clock 2 is less than clock 1." << std::endl;

    if (clock2 <= clock)
        std::cout << "Clock 2 is less than or equal to clock 1." << std::endl;

    if (clock2 != clock)
        std::cout << "Clock 2 is not equal to clock 1." << std::endl;

    clockType clock4 = clock--;

    clockType clock3;
    try
    {
        std::cout << "Enter the time on the clock hours minutes seconds: ";
        std::cin >> clock3;
        std::cout << std::endl;
        while (!std::cin)
        {
            resetStream();
            std::cout << "Enter the time on the clock hours minutes seconds: ";
            std::cin >> clock3;
            std::cout << std::endl;
        }
    }
    catch (...)
    {
        std::cout << "The data you entered is invalid." << std::endl;
    }
    std::cout << clock3 << std::endl;
    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

int inputInt(std::string prompt)
{
    int x;
    std::cout << prompt;
    std::cin >> x;
    std::cout << std::endl;
    while (!std::cin)
    {
        resetStream();
        std::cout << prompt;
        std::cin >> x;
        std::cout << std::endl;
    }
    return x;
}
