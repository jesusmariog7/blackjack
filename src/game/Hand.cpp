//
//  Hand.cpp
//  
//
//  Created by Jesus Mario Garza on 3/21/18.
//

#include "Hand.hpp"
#include <iostream>

Hand::Hand(){
    amountOfCards=0;
}

void Hand::addCard(Card card){
    // Inserting card in hand
    cardsInHand.insert(make_pair(card.getValueName(), card));
    amountOfCards++;
}

void Hand::throwCard(Card card){
    // Remove card from hand
    cardsInHand.erase(card.getValueName());
    amountOfCards--;
}

int Hand::getAmountOfCards(){
    return amountOfCards;
}
