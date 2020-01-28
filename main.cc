#include "cs240p7.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    TeamPQ tpq;
    string command;
    while(cin >> command){
        if (command == "i"){
            int wins;
            cin >> wins;
            int losses;
            cin >> losses;
            string name;
            cin >> name;

            Team added = Team(wins, losses, name, tpq.getSize());
            tpq.insert(added);
        }else if (command == "pw"){
            if (tpq.isEmpty()){
                continue;
            }
            Team temp = tpq.findMaxWins();
            cout << temp.getName() << endl;
        }else if (command == "pl"){
            if (tpq.isEmpty()){
                continue;
            }
            Team temp = tpq.findMinLosses();
            cout << temp.getName() << endl;
        }else if (command == "rw"){
            if (tpq.isEmpty()){
                continue;
            }
            tpq.removeMaxWins();
        }else if (command == "rl"){
            if (tpq.isEmpty()){
                continue;
            }
            tpq.removeMinLosses();
        }
    }

    
}