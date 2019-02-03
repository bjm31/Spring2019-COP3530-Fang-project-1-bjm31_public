#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

using namespace std;

class Question {
public:
	Question() { this->answer = ""; this->text = ""; }
	Question(string answer, string text) { this->answer = answer; this->text = text; }
	string GetText() { return text; }
	bool AnswerContiansDigit(char digit) {
		if (answer.find(digit) >= 0) return true;
		else return false;
	}
	string GetAnswerWithPlaceholders(vector<char>) {
		
		return "";
	}
	bool AllDigitsGuessed(string) {

		return false;
	}

private:
	string answer;
	string text;
};

#endif