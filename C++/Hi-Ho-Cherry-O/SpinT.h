#pragma once
#include "SpinT.h"
#include <string>

enum class SpinT {ONE, TWO, THREE, FOUR, DOG, BIRD, EMPTY, NONE};

const SpinT  FIRST_SPIN = SpinT::ONE;
const size_t SPIN_COUNT = static_cast<size_t>(SpinT::NONE);

std::string SpinTToString(SpinT s);
int ChangeScore(SpinT spin, int score);
SpinT RandomSpin(void);
void AddCherries(int & score, int scoreOver, int spinValue);
void SubtractCherries(int & score);