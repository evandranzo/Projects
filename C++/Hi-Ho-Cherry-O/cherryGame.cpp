/*	Program 2:  Hi Ho Cherry-O
	Programmer: Evan Dranzo
	Class:		CSCI230, Spring 2022
	Short Description:	A game where a human or computer play Hi-Ho-Cherro-O*/
#include <iostream>
#include "SpinT.h"
#include "PlayerT.h"
using namespace std;

void CreatePlayers(PlayerT p[]);
int CherryO(PlayerT p[]);
void TakeTurn(PlayerT & p);
void PrintScoreBoard(PlayerT p[]);
void IfWin(PlayerT p[], int & turn, bool & gameOver);
void PlayerWin (PlayerT & p);

int main(){
    PlayerT p[NUMBER_OF_PLAYERS];

    srand(static_cast<int>(time(nullptr)));
    CreatePlayers(p);
    return CherryO(p);//MAX_SCORE and NUMBER_OF_PLAYERS declared in PlayerT.h
}
void CreatePlayers(PlayerT p[]){
    int i;
    p[0].name = "Alphie"; p[1].name = "Bettie";
    p[2].name = "Deltie"; p[3].name = "Gammie";
    for (i = 1; i<=NUMBER_OF_PLAYERS; i++){
        CreatePlayer(p[i-1], i);
    }
    cout << "Players created, Press ENTER to Continue";
    cin.clear(); cin.ignore(100, '\n'); cin.ignore(100, '\n');
}
int CherryO(PlayerT p[]){
    int turn{0}; 
    string playAgain;
    bool gameOver{0};

    while (gameOver == 0) {
        TakeTurn(p[turn]);
        ++turn;
        IfWin(p, turn, gameOver);
        if (turn == NUMBER_OF_PLAYERS && not gameOver){//Check if player won
            PrintScoreBoard(p);
            cout << "Press ENTER to Continue:"; 
            cin.clear(); cin.ignore(200,'\n');
            turn %= NUMBER_OF_PLAYERS;
        }
    }
    return 0;
}
void TakeTurn(PlayerT & p){
    p.spin = RandomSpin();
    p.score = ChangeScore(p.spin, p.score);
    ++p.round;
    if (p.pType == "computer"){
        cout << endl << "Player " << p.num << " " << p.name << ", A "
             << PlayerTypeTToString(p.playerType) << " Player" << endl
             << SpinTToString(p.spin) << "You now have " << p.score
             << " cherries.";
    } else {
        cout << endl << p.name << ", it is your turn." << endl
             << "Press ENTER to Spin"; cin.ignore(); cout << endl
             << SpinTToString(p.spin) << "You now have " << p.score
             << " cherries.";
    }
    cout << endl;
}
void PrintScoreBoard(PlayerT p[]){
    cout << endl;
    int i;
    for (i = 1; i<=NUMBER_OF_PLAYERS; i++){
        PrintPlayers(p[i-1]);
    }
}
void IfWin(PlayerT p[], int & turn, bool & gameOver){
    string playAgain;
    if (p[turn-1].score == MAX_SCORE) {
        PlayerWin (p[turn-1]);
        gameOver = 1;
        PrintScoreBoard(p);//print final scoreboard
        cout << endl << "Thanks for playing Hi Ho Cherro-O!!" << endl
             << "Play again? (yes or no) "; 
             cin  >> playAgain; MakeLower(playAgain);
        if (playAgain == "yes") {
            CreatePlayers(p);
            gameOver = 0; turn = 0;
        } else {
            gameOver = 1;
            cout << endl << "Ok, have a good day!" << endl;
        }
    }
}
void PlayerWin (PlayerT & p){
    cout << "Hi Ho Cherro-O!, you win." << endl << endl
         << p.name << ", you won the game in "<< p.round << " rounds!" <<endl
         << "That is ";
    if (p.pType == "human"){
        cout << GoodVBad(p.age);
    } else {
        cout << "okay, but should have been much better\n";
    }
    cout << "for a " << p.pType <<" who is "<< p.age 
         << " years old!" << endl;
}