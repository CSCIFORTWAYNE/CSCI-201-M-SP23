#ifndef CLOCKE_H
#define CLOCKE_H
#include <string>

class clockHrExcept
{
    public:
    clockHrExcept();
    std::string what();
    private:
    std::string msg;

};
class clockMinExcept
{

};
class clockSecExcept
{

};


#endif