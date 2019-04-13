
#pragma once
#include <iostream>
#include "Card.hpp"
#include <string>
#include <vector>

using namespace std;

class PokerEvaluator
{
public:
    PokerEvaluator(vector <Card> hand);
    string evaluate();
private:
    vector <Card> hand;
};
