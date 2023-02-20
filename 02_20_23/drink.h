#pragma once
#include <string>
#include <algorithm>
enum baseType {COFFEE, TEA, CREAM};
enum tempType {HOT, ICE, BLEND};
enum sizeType {SMALL, MED, LARGE};

const std::string baseStr[] = { "Coffee", "Tea", "Cream" };
const std::string tempStr[] = { "Hot", "Iced", "Blended" };
const std::string sizeStr[] = { "Small", "Medium", "Large" };
const baseType bases[] = {COFFEE, TEA, CREAM};
const tempType temps[] = {HOT, ICE, BLEND};
const sizeType sizes[] = {SMALL, MED, LARGE};

class drink
{
public:
	drink(baseType, tempType, sizeType, std::string dairy, std::string flavor);
	std::string getBaseStr();
	std::string getTemperature();
	std::string getSize();
	std::string getDairy();
	std::string getFlavor();
	double getPrice();
	void setBase(baseType);
	void setTemperature(tempType);
	void setSize(sizeType);
	void setDairy(std::string);
	void setFlavor(std::string);
	
private:
	baseType base;
	tempType temperature;
	sizeType size;
	std::string dairy;
	std::string flavor;
};

