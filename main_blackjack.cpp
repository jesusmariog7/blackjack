//
//  main_blackjack.cpp
//  
//
//  Created by Jesus Mario Garza on 3/17/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include "src/game/BlackJack.hpp"

int main(){
    
    //Initialize game variables
    bool play = true;
    string logs = "";
    string logs_rounds = "";
    int round = 1;
    int rounds_won=0;
    int rounds_lost=0;
    int rounds_draw=0;
    
    //Save start time
    time_t start_time = time(0);
    tm *st = localtime(&start_time);
    char startTime [80];
    strftime (startTime,80,"Game start: %R %d-%b-%G\n",st);
    
    //Play game until "no" is selected
    do{
        BlackJack game;
        game.play();
        
        if(game.result.compare("won")==0)
            rounds_won++;
        else if(game.result.compare("lost")==0)
            rounds_lost++;
        else if(game.result.compare("draw")==0)
            rounds_draw++;
        
        logs_rounds += "Round " + to_string(round) + ": " + game.result + ".\n";
        
        //Play again
        cout << "\nDo you want to play again? [y]es/[n]o" << endl;
        char playAgain;
        cin >> playAgain;
        while(playAgain != 'y' and playAgain !='n' ){
            cout << "Please enter 'y' or 'n'. " << endl;
            cin >> playAgain;
        }
        if(playAgain=='y'){
            play=true;
            round++;
        }
        else
            play=false;
    }while (play);

    cout << "Thanks, bye!" << endl;
    
    //Save finish time
    time_t finish_time = time(0);
    tm *ft = localtime(&finish_time);
    char finishTime [80];
    strftime (finishTime,80,"Game finish: %R %d-%b-%G\n",ft);
    
    //Create logs
    logs += startTime;
    logs += finishTime;
    logs += "Rounds: " + to_string(round) + "\n" ;
    logs += "Won: " + to_string(rounds_won) + "\n" ;
    logs += "Lost: " + to_string(rounds_lost) + "\n" ;
    logs += "Draw: " + to_string(rounds_draw) + "\n" ;
    logs += "--\n";
    logs += logs_rounds;
    
    //Save logs into file
    char fileName [80];
    strftime (fileName,80,"%y%m%d_%H%M.txt",st);
    std::ofstream out(fileName);
    out << logs;
    out.close();

}
