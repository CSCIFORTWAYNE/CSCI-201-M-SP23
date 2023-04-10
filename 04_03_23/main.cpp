#include "animal.h"
#include <vector>

int main()
{
    std::vector<Animal *> a;
    a.push_back(new Dog());
    a.push_back(new Cat());
    // a.push_back(new Animal());
    a.push_back(new Rat());
    for (int i = 0; i < a.size(); i++)
    {
        a[i]->id();
        a[i]->eat();
        a[i]->id();
        a[i]->play();
        a[i]->animalSound(false);
    }
    std::cout << "Enter a animal name: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);
    std::cout << "The animal is named " << name << "." << std::endl;
    return 0;
}