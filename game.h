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
		this->currentScore = 0;
	}
	int AskQuestion() {
		Question qstn;
		int wager = 0;
		char guess;
		bool isDigit = false;
		vector<char> correctGuesses;
		string incorrectGuesses = "";
		int numIncorrectGuesses = 0;
		bool isCorrect = false;

		qstn = questions->GetNextQuestion();
		if (qstn.GetText() == "") return -1;

		cout << qstn.GetText() << endl;
		
		cout << "Points to wager? ";
		cin >> wager;
		
		SetWager(wager);
		
		cout << "Guess a digit: ";
		while (numIncorrectGuesses < 3) {
		
			cin >> guess;

			cout << "Guess #1: " << guess << endl;

			isDigit = qstn.AnswerContainsDigit(guess);

			cout << isDigit;

			if (isDigit) {
				correctGuesses.push_back(guess);
			}
			else if (!isDigit && numIncorrectGuesses != 3) {
				++numIncorrectGuesses;
				incorrectGuesses += "~" + to_string(guess) + "~";
				cout << "Guess again: ";
			}
			cout <<	qstn.GetAnswerWithPlaceholders(correctGuesses) << "\t";
			cout << incorrectGuesses << endl;
		}
		AdjustPoints(isCorrect);
		return currentScore;
	}
	void AdjustPoints(bool isGuessCorrect) {
		if (isGuessCorrect) {
			currentScore += amountWagered;
			cout << "Great job! You won " << GetWager() << " points!" << endl;
		}
		else {
			currentScore -= amountWagered;
			cout << "You lost " << GetCurrentScore() << " points!" << endl;
		}
	}
	void SetWager(int amountWagered) { this->amountWagered = amountWagered; };
	int GetWager() { return amountWagered; };
	int GetCurrentScore() { return currentScore; };

private:
	QuestionBank* questions;
	int amountWagered;
	int currentScore;
};

#endif