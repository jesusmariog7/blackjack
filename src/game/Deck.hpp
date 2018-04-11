//
//  Deck.hpp
//  
//
//  Created by Jesus Mario Garza on 3/17/18.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include <deque>

#include "../cards/Card.hpp"
#include "../cards/Heart.hpp"
#include "../cards/Diamond.hpp"
#include "../cards/Club.hpp"
#include "../cards/Spade.hpp"

class Deck{

public:
    Deck();
    Card drawCard();
    int getAmountOfCardsInDeck();
    void displayAvailableCards();
    void displayAvailableCards(int n);
    void shuffleDeck();
    
private:
    deque<Card> cards;
    int cardsOnDeck;
};


#endif /* Deck_hpp */
