//
//  BlackJack.hpp
//  
//
//  Created by Jesus Mario Garza on 3/22/18.
//

#ifndef BlackJack_hpp
#define BlackJack_hpp

#include <stdio.h>
#include "HandBlackJack.hpp"
#include "Deck.hpp"

class BlackJack{
    
public:
    Deck deck;
    HandBlackJack player;
    HandBlackJack bank;
    string result;
    
    char askAction();
    void checkWinner();
    void newGame();
    void play();
    void twist(HandBlackJack*);
   
private:
    char currentAction;
    int scoreToWin;
};
#endif /* BlackJack_hpp */
