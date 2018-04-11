//
//  HandBlackJack.cpp
//  
//
//  Created by Jesus Mario Garza on 3/22/18.
//

#include "HandBlackJack.hpp"
#include <iostream>

/******************
 HandBlackJack()
 a special hand for the Black Jack game
 CONSTRUCTOR
 ******************/

HandBlackJack::HandBlackJack(){
    handValue=0;
    cardValues["A"]=1;
    cardValues["2"]=2;
    cardValues["3"]=3;
    cardValues["4"]=4;
    cardValues["5"]=5;
    cardValues["6"]=6;
    cardValues["7"]=7;
    cardValues["8"]=8;
    cardValues["9"]=9;
    cardValues["10"]=10;
    cardValues["J"]=10;
    cardValues["Q"]=10;
    cardValues["K"]=10;
}

/******************
 printHand()
 Prints the cards in the hand
 Input : --
 Output: --
 ******************/

void HandBlackJack::printHand(){
    
    for (map<string,Card>::iterator card_iterator=cardsInHand.begin(); card_iterator != cardsInHand.end(); ++card_iterator){
        cout << card_iterator->second.getValueName();
        string value = card_iterator->second.getValue();
        cout << "\t(" << cardValues.find(value)->second << ")" << endl;
    }
}

/******************
 printHandValue()
 Prints the total value of the hand in a Black Jack game
 Input : --
 Output: --
 ******************/

void HandBlackJack::printHandValue(){
    if(handValue<=21)
        cout << "value= " << handValue << endl;
    else{
        cout << "value= " << handValue << endl;
        cout << "BUST!!!" << endl;
    }
}

/******************
 addCard()
 adds a card to the hand.
 Input : Card
 Output: --
 ******************/

void HandBlackJack::addCard(Card card){
    int cardValue = cardValues.find(card.getValue())->second;
    handValue += cardValue;
    Hand::addCard(card);
}
