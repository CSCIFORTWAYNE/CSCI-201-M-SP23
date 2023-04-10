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
void Cat::play()
{
    std::cout << "kicks Odie off of the table" << '\n';
}

void Dog::play()
{
    std::cout << "chases his tail for hours" << '\n';
}

void Rat::play()
{
    std::cout << "finds cheese in a maze" << '\n';
}
void Cat::animalSound(bool sound)
{
    if (sound)
    {
        std::cout << "miaow" << std::endl;
    }
    else
    {
        std::cout << "cat is quiet" << std::endl;
    }
}
void Dog::animalSound(bool sound)
{
    if (sound)
    {
        std::cout << "woof" << std::endl;
    }
    else
    {
        std::cout << "dog is quiet" << std::endl;
    }
}
void Rat::animalSound(bool sound)
{
    if (sound)
    {
        std::cout << "squeak" << std::endl;
    }
    else
    {
        std::cout << "rat is quiet" << std::endl;
    }
}
