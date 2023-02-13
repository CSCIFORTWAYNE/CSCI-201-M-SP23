#include "card.h"
#include <vector>
#include <iostream>
#include <set>
#include <map>

int main()
{
    std::vector<card> deck;
    for (std::set<suitType>::iterator i = card::suits.begin(); i != card::suits.end(); i++)
    {
        for (std::set<rankType>::iterator j = card::ranks.begin(); j != card::ranks.end(); j++)
        {
            deck.push_back(card(*i, *j));
        }
    }

    for (int i = 0; i < deck.size(); i++)
    {
        std::cout << deck[i].toString() << std::endl;
    }
    card c("heart", "ace");
    std::cout << c.toString() << std::endl;

    std::random_shuffle(deck.begin(), deck.end());
    for (int i = 0; i < deck.size(); i++)
    {
        std::cout << deck[i].toString() << std::endl;
    }

    return 0;
}