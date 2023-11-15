#include <iostream>
#include "SpinT.h"
#include "PlayerT.h"

std::string SpinTToString(SpinT s) {
    std::string value;
    switch(s) {
        case SpinT::ONE :
            value = "You picked 1 cherry.     ";break;
        case SpinT::TWO :
            value = "You picked 2 cherries.   ";break;
        case SpinT::THREE :
            value = "You picked 3 cherries.   ";break;
        case SpinT::FOUR :
            value = "You picked 4 cherries.   ";break;
        case SpinT::DOG :
            value = "A dog spilled 2 of your cherries.  ";break;
        case SpinT::BIRD :
            value = "A bird spilled 2 of your cherries. ";break;
        case SpinT::EMPTY :
            value = "You spilled your basket.   ";break;
        case SpinT::NONE:
        default:
            value = "Unknown"; 
    }
    return value;
}
SpinT RandomSpin(void) {
    int randomValue;
    SpinT value;

    randomValue = rand() % static_cast<int>(SPIN_COUNT);
    value = static_cast<SpinT>(randomValue);

    return value;
}
int ChangeScore(SpinT spin, int score) {
    int spinValue{0}, scoreOver{0};
    scoreOver = score;
    switch(spin) {
        case SpinT::ONE :
            spinValue = 1;
            AddCherries(score, scoreOver, spinValue); break;
        case SpinT::TWO :
            spinValue = 2;
            AddCherries(score, scoreOver, spinValue); break;
        case SpinT::THREE :
            spinValue = 3;
            AddCherries(score, scoreOver, spinValue); break;
        case SpinT::FOUR :
            spinValue = 4;
            AddCherries(score, scoreOver, spinValue); break;
        case SpinT::DOG :
        case SpinT::BIRD :
            SubtractCherries(score); break;
        case SpinT::EMPTY :
            score = 0;break;
        case SpinT::NONE:
        default:
            score = 0;
    }
    return score;
}
void AddCherries(int & score, int scoreOver, int spinValue){
    score = score + spinValue;
    if (score > MAX_SCORE){
        score = scoreOver;
    }
}
void SubtractCherries(int & score){
    score = score -2;
    if (score < 0){
        score = 0;
    }
}