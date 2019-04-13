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
#include "PokerEvaluator.hpp"
#include <vector>

int main(int argc, const char * argv[])
{
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
}

TEST_CASE("Test Deck")
{
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
    SECTION("Test shuffle")
    {
        Deck tempDeck;
        Deck copyOfDeck = tempDeck;
        bool retVal = false;
		tempDeck.shuffle();
        for(int i =0; i< tempDeck.getSize(); i++)
        {
            if((tempDeck.getCard(i).getSuit() != copyOfDeck.getCard(i).getSuit()) || 
            (tempDeck.getCard(i).getNumericValue() != copyOfDeck.getCard(i).getNumericValue())){
                retVal = true;
                break;
            }
        }
        REQUIRE(retVal == true);
    }
	SECTION("Test Create Hand")
	{
		int handSize = 5;
		Deck d1;
		int originalSize = d1.getSize();
		vector<Card> hand = d1.dealHand(handSize);
		REQUIRE(d1.getSize() + handSize == originalSize);
	}
}

TEST_CASE("Test PokerEvaluator")
{
    SECTION("Test High Card"){
        vector<Card> highCard = {
            Card(2, "Spades"),
            Card(4, "Hearts"),
            Card(6, "Clubs"),
            Card(10, "Clubs"),
            Card(8, "Hearts"),
            Card(9, "Hearts"),
            Card(13, "Diamonds"),
        };
        PokerEvaluator pe = PokerEvaluator(highCard);
        REQUIRE(pe.evaluate() == "High Card");
    }
    SECTION("Test Pair")
    {
        vector<Card> pair = {
            Card(10, "Clubs"),
            Card(10, "Hearts"),
            Card(9, "Clubs"),
            Card(2, "Spades"),
            Card(5, "Diamonds"),
            Card(8, "Clubs"),
            Card(7, "Clubs")
        };
        PokerEvaluator pe = PokerEvaluator(pair);
        REQUIRE(pe.evaluate() == "Pair");
    }
    SECTION("Test Two Pair")
    {
        vector<Card> twoPair = {
            Card(10, "Clubs"),
            Card(10, "Hearts"),
            Card(9, "Clubs"),
            Card(9, "Spades"),
            Card(8, "Diamonds"),
            Card(8, "Clubs"),
            Card(7, "Clubs")
        };
        PokerEvaluator pe = PokerEvaluator(twoPair);
        REQUIRE(pe.evaluate() == "Two Pair");
    }
    SECTION("Test Three of a kind")
    {
        vector<Card> threeOfAKind = {
            Card(10, "Clubs"),
            Card(10, "Hearts"),
            Card(4, "Clubs"),
            Card(10, "Spades"),
            Card(9, "Diamonds"),
            Card(8, "Clubs"),
            Card(7, "Clubs")
        };
        PokerEvaluator pe = PokerEvaluator(threeOfAKind);
        REQUIRE(pe.evaluate() == "Three of a Kind");
    }
    SECTION("Test Straight"){
        vector<Card> straight = {
            Card(2, "Spades"),
            Card(9, "Hearts"),
            Card(6, "Clubs"),
            Card(4, "Clubs"),
            Card(5, "Hearts"),
            Card(3, "Hearts"),
            Card(2, "Diamonds"),
        };
        PokerEvaluator pe = PokerEvaluator(straight);
        REQUIRE(pe.evaluate() == "Straight");
    }
    SECTION("Test Flush"){
        vector<Card> flush = {
            Card(5, "Hearts"),
            Card(9, "Hearts"),
            Card(6, "Hearts"),
            Card(4, "Clubs"),
            Card(11, "Hearts"),
            Card(3, "Spades"),
            Card(2, "Hearts"),
        };
        PokerEvaluator pe = PokerEvaluator(flush);
        REQUIRE(pe.evaluate() == "Flush");
    }
    SECTION("Test Full House"){
        vector<Card> fullHouse = {
            Card(3, "Hearts"),
            Card(3, "Clubs"),
            Card(4, "Spades"),
            Card(4, "Clubs"),
            Card(11, "Hearts"),
            Card(4, "Hearts"),
            Card(2, "Hearts"),
        };
        PokerEvaluator pe = PokerEvaluator(fullHouse);
        REQUIRE(pe.evaluate() == "Full House");
    }
    SECTION("Test Four of a kind")
    {
        vector<Card> fourOfAKind = {
            Card(10, "Clubs"),
            Card(10, "Hearts"),
            Card(10, "Spades"),
            Card(10, "Diamonds"),
            Card(9, "Clubs"),
            Card(8, "Clubs"),
            Card(7, "Clubs")
        };
        PokerEvaluator pe = PokerEvaluator(fourOfAKind);
        REQUIRE(pe.evaluate() == "Four of a Kind");
    }
    SECTION("Test Straight Flush")
    {
        vector<Card> straightFlush = {
            Card(8, "Hearts"),
            Card(9, "Hearts"),
            Card(3, "Clubs"),
            Card(4, "Clubs"),
            Card(5, "Clubs"),
            Card(6, "Clubs"),
            Card(7, "Clubs")
        };
        PokerEvaluator pe = PokerEvaluator(straightFlush);
        REQUIRE(pe.evaluate() == "Straight Flush");
    }
    SECTION("Test Royal Flush"){
        vector<Card> royalFlush = {
            Card(9, "Spades"),
            Card(11, "Spades"),
            Card(13, "Spades"),
            Card(4, "Clubs"),
            Card(10, "Spades"),
            Card(12, "Spades"),
            Card(2, "Hearts"),
        };
        PokerEvaluator pe = PokerEvaluator(royalFlush);
        REQUIRE(pe.evaluate() == "Royal Flush");
    }
    
}
