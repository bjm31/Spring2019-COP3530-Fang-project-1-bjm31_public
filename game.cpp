#include <iostream>
#include <vector>
#include <string>

#include "question.h"
#include "game.h"

using namespace std;

int Game::AskQuestion() {
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
		cin >> guess;
		isDigit = qstn.AnswerContainsDigit(guess);
		
		if (isDigit) {
			correctGuesses.push_back(guess);
		}
		else if (!isDigit && numIncorrectGuesses != 3) {
			++numIncorrectGuesses;
			incorrectGuesses += "~";
			incorrectGuesses += guess;
			incorrectGuesses += "~";
		}

		string answers = qstn.GetAnswerWithPlaceholders(correctGuesses);
		cout << answers << "\t" << incorrectGuesses << endl;

		isCorrect = qstn.AllDigitsGuessed(answers);
		if (!isCorrect) cout << "Guess again: ";

	} while (numIncorrectGuesses < 3 && !isCorrect);

	AdjustPoints(isCorrect);

	return currentScore;
}
void Game::AdjustPoints(bool isGuessCorrect) {
	if (isGuessCorrect) {
		currentScore += amountWagered;
		cout << "Great job! You won " << GetWager() << " points!" << endl;
	}
	else {
		currentScore -= amountWagered;
		cout << "You lost " << GetWager() << " points!" << endl;
	}
}
void Game::SetWager(int wager) {
	if (wager < 0) wager = 1;
	else if (wager > currentScore) wager = currentScore;
	this->amountWagered = wager;
}
