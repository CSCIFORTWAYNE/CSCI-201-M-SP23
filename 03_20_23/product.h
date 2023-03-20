#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <sstream>
#include <iomanip>

class product
{
public:
    product(double, std::string, int);
    int getProdNum() const;
    std::string getDescription() const;
    double getPrice() const;
    void purchase();
    void setPrice();
    void setDescription();
    friend std::ostream &operator<<(std::ostream &, const product &);

protected:
    double price;
    std::string description;
    int prodNum;
    bool isPurchased;
    std::string toString() const;
};
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
class donut : public product
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
    friend std::ostream &operator<<(std::ostream &, const donut &);

private:
    icingType icing;
    toppingType topping;
    drizzleType drizzle;
    static int nextProdNum;
    std::string toString() const;
};
enum baseType
{
    COFFEE,
    TEA,
    CREAM
};
enum tempType
{
    HOT,
    ICE,
    BLEND
};
enum sizeType
{
    SMALL,
    MED,
    LARGE
};
// modify drink to inherit from product.
class drink
{
public:
    drink(baseType, tempType, sizeType, std::string dairy, std::string flavor); // this one
    std::string getBaseStr();
    std::string getTemperature();
    std::string getSize();
    std::string getDairy();
    std::string getFlavor();
    double getPrice(); // this one
    void setBase(baseType);
    void setTemperature(tempType);
    void setSize(sizeType);
    void setDairy(std::string);
    void setFlavor(std::string);
    friend std::ostream &operator<<(std::ostream &, const drink &); // this one

private:
    baseType base;
    tempType temperature;
    sizeType size;
    std::string dairy;
    std::string flavor;
    std::string toString() const; // this one
};

#endif