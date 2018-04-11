//
//  BlackJack.cpp
//  
//
//  Created by Jesus Mario Garza on 3/22/18.
//

#include "BlackJack.hpp"
#include <iostream>

/********************
 newGame()
 initialize a new game
 Input: --
 Output: --
 ******************/
 
void BlackJack::newGame(){
    
    scoreToWin = 21;
    cout << "\nNew game! " << endl;
    
    cout << "\nYour hand is: " << endl;
    player.addCard(deck.drawCard());
    player.addCard(deck.drawCard());
    player.printHand();
    player.printHandValue();
    
    bank.addCard(deck.drawCard());
    bank.addCard(deck.drawCard());

}

/**********************
askAction()
ask for an action to the player (stick or twist)
Input:  --
Output: char
***********************/

char BlackJack::askAction(){
    
    cout << "\n[s]tick or [t]wist?" << endl;
    char enteredAction;
    cin >> enteredAction;
    
    while(enteredAction != 's' and enteredAction != 't' ) {
        cout << "Please enter 's' or 't' " << endl;
        cin >> enteredAction;
    }
    
    return enteredAction;
}

/*************************************************
 twist(HandBlackJack)
 Draws a new card for the selected player
 Input: HandBlackJack (player or bank)
 Output: --
 ************************************************/

void BlackJack::twist(HandBlackJack *hand){
   
    hand->addCard(deck.drawCard());
    
}

/*************************************************
 checkWinner()
 Checks the conditions to validate the result of the match
 Input: --
 Output: --
 ************************************************/
 
void BlackJack::checkWinner(){

    if(player.handValue == 21)
        result = "won";
    else if(player.handValue > 21)
        result = "lost";
    else if(bank.handValue > 21)
        result = "won";
    else if(player.handValue > bank.handValue and currentAction=='f' )
        result = "won";
    else if(player.handValue < bank.handValue and currentAction=='f')
        result = "lost";
    else if(player.handValue == bank.handValue and currentAction=='f'){
        if(player.getAmountOfCards() == bank.getAmountOfCards())
             result = "draw";
        else if (player.getAmountOfCards() > bank.getAmountOfCards())
             result = "won";
        else if (player.getAmountOfCards() > bank.getAmountOfCards())
            result = "lost";
    }
    
    if(result == "won")
        cout << "Well done, you won!!!" << endl;
    else if (result == "lost")
        cout << "Bad luck, the bank won." << endl;
    else if (result == "draw")
        cout << "Its a draw!" << endl;
}

/*************************************************
 play()
 Contains logic of the game. It lets the player draw the
 cards first, and then gives the turn to the bank. It
 also validates the winner.
 Input: --
 Output: --
 ************************************************/

void BlackJack::play(){
    bool play = true;
    newGame();
    
    // "Twist" until Stick or loose
    do{
        currentAction = askAction();
        if (currentAction == 't'){
            twist(&player);
            cout << "\nYour hand is: \n" << endl;
            player.printHand();
            player.printHandValue();
        }

         else
             break;
    }while(player.handValue < scoreToWin and player.getAmountOfCards() < 5);

    //Stick
    checkWinner();

    
    // if no winner, is bank's turn until win or loose.
    if(result==""){
        cout << "\nThe bank hand is: \n" << endl;
        bank.printHand();
        bank.printHandValue();
        do{
            twist(&bank);
            cout << "\nThe bank hand is: \n" << endl;
            bank.printHand();
            bank.printHandValue();
            
        }while(bank.handValue < scoreToWin and bank.getAmountOfCards() < 5 and bank.handValue < player.handValue);
        currentAction='f'; //finish game
        checkWinner();
    }

    
}
