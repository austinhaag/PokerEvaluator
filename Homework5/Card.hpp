

#ifndef Card_hpp
#define Card_hpp

#pragma once

//#include <stdio.h>
#include <string>

#endif /* Card_hpp */

using namespace std;

class Card
{
public:
    Card(int n, string s);
    
    string toString();
    
    int getNumericValue();
    void setNumericValue(int n);
    
    string getSuit();
    void setSuit(string s);
    
private:
    int cardNumber;
};
