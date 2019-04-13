
#ifndef Deck_hpp
#define Deck_hpp

#pragma once

#include <stdio.h>
#include "Card.hpp"
#include <vector>

#endif /* Deck_hpp */

using namespace std;

class Deck
{
public:
    Deck();
    int getSize();
    
    Card getCard(int pos);
    
    void shuffle();
    
	vector<Card> dealHand(int handSize);
    
    vector<Card> getDeck();
private:
    vector<Card> deck;
};
