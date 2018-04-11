//
//  Deck.cpp
//  
//
//  Created by Jesus Mario Garza on 3/17/18.
//

#include "Deck.hpp"
#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <ctime>

/**********************
 Deck()
 Constructor. Creates a Deck
 Input: -
 Output: -
 ***********************/

Deck::Deck(){
    
    cardsOnDeck = 0;
    string values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string valueNames[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    
    for (int i=0; i<13; i++){
        //Create a card of each suit
        Diamond diamond_card(valueNames[i], values[i]);
        Heart heart_card(valueNames[i], values[i]);
        Spade spade_card(valueNames[i], values[i]);
        Club club_card(valueNames[i], values[i]);
        
        //Add cards to the deck
        cards.push_back(diamond_card);  cardsOnDeck++;
        cards.push_back(heart_card);    cardsOnDeck++;
        cards.push_back(spade_card);    cardsOnDeck++;
        cards.push_back(club_card);     cardsOnDeck++;
    }
    shuffleDeck();
}

/**********************
 shuffleDeck()
 suffles the order of the cards in deck
 Input: -
 Output: -
 ***********************/

void Deck::shuffleDeck(){
    //srand(time(0));
    //int r = rand();
    //seed = std::chrono::system_clock::now().time_since_epoch().count();
    //int gen = default_random_engine(seed);
    random_shuffle(cards.begin(), cards.end());
}

/**********************
 Deck()
 Constructor. Creates a Deck
 Input: -
 Output: -
 ***********************/

int Deck::getAmountOfCardsInDeck(){
    return cardsOnDeck;
}

/**********************
 displayAvailableCards()
 Display all available cards from the deck
 Input: -
 Output: -
 ***********************/

void Deck::displayAvailableCards(){
    for (deque<Card>::iterator card_iterator=cards.begin(); card_iterator != cards.end(); ++card_iterator)
        cout << card_iterator->getSuit() << " " << card_iterator->getValue() << endl;
}

/**********************
 displayAvailableCards(n)
 Display n cards from the deck, if they are available
 Input: int
 Output: -
 ***********************/

void Deck::displayAvailableCards(int n){
    
    //Check if there are enough cards to display
    if (getAmountOfCardsInDeck()<n)
        n = getAmountOfCardsInDeck();
    
    int i=0;
    for (deque<Card>::iterator card_iterator=cards.begin(); i<n; ++card_iterator, i++){
        cout << card_iterator->getSuit() << " " << card_iterator->getValue() << endl;
    }
}

/**********************
 drawCard(n)
 gets one card from the deck
 Input: -
 Output: Card
 ***********************/

Card Deck::drawCard(){
    Card drawnCard = cards.back();
    cards.pop_back();
    cardsOnDeck--;
    return drawnCard;
}
