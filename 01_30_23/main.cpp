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
    hr = inputInt("Enter the hour on the clock: ");
    min = inputInt("Enter the minutes on the clock: ");
    sec = inputInt("Enter the seconds on the clock: ");

    while (true)
    {
        try
        {
            clock.setTime(hr, min, sec, PM);
        }
        catch (clockHrExcept e)
        {
            std::cout << e.what() << " Enter a new value for the hour." << std::endl;
            hr = inputInt("Enter the hour on the clock: ");
            continue;
        }
        catch (std::invalid_argument e)
        {
            std::cout << "There was an exception thrown during setTime. " << e.what() << std::endl;
            clock.setTime(12, 0, 0, PM);
            break;
        }
        break;
    }
    std::cout << "After the try/catch." << std::endl;
    hr = inputInt("Enter the hour on the clock: ");
    min = inputInt("Enter the minutes on the clock: ");
    sec = inputInt("Enter the seconds on the clock: ");
    try
    {
        clockType clock2(hr, min, sec, AM);
        if (clock.equalTime(clock2))
        {
            std::cout << "The two clocks are equal" << std::endl;
        }
    }
    catch (std::invalid_argument e)
    {
        std::cout << "There was an exception thrown during construction. " << e.what() << std::endl;
        // clock2.setTime(12, 0 , 0, AM);
    }

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
