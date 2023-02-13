#include "card.h"

card::card(suitType s, rankType r)
{
    suit = s;
    rank = r;
}

card::card(std::string s, std::string r)
{
    std::string scpy = s;
    std::string rcpy = r;
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    std::transform(r.begin(), r.end(), r.begin(), ::toupper);
    if (!strToSuit.count(s))
    {
        throw std::invalid_argument(scpy + " is not a valid suit.");
    }
    suit = strToSuit[s];
    rank = strToRank[r];
}

std::string card::getSuitStr()
{
    return suitToStr[suit];
}

std::string card::getRankStr()
{
    return rankToStr[rank];
}

suitType card::getSuit()
{
    return suit;
}

rankType card::getRank()
{
    return rank;
}

std::string card::toString()
{
    return rankToStr[rank] + suitToStr[suit];
}

std::map<suitType, std::string> card::suitToStr = {{HEART, "♥"},
                                                   {DIAMOND, "♦"},
                                                   {SPADE, "♠"},
                                                   {CLUB, "♣"}};
std::map<rankType, std::string> card::rankToStr = {}; // fill in for lecture activity
std::set<suitType> card::suits = {HEART,
                                  DIAMOND,
                                  SPADE,
                                  CLUB};
std::set<rankType> card::ranks = {ACE,
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
                                  JOKER};

std::map<std::string, suitType> card::strToSuit = {{"HEART", HEART},
                                                   {"HEARTS", HEART},
                                                   {"DIAMOND", DIAMOND},
                                                   {"DIAMONDS", DIAMOND},
                                                   {"SPADE", SPADE},
                                                   {"SPADES", SPADE},
                                                   {"CLUB", CLUB},
                                                   {"CLUBS", CLUB}};
std::map<std::string, rankType> card::strToRank = {}; // fill in for lecture activity