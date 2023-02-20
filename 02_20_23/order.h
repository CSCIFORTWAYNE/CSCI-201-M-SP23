#ifndef ORDER_H
#define ORDER_H
#include "drink.h"
#include "donut.h"
#include <string>
#include <sstream>
#include <iomanip>

class order
{
public:
    order(const donut *const donuts, int numDonuts, drink **const drinks, int numDrinks);
    order(const order &otherOrder);
    std::string tostring();
    ~order();

private:
    donut *donuts;
    int numDonuts;
    drink **drinks;
    int numDrinks;
};

#endif