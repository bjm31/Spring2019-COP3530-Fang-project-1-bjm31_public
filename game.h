#ifndef GAME_H
#define GAME_H

#include "question.h"
#include "question_bank.h"

using namespace std;

class Game {
public:
	Game() { this->amountWagered = 0; this->currentScore = 0; }
	Game(QuestionBank* qs) {
		this->questions = qs;
		this->amountWagered = 0;
		this->currentScore = 0;
	};
	int AskQuestion() {
		
		return GetCurrentScore();
	};
	void AdjustPoints(bool isGuessCorrect) {
		if (isGuessCorrect) currentScore += amountWagered;
	};
	void SetWager(int amountWagered) { this->amountWagered = amountWagered; };
	int GetWager() { return amountWagered; };
	int GetCurrentScore() { return currentScore; };

private:
	QuestionBank* questions;
	int amountWagered;
	int currentScore;
};

#endif