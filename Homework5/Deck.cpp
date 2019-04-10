//
//  Deck.cpp
//  Homework5
//
//  Created by Austin Haag on 4/5/19.
//  Copyright © 2019 Austin Haag. All rights reserved.
//

#include "Deck.hpp"
#include "stdlib.h"

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
    Shuffle();
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

void Deck::Shuffle()
{
    vector<Card> newDeck;
    for (int i = getSize(); i > 0; i--)
    {
        int pos = rand()%i;
        newDeck.push_back(deck.at(pos));
        deck.erase(deck.begin() + pos);
    }
    deck = newDeck;
}

vector<Card> Deck::dealHand(int handSize)
{
	vector<Card> retVal;
	if (getSize() >= handSize)
	{
		for (int i = 0; i < handSize; i++)
		{
			retVal.push_back(deck.at(0));
			deck.erase(deck.begin());
		}
	}
	else {
		exception e;
		throw e;
	}

	return retVal;
}

