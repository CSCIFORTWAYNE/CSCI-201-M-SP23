#ifndef DONUT_H
#define DONUT_H
#include <string>
#include <iostream>
#include <algorithm>
#include "donutExcept.h"
enum icingType
{
    CHOCOLATEICING,
    CARAMELICING,
    MAPLE,
    VANILLA,
    GLAZE,
    SPECIALICE,
    NOICE
};
enum toppingType
{
    RAINBOWSPR,
    CHOCOLATESPR,
    PEANUTS,
    COCONUT,
    OREO,
    BACON,
    GRAHAM,
    FRUITYPEBBLES,
    REESESPIECES,
    MMS,
    CANDYBAR,
    CHOCOLATECHIPS,
    SEASALT,
    CINSUGAR,
    POWDSUGAR,
    NOTOP
};
enum drizzleType
{
    CARAMELDRIZZLE,
    CHOCOLATEDRIZZLE,
    PEANUTBUTTER,
    RASPBERRY,
    SPECIALDRIZZLE,
    NODRIZZLE
};
const std::string iceStr[] = {"Chocolate", "Caramel", "Maple", "Vanilla", "Glaze", "Special", "None"};
const std::string topStr[] = {"Rainbow Sprinkles", "Chocolate Sprinkles", "Peanuts", "Coconut", "Oreo", "Bacon", "Graham Cracker", "Fruity Pebbles", "Reese's Pieces", "M&Ms", "Candy Bar", "Chocolate Chips","Sea Salt", "Cinnamon Sugar", "Powdered Sugar", "None"};
const std::string drizzleStr[] = {"Caramel", "Chocolate", "Peanut Butter", "Raspberry", "Special", "None"};
class donut
{
public:
    donut();
    donut(std::string icing, std::string topping, std::string drizzle);
    icingType getIcing();
    toppingType getTopping();
    drizzleType getDrizzle();
    void setIcing(std::string);
    void setTopping(std::string);
    void setDrizzle(std::string);
    std::string toString() const;

private:
    icingType icing;
    toppingType topping;
    drizzleType drizzle;
};

#endif