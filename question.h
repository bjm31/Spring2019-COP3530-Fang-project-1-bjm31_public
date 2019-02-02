#ifndef QUESTION_H
#define QUESTION_H

#include <string>

using namespace std;

class Question {
public:
	Question() { answer = 0; question = ""; }
	Question(int answer, string question) { this->answer = answer; this->question = question; }

private:
	int answer;
	string question;
};

#endif