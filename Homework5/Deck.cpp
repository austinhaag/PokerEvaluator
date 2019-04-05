//
//  Deck.cpp
//  Homework5
//
//  Created by Austin Haag on 4/5/19.
//  Copyright © 2019 Austin Haag. All rights reserved.
//

#include "Deck.hpp"

using namespace std;

Deck::Deck()
{
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    for (int i = 0; i < 4; i++)
    {
        for (int num = 2; num <= 14; num++)
        {
            Card c(num, suits[i]);
            deck.push_back(c);
        }
    }
}
//--
int Deck::getSize()
{
    return deck.size();
}
//--
Card Deck::getCard(int pos)
{
    return deck[pos];
}

