#include "clockExcept.h"

clockHrExcept::clockHrExcept()
{
    msg = "The hour is invalid.";
}

std::string clockHrExcept::what()
{
    return msg;
}
