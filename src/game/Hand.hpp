//
//  Hand.hpp
//  
//
//  Created by Jesus Mario Garza on 3/21/18.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include <map>
#include "../cards/Card.hpp"

class Hand {
    
public:
    Hand();
    void addCard(Card);
    void throwCard(Card);
    int getAmountOfCards();
 
protected:
    int amountOfCards;
    map<string, Card> cardsInHand;
};
#endif /* Hand_hpp */
