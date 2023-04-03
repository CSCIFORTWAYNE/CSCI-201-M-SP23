#include <iostream>

// lecture activity add 1 pure virtual function to animal and implement it for each derived class.
class Animal
{
public:
    virtual void id();
    virtual void eat() = 0;
};
class Cat : public Animal
{
public:
    virtual void id();
    void eat();
};
class Dog : public Animal
{
public:
    virtual void id();
    void eat();
};
class Rat : public Animal
{
    virtual void id();
    void eat();
};
