#include "drink.h"
#include "order.h"
#include <iostream>
#include <climits>
#include <cstdlib>
const int MAX_SIZE = 100;

int size(int[], int);
void resetStream();
drink **getDrinks(drink **, int &);
donut *getDonuts(donut *, int &);
int main()
{
    char more = 'Y';
    drink **d;
    donut *donuts;
    order **o;
    int numDonuts;
    int numDrinks;
    int numOrders;
    std::cout << "How many orders are you placing? ";
    std::cin >> numOrders;
    std::cout << std::endl;
    while (numOrders < 0 || !std::cin)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "How many drinks do you want to order? ";
        std::cin >> numOrders;
        std::cout << std::endl;
    }
    o = new order *[numOrders];
    int count = 0;
    while (count < numOrders)
    {
        // gather drink information
        d = getDrinks(d, numDrinks);
        donuts = getDonuts(donuts, numDonuts);
        o[count++] = new order(donuts, numDonuts, d, numDrinks);
        // d[count++] = new drink(COFFEE, ICE, SMALL, "cream", "raspberry");
        more = 'N';
    }
    std::cout << "here" << std::endl;
    // loop through and print the orders

    /*int num[MAX_SIZE] = {4, 7, 11};
    int *intptr;
    int i = 0;
    while (true)
    {
        if (num[i] == 0)
        {
            intptr = &num[i];
            break;
        }
        i++;
    }

    // int size = (intptr - num);
    std::cout << num << std::endl;
    // std::cout << size << std::endl;
    for (int i = 0; i < size(num, MAX_SIZE); i++)
    {
        std::cout << num[i] << std::endl;
    }*/
    return 0;
}

int size(int num[], int max)
{

    int *intptr;
    for (int i = 0; i < max; i++)
    {
        if (num[i] == 0)
        {
            intptr = &num[i];
            break;
        }
    }
    return intptr - num;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

drink **getDrinks(drink **drinks, int &numDrinks)
{
    // ask the user for the number of drinks, validate, and dynamically allocate the array
    for (int i = 0; i < numDrinks; i++)
    {
        baseType b = static_cast<baseType>(rand() % 3);
        sizeType s = static_cast<sizeType>(rand() % 3);
        tempType t = static_cast<tempType>(rand() % 3);
        std::string dairy = "milk";
        std::string flavor = "raspberry";
        // use the new operator to dynamically allocate a drink to put into the array
    }
    return drinks;
}

donut *getDonuts(donut *donuts, int &numDonuts)
{
    numDonuts = rand() % 24 + 1;
    donuts = new donut[numDonuts];
    for (int i = 0; i < numDonuts; i++)
    {
        std::string ice = iceStr[rand() % 7];
        std::string top = topStr[rand() % 16];
        std::string driz = drizzleStr[rand() % 6];
        try
        {
            donuts[i].setIcing(ice);
            donuts[i].setTopping(top);
            donuts[i].setDrizzle(driz);
        }
        catch (...)
        {
            continue;
        }
    }
    return donuts;
}
