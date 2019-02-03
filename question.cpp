#include <iostream>
#include <string>
#include <vector>

#include "question.h"

using namespace std;

bool Question::AnswerContainsDigit(char digit) {
	int found = answer.find(digit);
	if (found >= 0) return true;
	else return false;
}

string Question::GetAnswerWithPlaceholders(vector<char> goodGuesses) {
	string ph = "";
	for (int s = 0; s < answer.size(); ++s) ph += "_";
	if (!goodGuesses.empty()) {
		for (int i = 0; i < answer.size(); ++i) {
			for (int j = 0; j < goodGuesses.size(); ++j) {
				if (answer.at(i) == goodGuesses.at(j)) ph.at(i) = answer.at(i);
			}
		}
	}
	
	return ph;
}

bool Question::AllDigitsGuessed(string answers) {
	if (answers.find("_") == -1) return true;
	else return false;
}