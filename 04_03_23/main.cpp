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
    }
    return 0;
}