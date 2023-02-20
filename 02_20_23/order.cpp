#include "order.h"

order::order(const donut *const donuts, int numDonuts, drink **const drinks, int numDrinks)
{
    this->numDonuts = numDonuts;
    this->donuts = new donut[numDonuts];
    for (int i = 0; i < numDonuts; i++)
    {
        this->donuts[i] = donuts[i];
    }
    this->numDrinks = numDrinks;
    this->drinks = new drink *[numDrinks];
    for (int i = 0; i < numDrinks; i++)
    {
        this->drinks[i] = new drink(*(drinks[i]));
    }
}

order::order(const order &otherOrder)
{
    this->numDonuts = otherOrder.numDonuts;
    this->donuts = new donut[numDonuts];
    for (int i = 0; i < numDonuts; i++)
    {
        this->donuts[i] = otherOrder.donuts[i];
    }
    this->numDrinks = otherOrder.numDrinks;
    this->drinks = new drink *[numDrinks];
    for (int i = 0; i < numDrinks; i++)
    {
        this->drinks[i] = new drink(*(otherOrder.drinks[i]));
    }
}

std::string order::tostring()
{
    std::ostringstream out;
    out << std::setprecision(2) << std::showpoint << std::fixed;
    out << "Your order is summarized below: " << std::endl;
    out << "Donuts ordered: " << std::endl;
    for (int i = 0; i < numDonuts; i++)
    {
        out << donuts[i].toString() << std::endl;
    }
    out << "Drinks orderd:" << std::endl;
    for (int i = 0; i < numDrinks; i++)
    {
        out << drinks[i]->getSize() << " - " << drinks[i]->getTemperature() << ", " << drinks[i]->getBaseStr() << ", " << drinks[i]->getDairy() << ", " << drinks[i]->getFlavor()
            << " - $" << drinks[i]->getPrice() << std::endl;
    }
    return out.str();
}

order::~order()
{
    delete[] donuts;
    donuts = nullptr;
    for (int i = 0; i < numDrinks; i++)
    {
        delete drinks[i];
        drinks[i] = nullptr;
    }
    delete[] drinks;
    drinks = nullptr;
}
