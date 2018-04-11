//
//  HandBlackJack.hpp
//  
//
//  Created by Jesus Mario Garza on 3/22/18.
//

#ifndef HandBlackJack_hpp
#define HandBlackJack_hpp

#include <stdio.h>
#include "Hand.hpp"

class HandBlackJack:public Hand{
    
    public:
        HandBlackJack();
        void addCard(Card);
        void printHand();
        void calculateValue();
        void printHandValue();
    
        int handValue;
        map<string, int> cardValues;
};

#endif /* HandBlackJack_hpp */
