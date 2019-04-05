//
//  Deck.hpp
//  Homework5
//
//  Created by Austin Haag on 4/5/19.
//  Copyright © 2019 Austin Haag. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

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
    
private:
    vector<Card> deck;
};
