
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Card.hpp"
#include "PokerEvaluator.hpp"

using namespace std;

PokerEvaluator::PokerEvaluator (vector<Card> hand)
{
    this->hand = hand;
}

string PokerEvaluator::evaluate()
{
    int highNum = -1, secHighNum = -1, thirdHighNum = -1;
    int numOfHearts = 0, numOfSpades = 0, numOfDiamonds = 0, numOfClubs = 0;
    
    for (int i = 0; i < this->hand.size(); i++)
    {
        if (this->hand[i].getSuit() == "Hearts")
        {
            numOfHearts += 1;
        }
        if (this->hand[i].getSuit() == "Spades")
        {
            numOfSpades += 1;
        }
        if (this->hand[i].getSuit() == "Diamonds")
        {
            numOfDiamonds += 1;
        }
        if (this->hand[i].getSuit() == "Clubs")
        {
            numOfClubs += 1;
        }
        if (this->hand[i].getNumericValue() > highNum)
        {
            thirdHighNum = secHighNum;
            secHighNum = highNum;
            highNum = this->hand[i].getNumericValue();
        }
        else if (this->hand[i].getNumericValue() > secHighNum)
        {
            thirdHighNum = secHighNum;
            secHighNum = this->hand[i].getNumericValue();
        }
        else if (this->hand[i].getNumericValue() > thirdHighNum)
        {
            thirdHighNum = this->hand[i].getNumericValue();
        }
    }
    
    int highSuitNum = -1;
    int tempNum;
    int straightCount = 1;
    if (numOfSpades > 4)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand[i].getSuit() == "Spades")
            {
                if (this->hand[i].getNumericValue() > highSuitNum)
                {
                    highSuitNum = this->hand[i].getNumericValue();
                    tempNum = highSuitNum;
                }
            }
        }
        for (int j = 0; j < this->hand.size(); j++)
        {
            for (int i = 0; i < this->hand.size(); i++)
            {
                if (this->hand[i].getSuit() == "Spades")
                {
                    if (this->hand[i].getNumericValue() == tempNum - 1)
                    {
                        tempNum = tempNum - 1;
                        straightCount = straightCount + 1;
                        if (straightCount >= 5)
                        {
                            if (highSuitNum == 13)
                            {
                                return "Royal Flush";
                            }
                            else
                            {
                                return "Straight Flush";
                            }
                        }
                        break;
                    }
                    
                    if (i == this->hand.size() - 1)
                    {
                        straightCount = 1;
                        tempNum = 0;
                        for (int k = 0; k < this->hand.size(); k++)
                        {
                            if (this->hand.at(k).getNumericValue() > tempNum && this->hand.at(k).getNumericValue() < highSuitNum)
                            {
                                tempNum = this->hand.at(k).getNumericValue();
                            }
                        }
                        highSuitNum = tempNum;
                    }
                }
            }
        }
    }
    else if (numOfClubs > 4)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand[i].getSuit() == "Clubs")
            {
                if (this->hand[i].getNumericValue() > highSuitNum)
                {
                    highSuitNum = this->hand[i].getNumericValue();
                    tempNum = highSuitNum;
                }
            }
        }
        for (int j = 0; j < this->hand.size(); j++)
        {
            for (int i = 0; i < this->hand.size(); i++)
            {
                if (this->hand[i].getSuit() == "Clubs")
                {
                    if (this->hand[i].getNumericValue() == tempNum - 1)
                    {
                        tempNum = tempNum - 1;
                        straightCount = straightCount + 1;
                        if (straightCount >= 5)
                        {
                            if (highSuitNum == 13)
                            {
                                return "Royal Flush";
                            }
                            else
                            {
                                return "Straight Flush";
                            }
                        }
                        break;
                    }
                    
                    if (i == this->hand.size() - 1)
                    {
                        straightCount = 1;
                        tempNum = 0;
                        for (int k = 0; k < this->hand.size(); k++)
                        {
                            if (this->hand.at(k).getNumericValue() > tempNum && this->hand.at(k).getNumericValue() < highSuitNum)
                            {
                                tempNum = this->hand.at(k).getNumericValue();
                            }
                        }
                        highSuitNum = tempNum;
                    }
                }
            }
        }
    }
    else if (numOfDiamonds > 4)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand[i].getSuit() == "Diamonds")
            {
                if (this->hand[i].getNumericValue() > highSuitNum)
                {
                    highSuitNum = this->hand[i].getNumericValue();
                    tempNum = highSuitNum;
                }
            }
        }
        for (int j = 0; j < this->hand.size(); j++)
        {
            for (int i = 0; i < this->hand.size(); i++)
            {
                if (this->hand[i].getSuit() == "Diamonds")
                {
                    if (this->hand[i].getNumericValue() == tempNum - 1)
                    {
                        tempNum = tempNum - 1;
                        straightCount = straightCount + 1;
                        if (straightCount >= 5)
                        {
                            if (highSuitNum == 13)
                            {
                                return "Royal Flush";
                            }
                            else
                            {
                                return "Straight Flush";
                            }
                        }
                        break;
                    }
                    
                    if (i == this->hand.size() - 1)
                    {
                        straightCount = 1;
                        tempNum = 0;
                        for (int k = 0; k < this->hand.size(); k++)
                        {
                            if (this->hand.at(k).getNumericValue() > tempNum && this->hand.at(k).getNumericValue() < highSuitNum)
                            {
                                tempNum = this->hand.at(k).getNumericValue();
                            }
                        }
                        highSuitNum = tempNum;
                    }
                }
            }
        }
    }
    else if (numOfHearts > 4)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand[i].getSuit() == "Hearts")
            {
                if (this->hand[i].getNumericValue() > highSuitNum)
                {
                    highSuitNum = this->hand[i].getNumericValue();
                    tempNum = highSuitNum;
                }
            }
        }
        for (int j = 0; j < this->hand.size(); j++)
        {
            for (int i = 0; i < this->hand.size(); i++)
            {
                if (this->hand[i].getSuit() == "Hearts")
                {
                    if (this->hand[i].getNumericValue() == tempNum - 1)
                    {
                        tempNum = tempNum - 1;
                        straightCount = straightCount + 1;
                        if (straightCount >= 5)
                        {
                            if (highSuitNum == 13)
                            {
                                return "Royal Flush";
                            }
                            else
                            {
                                return "Straight Flush";
                            }
                        }
                        break;
                    }
                    
                    if (i == this->hand.size() - 1)
                    {
                        straightCount = 1;
                        tempNum = 0;
                        for (int k = 0; k < this->hand.size(); k++)
                        {
                            if (this->hand.at(k).getNumericValue() > tempNum && this->hand.at(k).getNumericValue() < highSuitNum)
                            {
                                tempNum = this->hand.at(k).getNumericValue();
                            }
                        }
                        highSuitNum = tempNum;
                    }
                }
            }
        }
    }
    
    vector<int> kindCount = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int i = 0; i < this->hand.size(); i++)
    {
        kindCount[this->hand[i].getNumericValue() - 2]++;
    }
    for (int i = 0; i < 12; i++)
    {
        if (kindCount[i] >= 4)
        {
            return "Four of a Kind";
        }
    }
    
    for (int i = 0; i < 12; i++)
    {
        if (kindCount[i] == 3)
        {
            for (int j = 0; j < 12; j++)
            {
                if (kindCount[j] == 2)
                {
                    return "Full House";
                }
            }
        }
    }
    
    if (numOfSpades > 4 || numOfHearts > 4 || numOfDiamonds > 4 || numOfClubs > 4)
    {
        return "Flush";
    }
    
    highSuitNum = highNum;
    tempNum = highNum;
    straightCount = 1;
    for (int j = 0; j < this->hand.size(); j++)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand[i].getNumericValue() == tempNum - 1)
            {
                tempNum = tempNum - 1;
                straightCount = straightCount + 1;
                if (straightCount >= 5)
                {
                    return "Straight";
                }
                break;
            }
            
            if (i == this->hand.size() - 1)
            {
                straightCount = 1;
                tempNum = 0;
                for (int k = 0; k < this->hand.size(); k++)
                {
                    if (this->hand.at(k).getNumericValue() > tempNum && this->hand.at(k).getNumericValue() < highSuitNum)
                    {
                        tempNum = this->hand.at(k).getNumericValue();
                    }
                }
                highSuitNum = tempNum;
            }
        }
    }
    
    for(int i = 0;i<12;i++){
        if(kindCount[i]==3){
            return "Three of a Kind";
        }
    }
    
    for(int i = 0;i<12;i++){
        if(kindCount[i]==2){
            for(int j = 0;j<12;j++){
                if(j!=i && kindCount[j]==2){
                    return "Two Pair";
                }
            }
        }
    }
    
    for(int i = 0;i<12;i++){
        if(kindCount[i]==2){
            return "Pair";
        }
    }
    
    return "High Card";
}
