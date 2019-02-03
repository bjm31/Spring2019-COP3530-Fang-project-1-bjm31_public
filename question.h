#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Question {
public:
	Question() { 
		this->answer = "";
		this->text = ""; 
	}
	Question(string answer, string text) { 
		this->answer = answer; 
		this->text = text; 
	}
	string GetText() { return text; }

	bool AnswerContainsDigit(char digit) {
		int check = answer.find(digit);
		cout << "check: " << check << endl;
		if (check >= 0) return true;
		else return false;
	}
	string GetAnswerWithPlaceholders(vector<char> goodGuesses) { 
		string ph = "";
		for (int s = 0; s < answer.size(); ++s) ph += "_";

		for (int i = 0; i < answer.size(); ++i) {
			if (goodGuesses.empty())
				break;
			else {
				for (int j = 0; j < goodGuesses.size(); ++j) {
					if (answer.at(i) == goodGuesses.at(j))
						ph.at(i) = answer.at(i);
				}
			}
		}

		return ph;
	}
	bool AllDigitsGuessed(string answers) {
		if (answers.find("_") == -1) return true;
		else return false;
	}

private:
	string answer;
	string text;
};

#endif