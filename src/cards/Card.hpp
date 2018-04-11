//
//  Card.hpp
//  
//
//  Created by Jesus Mario Garza on 3/17/18.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Card {
  
    private:
        string valueName;
        string value;
        string suit;
    
    public:
        Card(string valueName, string value, string suit);
        string getValueName();
        string getValue();
        string getSuit();
    
};

#endif /* Card_hpp */
