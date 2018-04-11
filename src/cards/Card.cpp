//
//  Card.cpp
//  
//
//  Created by Jesus Mario Garza on 3/17/18.
//

#include "Card.hpp"
#include <iostream>

/********************
 Card() //Contructor
 ******************/

Card::Card(string _valueName, string _value, string _suit){
    valueName = _valueName;
    value = _value;
    suit = _suit;
}

/********************
 getValueName()
 returns the suit and value of the card
 Input: --
 Output: string
 ******************/

string Card::getValueName(){
    return valueName + " of " + suit;
}

/********************
 getValue()
 Returns the value of the vard
 Input: --
 Output: string
 ******************/

string Card::getValue(){
    return value;
}

/********************
 getSuit()
 returns the suit of the card
 Input: --
 Output: Card
 ******************/

string Card::getSuit(){
    return suit;
}
