#pragma once
#include "SpinT.h"

enum class PlayerTypeT {HUMAN, COMPUTER, NONE};
const int MAX_SCORE{10}, NUMBER_OF_PLAYERS {4};

struct PlayerT {
    PlayerTypeT playerType;
    std::string pType;
    std::string name{"Alan Turing"};
    int age {66};//"The field of artificial intelligence research was founded as 
    int num;     //an academic discipline in 1956." - Google
    SpinT spin;
    int score{0};
    int round{0};
};

void PrintPlayers(const PlayerT & p);
void CreatePlayer(PlayerT & p, int i);
std::string MakeLower(std::string s);

std::string ScoreToString(int score);

std::string GoodVBad(int age);
std::string PlayerTypeTToString(PlayerTypeT t);
PlayerTypeT StringToPlayerTypeT(std::string t);