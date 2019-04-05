//
//  main.cpp
//  Homework5
//
//  Created by Austin Haag on 4/5/19.
//  Copyright © 2019 Austin Haag. All rights reserved.
//

#include <iostream>
using namespace std;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include <vector>

int main(int argc, const char * argv[])
{
    cout << "Hello World!!!" << endl;
    
    Catch::Session().run();
    
    return 0;
}

TEST_CASE("Test Cards")
{
    SECTION("Test create bad cards")
    {
        Card c1(-10, "Hearts");
        Card c2(10, "Fish");
        Card c3(-10, "Fish");
        
        REQUIRE(c1.getNumericValue() == 2);
        REQUIRE(c1.getSuit() == "Hearts");
        REQUIRE(c2.getNumericValue() == 10);
        REQUIRE(c2.getSuit() == "Clubs");
        REQUIRE(c3.getNumericValue() == 2);
        REQUIRE(c3.getSuit() == "Clubs");
    }
    
    SECTION("Test create 52 cards")
    {
        string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
        for (int i = 0; i < 4; i++)
        {
            for (int num = 2; num <= 14; num++)
            {
                Card c(num, suits[i]);
                REQUIRE(c.getNumericValue() == num);
                REQUIRE(c.getSuit() == suits[i]);
            }
        }
    }
    
    SECTION("Test toString()")
    {
        Card c1(3, "Diamonds");
        Card c2(10, "Hearts");
        Card c3(14, "Spades");
        
        REQUIRE(c1.toString() == "3 of Diamonds");
        REQUIRE(c2.toString() == "10 of Hearts");
        REQUIRE(c3.toString() == "Ace of Spades");
    }
    
    SECTION("Test Unique 52 Card Deck")
    {
        Deck d1;
        
        REQUIRE(d1.getSize() == 52);
        
        vector <Card> cardsUsed;
        
        for(int i = 0; i < d1.getSize(); i++)
        {
            for(int j = 0; j <cardsUsed.size(); j++)
            {
                if((cardsUsed[j].getSuit() == d1.getCard(i).getSuit()) && (cardsUsed[j].getNumericValue() == d1.getCard(i).getNumericValue())){
                    REQUIRE(1 == 2);
                }
            }
            cardsUsed.push_back(d1.getCard(i));
        }
    }
}
