#include "animal.h"

void Animal::id()
{
    std::cout << "animal ";
}

void Dog::id()
{
    std::cout << "dog ";
}

void Rat::id()
{
    std::cout << "rat ";
}

void Cat::id()
{
    std::cout << "cat ";
}

void Cat::eat()
{
    std::cout << "eating a rat" << std::endl;
}

void Dog::eat()
{
    std::cout << "eating kibble" << std::endl;
}
void Rat::eat()
{
    std::cout << "eating corn" << std::endl;
}
