#include <iostream>
#include "PlayerT.h"
using namespace std;

void PrintPlayers(const PlayerT & p){
    cout << "\tPlayer " << p.num << ", " << p.name<< ",  (" << p.score 
         << ")   is a " << PlayerTypeTToString(p.playerType) << ". \t"
         << ScoreToString(p.score) << endl;
}
void CreatePlayer(PlayerT & p, int i){
    p.score = 0;
    p.round = 0;
    p.num = i;
    bool playerCreated {0}, humanCreated {0};
    
    while (playerCreated == 0) {
        cout << "Is player " << i << " a computer or human? "; 
        cin >> p.pType; p.pType = MakeLower(p.pType);
        
        if (p.pType == "computer"){
            playerCreated = 1;
        } else if (p.pType == "human"){
            cout << "What is player " << p.num << " name: ";
            cin.ignore(10,'\n');
            getline (cin, p.name);
            while (humanCreated == 0) {
                cout << "What is player " << p.num << " age: ";
                if (cin >> p.age) {
                    humanCreated = 1;
                    playerCreated = 1;
                } else {
                    cout << "Please enter numbers only," << endl;
                    cin.clear();  
                    cin.ignore(10,'\n');
                }
            }
        } else {
            cout << "Error, " << p.pType << " is not a type, try again" << endl;
        }
    }
    p.playerType = StringToPlayerTypeT(p.pType);
    cout << endl;
}
string MakeLower(string s) {
    size_t i;

    for(i = 0 ; i < s.size(); ++i) {
        s[i] = static_cast<char>(tolower(s[i]));
    }
    return s;
}
string ScoreToString(int score){
    string starO;
    int i {0};
    int j = MAX_SCORE-i;

    while (i < score){
        starO += "* ";
        i++;
    }
    while (i < j){
        starO += "0 ";
        i++;
    }
    return starO;
}

string PlayerTypeTToString(PlayerTypeT t){
    string value;
    switch(t) {
        case PlayerTypeT::COMPUTER :
            value = "computer"; break;
        case PlayerTypeT::HUMAN :
            value = "human"; break;
        case PlayerTypeT::NONE:
        default:
            value = "unknown";
    }
    return value;
}
PlayerTypeT StringToPlayerTypeT(string t){
    PlayerTypeT value{PlayerTypeT::NONE};
    t = MakeLower(t);
    if (t == "human"){
        value = PlayerTypeT::HUMAN;
    } else if (t == "computer") {
        value = PlayerTypeT::COMPUTER;
    }
    return value;
}
string GoodVBad(int age){
    string goodVBad;
    if (age <= 19){
        goodVBad = "very good ";
    } else if (age == 20){
        goodVBad = "brilliant, just brilliant ";
    } else if (age > 20 && age <= 66) {
        goodVBad = "good ";
    } else if (age > 66) {
        goodVBad = "wonderful ";
    }
    return goodVBad;
}