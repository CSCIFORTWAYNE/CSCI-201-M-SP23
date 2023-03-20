#include "product.h"
#include <iostream>

int main()
{

    donut d;
    d.getPrice();
    product p(1.99, "Generic product", 289);
    std::cout << p << std::endl;
    std::cout << d << std::endl;
}