#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>

#include "question.h"
#include "question_bank.h"

using namespace std;

class Game {
public:
	Game() { this->amountWagered = 0; this->currentScore = 0; }
	Game(QuestionBank* qs) {
		this->questions = qs;
		this->amountWagered = 0;
		this->currentScore = 200;
	}
	int AskQuestion();
	void AdjustPoints(bool isGuessCorrect);
	void SetWager(int wager) { 
		if (wager < 0) amountWagered = 0;
		this->amountWagered = wager;
	}
	int GetWager() { return amountWagered; }
	int GetCurrentScore() { return currentScore; }

private:
	QuestionBank* questions;
	int amountWagered;
	int currentScore;
};

#endif