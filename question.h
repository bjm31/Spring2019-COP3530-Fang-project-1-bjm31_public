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
	Question(string text, string answer) { 
		this->answer = answer; 
		this->text = text; 
	}
	string GetText() { return text; }

	bool AnswerContainsDigit(char digit);
	string GetAnswerWithPlaceholders(vector<char> goodGuesses);
	bool AllDigitsGuessed(string answers);

private:
	string answer;
	string text;
};

#endif