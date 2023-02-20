#ifndef DONUTEXCEPT_H
#define DONUTEXCEPT_H
#include <string>

class invalid_icing
{
    private: 
    std::string msg;
    public:
    std::string what();
    invalid_icing(std::string);
};

class invalid_topping
{
    private: 
    std::string msg;
    public:
    std::string what();
    invalid_topping(std::string);
};

class invalid_drizzle
{
private: 
    std::string msg;
    public:
    std::string what();
    invalid_drizzle(std::string);
};


#endif