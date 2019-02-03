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
		bool isDigit;
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
		do {
			string junk;
			cin >> guess;
			getline(cin, junk);
			isDigit = qstn.AnswerContainsDigit(guess);

			if (isDigit) {
				correctGuesses.push_back(guess);
				cout << "isDigit = true\n";
			}
			else if (!isDigit && numIncorrectGuesses != 3) {
				++numIncorrectGuesses;
				cout << "numIncorrectGuesses = " << numIncorrectGuesses << endl;
				incorrectGuesses += "~";
				incorrectGuesses += guess;
				incorrectGuesses += "~";
			}
			string answers = qstn.GetAnswerWithPlaceholders(correctGuesses);
			cout << answers	<< "\t";
			cout << incorrectGuesses << endl;
			isCorrect = qstn.AllDigitsGuessed(answers);
			if (!isCorrect) cout << "Guess again: ";
		} while (numIncorrectGuesses < 3 && !isCorrect);

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
			cout << "You lost " << GetWager() << " points!" << endl;
		}
	}
	void SetWager(int amountWagered) { this->amountWagered = amountWagered; }
	int GetWager() { return amountWagered; }
	int GetCurrentScore() { return currentScore; }

private:
	QuestionBank* questions;
	int amountWagered;
	int currentScore;
};

#endif