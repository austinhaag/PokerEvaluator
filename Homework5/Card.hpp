//
//  Card.hpp
//  Homework5
//
//  Created by Austin Haag on 4/5/19.
//  Copyright © 2019 Austin Haag. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#pragma once

#include <stdio.h>
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
