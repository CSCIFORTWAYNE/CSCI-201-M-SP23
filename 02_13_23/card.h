#ifndef CARD_H
#define CARD_H
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

enum suitType
{
    HEART,
    DIAMOND,
    SPADE,
    CLUB
};
enum rankType
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    JOKER = 25
};

class card
{
public:
    card(suitType, rankType);
    card(std::string, std::string);
    std::string getSuitStr();
    std::string getRankStr();
    suitType getSuit();
    rankType getRank();
    std::string toString();
    static std::map<suitType, std::string> suitToStr;
    static std::map<rankType, std::string> rankToStr;
    static std::map<std::string, suitType> strToSuit;
    static std::map<std::string, rankType> strToRank;
    static std::set<suitType> suits;
    static std::set<rankType> ranks;

private:
    suitType suit;
    rankType rank;
};

#endif