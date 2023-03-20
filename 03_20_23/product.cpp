#include "product.h"

int donut::nextProdNum = 0;

donut::donut() : product(1.25, "Standard Donut", ++nextProdNum + 100)
{
    this->icing = NOICE;
    this->topping = NOTOP;
    this->drizzle = NODRIZZLE;
}

donut::donut(std::string icing, std::string topping, std::string drizzle) : product(1.25, "Speciality Donut", ++nextProdNum + 100)
{
    // fill in rest of constructor
}

std::string donut::toString() const
{
    std::ostringstream out;
    out << product::toString() << " ";
    out << "Icing: None, Topping: None, Drizzle: None";
    return out.str();
}

product::product(double price, std::string desc, int prodNum)
{
    this->price = price;
    this->description = desc;
    this->prodNum = prodNum;
}

double product::getPrice() const
{
    return price;
}

void product::purchase()
{
    isPurchased = true;
}

std::string product::toString() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << description << " $" << price;
    return out.str();
}

std::ostream &operator<<(std::ostream &o, const product &p)
{
    o << p.toString();
    return o;
}

std::ostream &operator<<(std::ostream &o, const donut &d)
{
    o << d.toString();
    return o;
}
